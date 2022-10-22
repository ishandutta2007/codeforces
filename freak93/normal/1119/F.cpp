#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class FenwickTree {
  public:
    FenwickTree(int size = 0):
        m_data(size, 0) {}

    int size() const {
        return m_data.size();
    }

    void add(int pos, int value) {
        for (++pos; pos <= size(); pos += (pos & -pos))
            m_data[pos - 1] += value;
    }

    int64_t sum(int pos) const {
        int64_t answer = 0;
        for (++pos; pos; pos -= (pos & -pos))
            answer += m_data[pos - 1];
        return answer;
    }

    int count(int sum) const {
        if (sum == 0)
            return -1;
        int step;
        for (step = 1; step <= size(); step <<= 1);
        int answer = 0;
        for (; step; step >>= 1)
            if (answer + step <= size() && m_data[answer + step - 1] < sum) {
                sum -= m_data[answer + step - 1];
                answer += step;
            }
        return answer;
    }

  private:
    vector<int64_t> m_data;
};

class EdgeStructure {
  public:
    EdgeStructure(int size):
        m_values(size), m_fenwick_sum(size), m_fenwick_count(size) {}

    void add_value(int node, int value) {
        m_values[node].push_back(value);
    }

    int size() const {
        return m_values.size();
    }

    void prepare() {
        for (int i = 0; i < size(); ++i) {
            sort(m_values[i].begin(), m_values[i].end());
            m_fenwick_sum[i] = FenwickTree(m_values[i].size());
            m_fenwick_count[i] = FenwickTree(m_values[i].size());
        }
    }

    int64_t query(int node, int count) const {
        if (count <= 0)
            return 0;

        int where = m_fenwick_count[node].count(count);
        if (where == int(m_fenwick_count[node].size()))
            return numeric_limits<int64_t>::max() / 1000000;
        return m_fenwick_sum[node].sum(where);
    }

    void add(int node, int value) {
        int upper = upper_bound(m_values[node].begin(), m_values[node].end(), value) - m_values[node].begin();
        int lower = lower_bound(m_values[node].begin(), m_values[node].end(), value) - m_values[node].begin();

        // find the next open space,
        int count = m_fenwick_count[node].sum(upper - 1);
        int where = max(lower, int(m_fenwick_count[node].count(count)) + 1);
        assert(m_values[node][where] == value);
        assert(m_fenwick_count[node].sum(where - 1) == m_fenwick_count[node].sum(where));
        m_fenwick_count[node].add(where, 1);
        m_fenwick_sum[node].add(where, value);
    }

    void remove(int node, int value) {
        int upper = upper_bound(m_values[node].begin(), m_values[node].end(), value) - m_values[node].begin();

        int count = m_fenwick_count[node].sum(upper - 1);
        int where = m_fenwick_count[node].count(count);
        assert(m_values[node][where] == value);
        assert(m_fenwick_count[node].sum(where) == m_fenwick_count[node].sum(where - 1) + 1);
        m_fenwick_count[node].add(where, -1);
        m_fenwick_sum[node].add(where, -value);
    }

  private:
    vector< vector<int> > m_values;
    vector<FenwickTree> m_fenwick_sum, m_fenwick_count;
};

class Tree {
  public:
    Tree(int size):
        m_edges(size),
        m_used(size, false),
        m_to_delete(size, 0) {}

    void add_edge(int from, int to, int cost) {
        m_edges[from].emplace_back(to, cost);
        m_edges[to].emplace_back(from, cost);
    }

    int size() const {
        return m_edges.size();
    }

    vector<int64_t> degree_cost() const {
        Tree temp(size());

        vector<int> nodes(size());
        for (int i = 0; i < size(); ++i)
            nodes[i] = i;
        sort(nodes.begin(), nodes.end(), [&](int x, int y) {
            return m_edges[x].size() < m_edges[y].size();
        });

        vector<int> good_nodes;
        vector<bool> used(size(), false);
        EdgeStructure S(size());

        for (int i = 0; i < size(); ++i)
            for (auto &edge : m_edges[i])
                S.add_value(i, edge.second);

        S.prepare();

        vector<int64_t> answer(size(), 0);
        for (int degree = size() - 1; degree > 0; --degree) {
            while (!nodes.empty() && int(m_edges[nodes.back()].size()) >= degree) {
                int node = nodes.back();
                nodes.pop_back(); 
                good_nodes.push_back(node);
                used[node] = true;
                for (auto &edge : m_edges[node])
                    if (used[edge.first]) {
                        temp.add_edge(node, edge.first, edge.second);
                        S.remove(edge.first, edge.second);
                    } else {
                        S.add(node, edge.second);
                    }
            }

            for (auto &x : good_nodes)
                temp.need_delete(x);

            int64_t current_answer = 0;
            for (auto &x : good_nodes)
                current_answer += temp.dp(x, S).second;
            for (auto &x : good_nodes)
                temp.reset_used(x);
            answer[degree - 1] = current_answer;
        }
        return answer;
    }

  private:
    void reset_used(int node) {
        m_used[node] = false;
    }

    void need_delete(int node) {
        m_to_delete[node]++;
    }

    pair<int64_t, int64_t> dp(int node, const EdgeStructure& S) {
        if (m_used[node])
            return {0, 0};

        m_used[node] = true;

        if (m_edges[node].size() == 0) { // single node
            auto answer = S.query(node, m_to_delete[node]);
            return {answer, answer};
        }

        vector< pair<int64_t, int64_t> > dp_sons;
        dp_sons.reserve(m_edges[node].size() - 1);
        for (auto &edge : m_edges[node])
            if (!m_used[edge.first]) {
                auto son_dp = dp(edge.first, S);
                dp_sons.emplace_back(min(son_dp.first, son_dp.second) + edge.second, min(son_dp.second, son_dp.first + edge.second));
            }

        // now we want to select m_to_delete[node] edges, K of which will be edges connecting to sons
        //
        // for fixed K this is: S.query(node, m_to_delete[node] - K) + some K dp_sons[i].first + rest dp_sons[i].second
        // makes sense to take the ones with first - second minimum, 
        sort(dp_sons.begin(), dp_sons.end(), [&](const pair<int64_t, int64_t> &x, const pair<int64_t, int64_t> &y) {
            return x.first - x.second < y.first - y.second;
        });

        int64_t son_part = 0;
        for (auto &d : dp_sons)
            son_part += d.second;
        
        int64_t best_with = S.query(node, m_to_delete[node]) + son_part;
        int64_t best_without = S.query(node, m_to_delete[node] - 1) + son_part;

        for (int K = 0; K < m_to_delete[node] && K < int(dp_sons.size()); ++K) {
            son_part -= dp_sons[K].second;
            son_part += dp_sons[K].first;
            best_with = min(best_with, S.query(node, m_to_delete[node] - K - 1) + son_part);
            if (m_to_delete[node] - K - 2 >= 0)
                best_without = min(best_without, S.query(node, m_to_delete[node] - K - 2) + son_part);
        }
        return {best_without, best_with};
    }

    vector< vector<pair<int, int> > > m_edges;
    vector<bool> m_used;
    vector<int> m_to_delete;
};

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;
    Tree T(N);
    for (int i = 1; i < N; ++i) {
        int x, y, z; cin >> x >> y >> z;
        T.add_edge(x - 1, y - 1, z);
    }

    for (auto x : T.degree_cost())
        cout << x << " ";
    cout << "\n";
}