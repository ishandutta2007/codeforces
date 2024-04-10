#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

class SuffixAutomaton {
  public:
    SuffixAutomaton(const string& S) {
        root = lastNode = new Node(0, 0);
        
        for (auto &c: S)
            extend(c);
    }

    vector<int> match(const string &S) {
        Node *k = root;
        int length = 0;

        vector<int> answer(S.size(), numeric_limits<int>::max() / 2);
        int steps = 0;
        for (auto &c: S) {
            while (k != root && k -> next.count(c) == 0) {
                k = k -> link;
                length = k -> length;
            }

            if (k -> next.count(c)) {
                k = k -> next[c];
                ++length;
            }

            if (length == ++steps)
                answer[steps - 1] = k -> firstPos;
        }

        return answer;
    }

  private:
    void extend(char c) {
        Node* current = new Node(lastNode -> length + 1, lastNode -> length + 1);
        
        Node *k;
        for (k = lastNode; k && k -> next.count(c) == 0; k = k -> link)
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

        Node *clone = new Node(k -> length + 1, p -> firstPos, p -> link, p -> next);
        current -> link = p -> link = clone;

        for (; k && k -> next[c] == p; k = k -> link)
            k -> next[c] = clone;
    }

    class Node {
      public:
        Node(const int &length_, const int& firstPos_, Node * const link_ = 0, const map<char, Node*>& next_ = map<char, Node*>()):
            length(length_),
            firstPos(firstPos_),
            link(link_),
            next(next_) {
        }

        int length, firstPos;
        Node* link;
        map<char, Node*> next;
    };

    Node* root, *lastNode;
};

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    string S; cin >> S;
   
    string S2 = S;
    reverse(S2.begin(), S2.end());
    
    SuffixAutomaton L(S), R(S2);

    int N; cin >> N;
    int answer = 0;
    for (int i = 0; i < N; ++i) {
        string X; cin >> X;

        vector<int> prefix = L.match(X);

        reverse(X.begin(), X.end());
        vector<int> suffix = R.match(X);

        for (int i = 1; i < int(X.size()); ++i)
            if (prefix[i - 1] + suffix[X.size() - i - 1] <= int(S.size())) {
                ++answer;
                break;
            }
    }

    cout << answer << "\n";
}