#ifndef BSTREE_H
#define BSTREE_H

using namespace std;

template <typename T>
class BSTree {    
    private:
        struct NodeBT {
            T data;
            NodeBT* left; 
            NodeBT* right;              
            NodeBT() : left(nullptr), right(nullptr) {}   
            NodeBT(T value) : data(value), left(nullptr), right(nullptr) {} 
        };

        NodeBT* root;    

    public:
        BSTree(): root(nullptr) {}
       
		void insert(T value){
            insert(this->root, value);            
        }
	
        void displayInOrder(){
            displayInOrder(this->root);
        }

        void displayPreOrder();
        void displayPostOrder();
        void displayPretty();
              
    private:
        void insert(NodeBT* &node, T value){
            if(node == nullptr)
                node = new NodeBT(value);
            else if(value < node->data)
                insert(node->left, value);
            else 
                insert(node->right, value);            
        }

        void displayInOrder(NodeBT* &node){
            if(node == nullptr) return;
            displayInOrder(node->left);
            cout<<node->data<<",";
            displayInOrder(node->right);
        }

        void displayInorder_iterative(){
            Stack<NodeBT<T>*> stack;
            NodeBT<T>* current = this->root;
            while(current != nullptr || !stack.empty()){
                while(current != nullptr){
                    stack.push(current);
                    current = current->left;
                }                
                current = stack.pop();                
                cout<<current->data<<",";  
                current = current->right;
            }
        }     
}; 


#endif


