#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

const int kUpperBound = 1000 * 1000;

class SuffixAutomaton {
  public:
    SuffixAutomaton(const string& S) {
        root = lastNode = new Node(0);
        
        for (auto &c: S)
            extend(c);
       
        for (Node *k = lastNode; k != 0; k = k -> link)
            k -> ends = 1;

        getCount(root);

        getAnswer(root);
    }

    string kthSubstring(int K) {
        Node *k = root;
        string answer;
        do {
            if (k != root) {
                if (K <= k -> ends)
                    return answer;
                K -= k -> ends;
            }

            for (auto &it: k -> next)
                if (it.second -> count < K)
                    K -= it.second -> count;
                else {
                    answer += it.first;
                    k = it.second;
                    break;
                }
        } while (1);
    }

  private:
     class Node {
      public:
        Node(const int &length_ = 0, Node * const link_ = 0, map<char, Node *> next_ = map<char, Node *>()):
            length(length_),
            ends(0),
            count(0),
            solved(false),
            link(link_),
            next(next_) {
        }

        int length, ends, count;
        bool solved;
        Node* link;
        map<char, Node*> next;
    };

    int getCount(Node *current) {
        if (current -> solved == true)
            return current -> ends;

        for (auto &it: current -> next)
            current -> ends += getCount(it.second);
        
        current -> solved = true;
        return current -> ends;
    }

    int getAnswer(Node* current) {
        if (current -> solved == false)
            return current -> count;

        current -> count = current -> ends;
        for (auto &it: current -> next) {
            current -> count += getAnswer(it.second);
            if (current -> count > kUpperBound)
                current -> count = kUpperBound;
        }

        current -> solved = false;
        return current -> count;
    }


    void extend(char c) {
        Node *current = new Node(lastNode -> length + 1);

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

    Node *root, *lastNode;
};

int main() {
//    ifstream cin("input.txt");
 //   ofstream cout("output.txt");

    string S; cin >> S;
    int K; cin >> K;

    if (1ULL * S.size() * (S.size() + 1) / 2 < 1ULL * K) {
        cout << "No such line.\n";
        return 0;
    }

    SuffixAutomaton A(S);
    cout << A.kthSubstring(K) << "\n";
}