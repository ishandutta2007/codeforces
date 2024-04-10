#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

static const int kModulo = 1000 * 1000 * 1000 + 7;

struct Barrier {
    int u, l, r, s;
    bool operator<(const Barrier& that) const {
        return u < that.u;
    }
};

class SegmentTree {
  public:
    SegmentTree(int size):
        m_size(size),
        m_data(size * 4) {}

    void insert(int from, int to, int value) {
        insert_or_erase(1, 0, m_size, from, to + 1, value, true);
    }

    void erase(int from, int to, int value) {
        insert_or_erase(1, 0, m_size, from, to + 1, value, false);
    }

    int query(int position) {
        return query(1, 0, m_size, position);
    }

  private:
    void insert_or_erase(int node, int begin, int end, int from, int to, int value, bool insert) {
        if (from <= begin && end <= to) {
            if (insert)
                m_data[node].emplace(value);
            else
                m_data[node].erase(value);
            return;
        }

        int mid = (begin + end) / 2;
        if (from < mid)
            insert_or_erase(node * 2, begin, mid, from, to, value, insert);
        if (mid < to)
            insert_or_erase(node * 2 + 1, mid, end, from, to, value, insert);
    }

    int query(int node, int begin, int end, int position) {
        int answer = -1;
        if (m_data[node].size())
            answer = max(answer, *m_data[node].rbegin());
        if (end - begin == 1)
            return answer;

        int mid = (begin + end) / 2;
        if (position < mid)
            return max(answer, query(node * 2, begin, mid, position));
        else
            return max(answer, query(node * 2 + 1, mid, end, position));
    }

    int m_size;
    vector<set<int>> m_data;
};

int main() {
    ios::sync_with_stdio(false);
    int H, W, N; cin >> H >> W >> N;

    vector<Barrier> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i].u >> B[i].l >> B[i].r >> B[i].s;
        --B[i].l;
        --B[i].r;
    }

    sort(B.begin(), B.end());
    set< pair<int, int> > del;
    SegmentTree S(W);
    vector<int> multiply(N, 0);
    for (int i = 0; i < N; ++i) {
        auto &b = B[i];
        while (del.size()) {
            int x, y;
            tie(x, y) = *del.begin();
            if (x > b.u)
                break;
            del.erase(del.begin());
            S.erase(B[y].l, B[y].r, y);
        }

        int left = b.l - 1;
        int right = b.r + 1;
        if (left < 0)
            left = right;
        if (right >= W)
            right = left;

        int hit_left = S.query(left);
        int hit_right = S.query(right);

        if (hit_left == -1)
            multiply[i] = 1;
        else
            multiply[i] = multiply[hit_left];

        if (hit_right == -1)
            multiply[i] = (multiply[i] + 1) % kModulo;
        else
            multiply[i] = (multiply[i] + multiply[hit_right]) % kModulo;

        // add us
        S.insert(b.l, b.r, i);
        del.emplace(b.u + b.s + 1, i);
    }

    while (del.size()) {
        int x, y;
        tie(x, y) = *del.begin();
        if (x > H + 1)
            break;
        del.erase(del.begin());
        S.erase(B[y].l, B[y].r, y);
    }
    int answer = 0;
    for (int i = 0; i < W; ++i) {
        int hit = S.query(i);
        if (hit == -1)
            answer = (answer + 1) % kModulo;
        else
            answer = (answer + multiply[hit]) % kModulo;
    }
    cout << answer << "\n";
}