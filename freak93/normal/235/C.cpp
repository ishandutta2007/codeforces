#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class SuffixAutomaton {
  public:
    SuffixAutomaton(const string& S) {
        root = lastNode = new Node(0);

        for (auto &c: S)
            extend(c - 'a');

        for (Node* k = lastNode; k != 0; k = k -> link)
            k -> count = 1;

        getAnswer(root);
    }

    int countCyclic(const string& S) {
        int period = this->period(S);

        int length = 0;
        Node* k = root;
        for (auto &c: S) {
            while (k != root && k -> next[c - 'a'] == 0) {
                k = k -> link;
                length = k -> length;
            }

            if (k -> next[c - 'a']) {
                ++length;
                k = k -> next[c - 'a'];
            }
        }

        int N = S.size();
        int answer = 0;
        if (length == N)
            answer = k -> count;
        
        for (int i = 0; i < period - 1; ++i) {
            if (length == N) {
                if (--length <= k -> link -> length)
                    k = k -> link;
            }

            while (k != root && k -> next[S[i] - 'a'] == 0) {
                k = k -> link;
                length = k -> length;
            }

            if (k -> next[S[i] - 'a']) {
                ++length;
                k = k -> next[S[i] - 'a'];
            }

            if (length == N)
                answer += k -> count;
        }

        return answer;
    }

  private:
    class Node {
      public:
        Node(const int &length_, Node* const link_ = 0, Node** next_ = 0):
            length(length_),
            count(0),
            solved(false),
            link(link_) {
                if (next_ == 0) {
                    for (int i = 0; i < 26; ++i)
                        next[i] = 0;
                    return;
                }

                for (int i = 0; i < 26; ++i)
                    next[i] = next_[i];
            }

        int length;
        int count;
        bool solved;
        Node *link;
        Node* next[26];
    };

    int period(string A) {
        int N = A.size();
        A = " " + A;
        vector<int> pi(A.size());
        pi[1] = 0;
        int k = 0;
        for (int i = 2; i < int(A.size()); ++i) {
            while (k && A[i] != A[k + 1])
                k = pi[k];
            if (A[i] == A[k + 1])
                ++k;
            pi[i] = k;
        }

        if (N % (N - pi[N]) == 0)
            return N - pi[N];
        return N;
    }

    void extend(int value) {
        Node* current = new Node(lastNode -> length + 1);
        
        Node* k;
        for (k = lastNode; k != 0 && k -> next[value] == 0; k = k -> link)
            k -> next[value] = current;

        lastNode = current;

        if (k == 0) {
            current -> link = root;
            return;
        }

        Node* p = k -> next[value];
        if (k -> length + 1 == p -> length) {
            current -> link = p;
            return;
        }

        Node* clone = new Node(k -> length + 1, p -> link, p -> next);
        p -> link = current -> link = clone;

        for (; k != 0 && k -> next[value] == p; k = k -> link)
            k -> next[value] = clone;
    }

    int getAnswer(Node *k) {
        if (k -> solved)
            return k -> count;
        for (int i = 0; i < 26; ++i)
            if (k -> next[i])
                k -> count += getAnswer(k -> next[i]);
        k -> solved = true;
        return k -> count;
    }

    Node *root, *lastNode;
};

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    string S; cin >> S;
    SuffixAutomaton G(S);

    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        string X; cin >> X;
        cout << G.countCyclic(X) << "\n";
    }
}