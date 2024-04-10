#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class SegmentTree {
  public:
    SegmentTree(int size): m_size(size), m_data(size * 4) {}

    void update(int from, int to, int bound, int value) {
        update(1, 0, m_size, from, to, bound, value);
    }

    int query(int position) {
        return query(1, 0, m_size, position);
    }

  private:
    struct Node {
        int max1 = -1;
        int max2 = -2;
        int from = -1;
        int to = -1;
    };

    void propagate(int node, int begin, int end) {
        propagating = true;
        int mid = (begin + end) / 2;
        if (m_data[node].from != -1) {
            update(node * 2, begin, mid, begin, mid, m_data[node].from, m_data[node].to);
            update(node * 2 + 1, mid, end, mid, end, m_data[node].from, m_data[node].to);
            m_data[node].from = m_data[node].to = -1;
        }
        propagating = false;
    }

    void compute(int node) {
        m_data[node].max1 = m_data[node * 2].max1;
        m_data[node].max2 = m_data[node * 2].max2;
        auto check = [&](int x) {
            if (x > m_data[node].max1) {
                m_data[node].max2 = m_data[node].max1;
                m_data[node].max1 = x;
            } else if (x > m_data[node].max2 && x < m_data[node].max1) {
                m_data[node].max2 = x;
            }
        };
        check(m_data[node * 2 + 1].max1);
        check(m_data[node * 2 + 1].max2);
    }

    void update(int node, int begin, int end, int from, int to, int bound, int value) {
        if (to <= begin || end <= from || m_data[node].max1 < bound)
            return;

        if (from <= begin && end <= to && m_data[node].max2 < bound) {
            m_data[node].max1 = value;
            if (m_data[node].from == -1)
                m_data[node].from = bound;
            m_data[node].to = value;
            return;
        }
        assert(not propagating);

        int mid = (begin + end) / 2;
        propagate(node, begin, end);
        if (from < mid)
            update(node * 2, begin, mid, from, to, bound, value);
        if (mid < to)
            update(node * 2 + 1, mid, end, from, to, bound, value);

        compute(node);
    }

    int query(int node, int begin, int end, int position) {
        if (end - begin == 1)
            return m_data[node].max1;

        propagate(node, begin, end);
        int mid = (begin + end) / 2;
        if (position < mid)
            return query(node * 2, begin, mid, position);
        else 
            return query(node * 2 + 1, mid, end, position);
    }

    int m_size;
    vector<Node> m_data;
    bool propagating = false;
};

int main() {
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;

    vector<int> from(N, -1);
    for (int i = 0; i < M; ++i) {
        int l, r; cin >> l >> r;
        from[r - 1] = l - 1;
    }

    int Q; cin >> Q;
    vector< vector< pair<int, int> > > queries(N);
    for (int i = 0; i < Q; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;
        queries[y].emplace_back(x, i);
    }

    SegmentTree S(N);
    for (int i = 0; i < N; ++i)
        S.update(i, i + 1, -1, i);

    vector<int> answer(Q);
    for (int i = 0; i < N; ++i) {
        S.update(0, from[i] + 1, from[i], i);

        for (auto &[x, index] : queries[i])
            answer[index] = S.query(x);
    }
    for (int i = 0; i < Q; ++i)
        cout << answer[i] + 1 << "\n";
}