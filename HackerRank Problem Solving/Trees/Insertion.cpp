#include <iostream>
#include <cstddef>
	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  
    void preOrder(Node *root) {

          if( root == NULL )
              return;

          std::cout << root->data << " ";

          preOrder(root->left);
          preOrder(root->right);
      }
    Node * insert(Node * root, int data) {
        if(root==NULL) {
            return new Node(data);
        }
        Node* cur=root;
        while(true){
            if(cur->data<data){
                if(cur->right!=NULL) cur=cur->right;
                else{
                    cur->right=new Node(data);
                    break;
                }
            }
            else{
                if(cur->left!=NULL) cur=cur->left;
                else{
                    cur->left=new Node(data);
                    break;
                }
            }
        }
        return root;
    }

}; 

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
	myTree.preOrder(root);
    return 0;
}