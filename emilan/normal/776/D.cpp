#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

class TwoSat {
  public:
    // n external nodes <-> 2 * n internal nodes
    TwoSat(int n_) : n(n_), adj(2 * n) {}

    int inv(int u) { return u < n ? u + n : u - n; }

    void add_clause(int u, int v) {
        adj[inv(u)].push_back(v);
        adj[inv(v)].push_back(u);
    }

    // returns {} if no solution
    // otherwise, solve()[u] == 1 iff NOT u is chosen
    vector<bool> solve() {
        vector<int> tin(2 * n, -1), low(2 * n);
        int t = 0;
        stack<int> st;
        vector<int> scc(2 * n, -1);
        int scc_cnt = 0;
        auto dfs = [&](auto &self, int u) -> void {
            tin[u] = low[u] = t++;
            st.push(u);
            for (int v : adj[u]) if (scc[v] == -1) {
                if (tin[v] == -1) self(self, v);
                low[u] = min(low[u], low[v]);
            }

            if (low[u] == tin[u]) {
                int v;
                do {
                    v = st.top();
                    st.pop();
                    scc[v] = scc_cnt;
                } while (v != u);
                scc_cnt++;
            }
        };
        for (int s = 0; s < 2 * n; s++) if (tin[s] == -1) {
            dfs(dfs, s);
        }

        vector<bool> ans(n);
        for (int u = 0; u < n; u++) {
            if (scc[u] == scc[u + n]) return {};
            else ans[u] = scc[u] < scc[u + n];
        }
        return ans;
    }

  private:
    int n;
    vector<vector<int>> adj;
};

bool solve() {
    int n_, n;
    cin >> n_ >> n;
    vector<int> init(n_);
    for (auto &x : init) cin >> x;
    vector<vector<int>> flip(n_);
    for (int u = 0; u < n; u++) {
        int k;
        cin >> k;
        while (k--) {
            int i;
            cin >> i;
            flip[i - 1].push_back(u);
        }
    }

    TwoSat two_sat(n);
    for (int i = 0; i < n_; i++) {
        int u = flip[i][0];
        int v = flip[i][1];
        if (init[i] == 0) {
            two_sat.add_clause(u, v);
            two_sat.add_clause(two_sat.inv(u), two_sat.inv(v));
        } else {
            two_sat.add_clause(u, two_sat.inv(v));
            two_sat.add_clause(two_sat.inv(u), v);
        }
    }

    return !empty(two_sat.solve());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << (solve() ? "YES" : "NO") << '\n';
}