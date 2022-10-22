#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class HalfDecayTree {
  public:
    HalfDecayTree(int);
    void add(int, int);
    double decay();

  private:
    int height;
    class Node {
      public:
        int electrons;
        Node *left, *right;
        Node(int _electrons, Node *_left = 0, Node *_right = 0):
            electrons(_electrons), left(_left), right(_right) {}
    } *root, *nil;

    void _add(Node* &, int, int, int); 
    double _decay(Node *);
};

HalfDecayTree::HalfDecayTree(int _height) {
    height = _height;
    nil = new Node(0);
    nil -> left = nil -> right = nil;
    root = new Node(0, nil, nil);
}

void HalfDecayTree::add(int vertex, int electrons) {
    _add(root, height, vertex, electrons);
}

double HalfDecayTree::decay() {
    double answer = 0;
    double multiply = 0.5;

    int best = 0;
    for (Node *node = root; node != nil; multiply *= 0.5) {
        int left = node -> left -> electrons;
        int right = node -> right -> electrons;
        int total = node -> electrons;
        //cerr << total << " " << left << " " << right << "\n";

        if (left > total / 2) {
            answer += multiply * max(best, total - right);
            best = max(best, total - left);
            node = node -> left;
        } else
            if (right > total / 2) {
                answer += multiply * max(best, total - left);
                best = max(best, total - right);
                node = node -> right;
            } else {
                answer += multiply * (max(best, total - left) + max(best, total - right));
                break;
            }

    }

    cerr << "\n";
    return answer;
    return _decay(root);
}

void HalfDecayTree::_add(Node* &node, int level, int vertex, int electrons) {
    while ((1 << level) > vertex)
        --level;

    //cerr << level << " " << vertex << " with " << electrons  << "\n";
    if (node == nil)
        node = new Node(0, nil, nil);
        
    node -> electrons += electrons;

    if (level == 0)
        return;

    if ((1 << (level - 1)) & vertex)
        _add(node -> right, level - 1, vertex, electrons);
    else
        _add(node -> left, level - 1, vertex, electrons);
}

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int H, Q; cin >> H >> Q;

    HalfDecayTree MyTree(H);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(8);

    for (int i = 0; i < Q; ++i) {
        string operation; cin >> operation;

        if (operation == "add") {
            int vertex, electrons; 
            cin >> vertex >> electrons;

            MyTree.add(vertex, electrons);
        } else {
            cout << MyTree.decay() << "\n";
        }
        //cerr << "---Done---\n";
    }
}