/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode* minNode(TreeNode* root) {
        TreeNode* p = root;
        while (p != nullptr && p->left != nullptr) {
            p = p->left;
        }
        return p;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            if (root->left == NULL) {
                TreeNode* p = root->right;
                delete root;
                return p;
            } else if (root->right == NULL) {
                TreeNode* p = root->left;
                delete root;
                return p;
            } else {
                TreeNode* p = minNode(root->right);
                root->val = p->val;
                root->right = deleteNode(root->right, p->val);
            }
        }
        return root;
    }
};