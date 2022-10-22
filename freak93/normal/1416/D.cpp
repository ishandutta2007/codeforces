#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class DisjointSet {
  public:
    DisjointSet(int size):
        m_size(size, 1),
        m_anc(size) {
        for (int i = 0; i < size; ++i)
            m_anc[i] = i;
        }

    pair<int, int> merge(int x, int y) {
        x = anc(x);
        y = anc(y);
        if (x == y)
            return make_pair(-1, -1);
        if (m_size[x] < m_size[y])
            swap(x, y);
        m_anc[y] = x;
        m_size[x] += m_size[y];
        return make_pair(x, y);
    }

  private:
    int anc(int x) {
        if (x == m_anc[x])
            return x;
        m_anc[x] = anc(m_anc[x]);
        return m_anc[x];
    }

    vector<int> m_size, m_anc;
};

void dfs(const vector< vector<int> > &adj, int node, vector<int> &liniar, vector<int> &begin, vector<int> &end) {
    begin[node] = liniar.size();
    liniar.push_back(node);
    for (auto &p : adj[node])
        dfs(adj, p, liniar, begin, end);
    end[node] = liniar.size();
}

class SegmentTree {
  public:
    SegmentTree(int size): m_size(size), m_data(size * 2, make_pair(0, -1)) {}

    void update(int pos, int value) {
        pos += m_size;
        m_data[pos] = make_pair(value, pos - m_size);
        for (pos /= 2; pos > 0; pos /= 2)
            m_data[pos] = max(m_data[pos * 2], m_data[pos * 2 + 1]);
    }

    pair<int, int> query(int l, int r) {
        l += m_size;
        r += m_size;

        pair<int, int> answer(0, -1);
        while (l < r) {
            if (l % 2)
                answer = max(answer, m_data[l++]);
            if (r % 2)
                answer = max(answer, m_data[--r]);
            l /= 2;
            r /= 2;
        }
        return answer;
    }

  private:
    int m_size;
    vector< pair<int, int> > m_data;
};

int main() {
    ios::sync_with_stdio(false);

    int N, M, Q; cin >> N >> M >> Q;

    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];

    vector< pair<int, int> > edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first;
        --edges[i].second;
    }

    vector< pair<int, int> > queries(Q);
    vector<bool> deleted(M, false);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        --queries[i].second;
        if (queries[i].first == 2)
            deleted[queries[i].second] = true;
    }

    DisjointSet D(N);
    vector< vector<int> > adj(N);
    vector<int> parent(N, -1);
    for (int i = 0; i < M; ++i)
        if (!deleted[i]) {
            auto p = D.merge(edges[i].first, edges[i].second);
            if (p.first == -1)
                continue;
            adj[p.first].push_back(p.second);
            parent[p.second] = p.first;
        }

    for (int i = Q - 1; i >= 0; --i) {
        if (queries[i].first == 1)
            continue;
        int x, y; tie(x, y) = edges[queries[i].second];
        auto p = D.merge(x, y);
        if (p.first == -1) {
            queries[i].second = -1;
            continue;
        }
        adj[p.first].push_back(p.second);
        parent[p.second] = p.first;
        queries[i].second = p.second;
    }

    vector<int> liniar, begin(N), end(N);
    for (int i = 0; i < N; ++i)
        if (parent[i] == -1)
            dfs(adj, i, liniar, begin, end);

    SegmentTree S(N);
    for (int i = 0; i < N; ++i)
        S.update(begin[i], P[i]);
    for (int i = 0; i < Q; ++i) {
        if (queries[i].first == 1) {
            int node = queries[i].second;
            while (parent[node] != -1)
                node = parent[node];
            auto answer = S.query(begin[node], end[node]);
            cout << answer.first << "\n";
            if (answer.second != -1)
                S.update(answer.second, 0);
        } else {
            int node = queries[i].second;
            if (node == -1)
                continue;
            end[parent[node]] = begin[node];
            parent[node] = -1;
        }
    }
}