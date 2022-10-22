#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Automaton {
  public:
    Automaton() {
        nodes_.resize(1);
        root_ = last_node_ = new Node(0);
        nodes_[0].push_back(root_);
    }

    void build(const string& S) {
        nodes_.resize(max(nodes_.size(), S.size() + 1));

        for (auto &c : S)
            extend(c - 'a');
    }

    vector<int> buildSpecial(const string &S) {
        nodes_.resize(max(nodes_.size(), S.size() + 1));

        vector<int> answer(S.size());
        for (int i = 0; i < int(S.size()); ++i) {
            extend(S[i] - 'a');
            answer[i] = last_node_->link->length + 1;
        }

        return answer;
    }

    void mark(const int &lower_bound, const int &upper_bound) {
        lower_bound_ = lower_bound;
        upper_bound_ = upper_bound;

        for (Node* k = last_node_; k; k = k->link)
            k->endings = 1;

        for (int i = nodes_.size() - 1; i >= 0; --i)
            for (auto &now : nodes_[i])
                for (int j = 0; j < 26; ++j)
                    if (now->next[j])
                        now->endings += now->next[j]->endings;

        // now we mark with lower bound and upper_bound
        root_->lower_bound = 1;
        for (int i = 1; i < int(nodes_.size()); ++i) // the 0 length string has 0 lower_bound and upper_bound
            for (auto &now : nodes_[i]) {
                if (now->endings >= lower_bound)
                    now->upper_bound = now->length; // we can be this long because we appear often enough
                else
                    now->upper_bound = now->link->upper_bound;  // we use our link information

                if (now->endings > upper_bound) // we appear too often
                    now->lower_bound = now->length + 1;         // at least this distance
                else
                    now->lower_bound = now->link->lower_bound;  // our link information
            }
    }

    pair< vector<int>, vector<int> > match(const string &S) {
        vector<int> lower_bound(S.size()), upper_bound(S.size());

        Node *k = root_;
        int length = 0;
        for (int i = 0; i < int(S.size()); ++i) {
            int edge = S[i] - 'a';
            while (k != root_ and not k->next[edge]) {
                k = k->link;
                length = k->length;
            }

            if (k->next[edge]) {
                k = k->next[edge];
                ++length;
            }

            lower_bound[i] = k->lower_bound;
            upper_bound[i] = min(k->upper_bound, length);

            if (lower_bound_ == 0)
                upper_bound[i] = i + 1;
        }

        return {lower_bound, upper_bound};
    }

  private:
    class Node {
      public:
        Node(const int &_length, Node * const _link = 0, Node **_next = 0):
                length(_length),
                link(_link),
                endings(0),
                lower_bound(0),
                upper_bound(0) {
            if (_next == 0)
                memset(next, 0, sizeof(next));
            else
                memcpy(next, _next, sizeof(next));
        }

        int length;
        Node *link, *next[26];
        int endings;
        int lower_bound, upper_bound;
    };

    void extend(const int &edge) {
        Node* now = new Node(last_node_->length + 1);
        nodes_[now->length].push_back(now);

        Node *k;
        for (k = last_node_; k and not k->next[edge]; k = k->link)
            k->next[edge] = now;

        last_node_ = now;

        if (k == 0) {
            now->link = root_;
            return;
        }

        Node *p = k->next[edge];
        if (k->length + 1 == p->length) {
            now->link = p;
            return;
        }

        Node *clone = new Node(k->length + 1, p->link, p->next);
        nodes_[clone->length].push_back(clone);
        now->link = p->link = clone;

        for (; k and k->next[edge] == p; k = k->link)
            k->next[edge] = clone;
    }

    Node *root_, *last_node_;
    vector< vector<Node*> > nodes_;

    int lower_bound_, upper_bound_;
};

int main() {
    string S; cin >> S;

    int N; cin >> N;
    vector<Automaton> A(N);

    for (int i = 0; i < N; ++i) {
        string current; cin >> current;
        A[i].build(current);

        int lower_bound, upper_bound;
        cin >> lower_bound >> upper_bound;
        A[i].mark(lower_bound, upper_bound);
    }

    vector<int> lower_bound(S.size(), 1), upper_bound(S.size());
    for (int i = 0; i < int(S.size()); ++i)
        upper_bound[i] = i + 1;

    for (int i = 0; i < N; ++i) {
        vector<int> now_lower, now_upper;
        tie(now_lower, now_upper) = A[i].match(S);

        for (int j = 0; j < int(S.size()); ++j) {
            lower_bound[j] = max(lower_bound[j], now_lower[j]);
            upper_bound[j] = min(upper_bound[j], now_upper[j]);
        }
    }

    Automaton F;
    auto now_lower = F.buildSpecial(S);
    int answer = 0;
    for (int j = 0; j < int(S.size()); ++j) {
        lower_bound[j] = max(lower_bound[j], now_lower[j]);
        if (lower_bound[j] <= upper_bound[j])
            answer += upper_bound[j] - lower_bound[j] + 1;
    }

    cout << answer << "\n";
}