#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class SuffixAutomaton {
  public:
    SuffixAutomaton(const string &S) {
        root = lastNode = new Node(0);

        Nodes.resize(S.size() + 1);
        for (auto &c: S)
            extend(c);
    }

    int beginEnd(const string &begin, const string &end) {
        // let's fix those position which have a good ending
        Node *k = root;

        for (auto &c: end) {
            if (k -> next.count(c)) {
                k = k -> next[c];
            } else
                return 0;
        }

        k -> ends = 1;

        // now iterate over begin
        Node *start = root;

        for (auto &c: begin) {
            if (start -> next.count(c) == 0)
                return 0;
            start = start -> next[c];
        }

        for (int i = 1; i < int(Nodes.size()); ++i)
            for (auto &p: Nodes[i])
                p -> ends += p -> link -> ends;

        for (int i = Nodes.size() - 1; i >= 0; --i)
            for (auto &p: Nodes[i])
                for (auto &it: p -> next)
                    p -> ends += it.second -> ends;

        int answer = start -> ends;

        // let's delete those bad substrings
        k = root;
        int now = 0;
        int length = 0;

        for (auto &c: end) {
            while (k != root && k -> next.count(c) == 0) {
                k = k -> link;
                length = k -> length;
            }
            
            if (k -> next.count(c)) {
                k = k -> next[c];
                ++length;
            }
            ++now;

            if (length == int(begin.size())) {
                if (now == length && k == start)
                    return answer;

                if (k == start)
                    answer -= k -> ends;
                
                if (--length <= k -> link -> length)
                    k = k -> link;
 
            }
       }

        return answer;
    }

  private:
    class Node {
      public:
        Node(const int &length_, Node * const link_ = 0, map<char, Node*> next_ = map<char, Node*>()):
            length(length_),
            ends(0),
            link(link_),
            next(next_) {
        }

        int length;
        int ends;
        bool cloned;
        Node* link; 
        map<char, Node*> next;
    };
   
    void extend(char c) {
        Node* current = new Node(lastNode -> length + 1);
        Nodes[lastNode -> length + 1].push_back(current);

        Node* k;
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
        Nodes[clone -> length].push_back(clone);

        p -> link = current -> link = clone;
        for (; k != 0 && k -> next[c] == p; k = k -> link)
            k -> next[c] = clone;
    }

    Node *root, *lastNode;
    vector< vector<Node* > > Nodes;
};

int main() {
    string S; cin >> S;
    SuffixAutomaton A(S);

    string begin, end;
    cin >> begin >> end;

    cout << A.beginEnd(begin, end) << "\n";
}