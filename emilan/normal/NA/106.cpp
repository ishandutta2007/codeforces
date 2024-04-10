#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

pair<int, vector<int>> scc(const vector<vector<int>> &adj) {
    int n = int(size(adj));

    vector<int> tin(n, -1), low(n);
    int t = 0;
    stack<int> st;
    vector<int> scc_id(n, -1);
    int scc_cnt = 0;
    auto dfs = [&](auto &self, int u) -> void {
        tin[u] = low[u] = t++;
        st.push(u);
        for (int v : adj[u]) if (scc_id[v] == -1) {
            if (tin[v] == -1) self(self, v);
            low[u] = min(low[u], low[v]);
        }

        if (low[u] == tin[u]) {
            int v;
            do {
                v = st.top();
                st.pop();
                scc_id[v] = scc_cnt;
            } while (v != u);
            scc_cnt++;
        }
    };
    for (int s = 0; s < n; s++) if (tin[s] == -1) {
        dfs(dfs, s);
    }

    return {scc_cnt, scc_id};
}

class TwoSat {
  public:
    // n external nodes <-> 2 * n internal nodes
    TwoSat(int n) : n_(n), adj_(2 * n) {}

    int inv(int u) const { return u < n_ ? u + n_ : u - n_; }

    void add_clause(int u, int v) {
        adj_[inv(u)].push_back(v);
        adj_[inv(v)].push_back(u);
    }

    vector<bool> solve() const {
        auto [scc_cnt, scc_id] = scc(adj_);

        vector<bool> ans(n_);
        for (int u = 0; u < n_; u++) {
            if (scc_id[u] == scc_id[u + n_]) return {};
            else ans[u] = scc_id[u] < scc_id[u + n_];
        }
        return ans;
    }

  private:
    int n_;
    vector<vector<int>> adj_;
};

const array<pii, 4> dirs = {{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
}};

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (auto &v : a) {
        for (auto &x : v) cin >> x;
    }

    auto oob = [&](int i, int j) {
        return !(0 <= i && i < n && 0 <= j && j < m);
    };

    TwoSat ts(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (auto [di, dj] : dirs) {
                int i2 = i + di;
                int j2 = j + dj;
                if (oob(i2, j2)) continue;

                int u = i * m + j;
                int v = i2 * m + j2;
                if (a[i][j] == a[i2][j2] - 1) {
                    ts.add_clause(ts.inv(u), v);
                } else if (a[i][j] == a[i2][j2]) {
                    ts.add_clause(ts.inv(u), ts.inv(v));
                    ts.add_clause(u, v);
                } else if (a[i][j] == a[i2][j2] + 1) {
                    ts.add_clause(ts.inv(u), v);
                }
            }
        }
    }

    auto ans = ts.solve();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] + ans[i * m + j] << " \n"[j == m - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}