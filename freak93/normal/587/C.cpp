#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <array>
#include <tuple>
#include <algorithm>
#include <cassert>

using namespace std;

static const int kInfinite = numeric_limits<int>::max();
static const int kMaxK = 10;

array<int, kMaxK> merge(const array<int, kMaxK> first, const array<int, kMaxK> second) {
    array<int, kMaxK> result;
    int i = 0, j = 0, k = 0;
    while (k < kMaxK) {
        if (first[i] < second[j]) {
            result[k++] = first[i++];
        } else {
            result[k++] = second[j++];
        }
    }
    return result;
}

class SegmentTree {
  public:
    SegmentTree(int size):
            m_size(size),
            m_data(size * 4) {
        for (int i = 0; i < size * 4; ++i)
            for (int j = 0; j < kMaxK; ++j)
                m_data[i][j] = kInfinite;
    }

    void update(int position, const array<int, kMaxK>& value) {
        update(1, 0, m_size, position, value);
    }

    array<int, kMaxK> query(int from, int to) {
        if (from >= to) {
            array<int, kMaxK> result;
            for (int i = 0; i < kMaxK; ++i)
                result[i] = kInfinite;
            return result;
        }

        return query(1, 0, m_size, from, to);
    }

  private:
    void update(int node, int begin, int end, int position, const array<int, kMaxK> &value) {
        if (end - begin == 1) {
            m_data[node] = value;
            return;
        }

        int mid = (begin + end) / 2;
        if (position < mid)
            update(node * 2, begin, mid, position, value);
        else
            update(node * 2 + 1, mid, end, position, value);
        m_data[node] = merge(m_data[node * 2], m_data[node * 2 + 1]);
    }

    array<int, kMaxK> query(int node, int begin, int end, int from, int to) const {
        if (from <= begin && end <= to)
            return m_data[node];

        int mid = (begin + end) / 2;
        if (to <= mid)
            return query(node * 2, begin, mid, from, to);
        if (mid <= from)
            return query(node * 2 + 1, mid, end, from, to);
        return merge(query(node * 2, begin, mid, from, to), query(node * 2 + 1, mid, end, from, to));
    }

    int m_size;
    vector< array<int, kMaxK> > m_data;
};

class Tree {
  public:
    Tree(int size):
        m_edge(size),
        m_depth(size, 0),
        m_ancestor(size, vector<int>(2 * kMaxK)),
        m_values(size),
        m_node_q(size),
        m_tree(size) {
    }

    void addEdge(int x, int y) {
        m_edge[x].push_back(y);
        m_edge[y].push_back(x);
    }

    void prepare() {
        dfsPrepare(0);
    }

    void setValues(int node, array<int, kMaxK> vals) {
        m_values[node] = vals;
    }

    void addQuery(int from, int to) {
        m_node_q[from].push_back(m_queries.size());
        m_node_q[to].push_back(m_queries.size());
        m_queries.emplace_back(from, to, lca(from, to));
    }

    void solve() {
        m_first.resize(m_queries.size());
        m_second.resize(m_queries.size());
        dfsSolve(0);
    }

    array<int, kMaxK> answer(int q) {
        if (get<0>(m_queries[q]) == get<1>(m_queries[q]))
            return m_values[get<0>(m_queries[q])];

        return merge(m_first[q], m_second[q]);
    }

  private:
    void dfsSolve(int node, int father = -1) {
        m_tree.update(m_depth[node], m_values[node]);
        for (auto &q : m_node_q[node]) {
            int anc = get<2>(m_queries[q]);
            int ancd = m_depth[anc];

            if (get<0>(m_queries[q]) == node)
                m_first[q] = m_tree.query(ancd, m_depth[node] + 1);
            else
                m_second[q] = m_tree.query(ancd + 1, m_depth[node] + 1);
        }

        for (auto &x : m_edge[node])
            if (x != father)
                dfsSolve(x, node);
    }

    int lca(int x, int y) {
        if (m_depth[x] < m_depth[y])
            swap(x, y);
        for (int i = 0; i < 2 * kMaxK; ++i)
            if ((1 << i) & (m_depth[x] - m_depth[y]))
                x = m_ancestor[x][i];
        if (x == y)
            return x;

        for (int i = 2 * kMaxK - 1; i >= 0; --i)
            if (m_ancestor[x][i] != m_ancestor[y][i]) {
                x = m_ancestor[x][i];
                y = m_ancestor[y][i];
            }
        return m_ancestor[x][0];
    }

    void dfsPrepare(int node, int father = -1) {
        m_ancestor[node][0] = father;
        for (int i = 1; i < 2 * kMaxK; ++i)
            if (m_ancestor[node][i - 1] != -1)
                m_ancestor[node][i] = m_ancestor[m_ancestor[node][i - 1]][i - 1];

        for (auto &x : m_edge[node])
            if (x != father) {
                m_depth[x] = m_depth[node] + 1;
                dfsPrepare(x, node);
            }
    }


    vector< vector<int> > m_edge;
    vector<int> m_depth;
    vector< vector<int> > m_ancestor;
    vector< array<int, kMaxK> > m_values;

    vector< tuple<int, int, int> > m_queries;
    vector< vector<int> > m_node_q;
    SegmentTree m_tree;
    vector< array<int, kMaxK> > m_first, m_second;
};

int main() {
    ios::sync_with_stdio(false);

    int N, M, Q; cin >> N >> M >> Q;

    Tree T(N);
    for (int i = 1; i < N; ++i) {
        int x, y; cin >> x >> y;
        T.addEdge(x - 1, y - 1);
    }

    T.prepare();
    vector< vector<int> > values(N);
    for (int i = 1; i <= M; ++i) {
        int c; cin >> c;
        --c;
        values[c].push_back(i);
    }

    for (int i = 0; i < N; ++i) {
        sort(values[i].begin(), values[i].end());
        array<int, kMaxK> vals;
        for (int j = 0; j < kMaxK; ++j)
            vals[j] = kInfinite;
        for (int j = 0; j < kMaxK && j < int(values[i].size()); ++j)
            vals[j] = values[i][j];
        T.setValues(i, vals);
    }

    vector<int> sizes(Q);
    for (int i = 0; i < Q; ++i) {
        int u, v, a; cin >> u >> v >> a;
        T.addQuery(u - 1, v - 1);
        sizes[i] = a;
    }

    T.solve();
    for (int i = 0; i < Q; ++i) {
        auto arr = T.answer(i);
        int p;
        for (p = 0; arr[p] < kInfinite && p < sizes[i]; ++p);
        cout << p << " ";
        for (int j = 0; j < p; ++j)
            cout << arr[j] << " ";
        cout << "\n";
    }
}