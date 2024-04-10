#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class SegmentTree {
  public:
    SegmentTree(int size):
        size_(size),
        count_(size * 4, 0),
        intervals_(size * 4) {
    }

    int size() const {
        return size_;
    }

    void addInterval(int x, int y) {
        add(1, 0, size_ - 1, x, y);
    }

    void prepare() {
        prepare(1, 0, size_ - 1);
    }

    int query(int x, int y) {
        return query(1, 0, size_ - 1, x, y);
    }

  private:
    void add(int node, int from, int to, int x, int y) {
        int mid = (from + to) / 2;
        count_[node]++;
        if (x <= mid && mid < y) {
            intervals_[node].push_back({x, y});
            return;
        }

        if (y <= mid)
            add(node * 2, from, mid, x, y);
        else
            add(node * 2 + 1, mid + 1, to, x, y);
    }

    void prepare(int node, int from, int to) {
        if (from == to)
            return;
        sort(intervals_[node].begin(), intervals_[node].end(), greater<pair<int, int> >());

        int mid = (from + to) / 2;
        prepare(node * 2, from, mid);
        prepare(node * 2 + 1, mid + 1, to);
    }

    int query(int node, int from, int to, int x, int y) {
        if (x <= from && to <= y)
            return count_[node];

        int mid = (from + to) / 2;
        int answer = upper_bound(intervals_[node].begin(), intervals_[node].end(), make_pair(x, y), [&](pair<int, int> , pair<int, int>seq) {
            return !(seq.first >= x && seq.second <= y);
        }) - intervals_[node].begin();

        if (x <= mid)
            answer += query(node * 2, from, mid, x, y);
        if (mid < y)
            answer += query(node * 2 + 1, mid + 1, to, x, y);
        return answer;
    }

    int size_;

    vector<int> count_;
    vector< vector<pair<int, int> > > intervals_;
};

int main() {
    ios::sync_with_stdio(false);
    string S; cin >> S;

    SegmentTree T(S.size());

    stack<int> st;
    for (int i = 0; i < int(S.size()); ++i)
        if (S[i] == '(')
            st.push(i);
        else
            if (st.size()) {
                T.addInterval(st.top(), i);
                st.pop();
            }

    T.prepare();
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;
        cout << T.query(x, y) * 2 << "\n";
    }
}