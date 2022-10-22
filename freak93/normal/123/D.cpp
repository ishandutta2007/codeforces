#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class SuffixAutomaton {
  public:
    SuffixAutomaton(const string& S) {
        // damn that memory leak who cares
        root = lastNode = new Node(0);
        
        for (auto &c: S)
            extend(c);
    }

    long long answer() {
        for (Node *k = lastNode; k != 0; k = k -> link)
            k -> ends = 1;

        getAnswer(root);
        return root -> answer;
    }

  private:
    class Node {
      public:
        Node(const int &length_, Node * const link_ = 0, map<char, Node*> next_ = map<char, Node*>()):
            length(length_),
            ends(0),
            answer(0),
            solved(false),
            link(link_), 
            next(next_) {
        }

        int length, ends;
        long long answer;
        bool solved;
        Node *link;
        map<char, Node*> next;
    };

    void extend(char c) {
        Node* current = new Node(lastNode -> length + 1);
        
        Node *k;
        for (k = lastNode; k != 0 && k -> next.count(c) == 0; k = k -> link)
            k -> next[c] = current;

        lastNode = current;

        if (k == 0) {
            current -> link = root;
            return;
        }

        Node *p = k -> next[c];
        if (k -> length + 1 == p -> length) {
            current -> link = p;
            return;
        }

        Node *clone = new Node(k -> length + 1, p -> link, p -> next);
        p -> link = current -> link = clone;

        for (; k != 0 && k -> next[c] == p; k = k -> link)
            k -> next[c] = clone;
    }

    int getAnswer(Node *current) {
        if (current -> solved)
            return current -> ends;
        
        for (auto &it: current -> next) {
            current -> ends += getAnswer(it.second);
            current -> answer += it.second -> answer;
        }

        if (current != root)
            current -> answer += 1LL * (current -> ends) * (current -> ends + 1) / 2;
        current -> solved = true;
        return current -> ends;
    }


    Node *root, *lastNode;
};

int main() {
    string S; cin >> S;
    SuffixAutomaton A(S);

    cout << A.answer() << "\n";
}