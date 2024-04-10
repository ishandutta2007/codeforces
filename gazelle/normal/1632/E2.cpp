#include <bits/stdc++.h>
#define FOR(i, n, m) for(long long i = (n); i < (long long)(m); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr ld eps = 1e-6;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
    REP(i, v.size()) {
        if(i)
            os << " ";
        os << v[i];
    }
    return os;
}

void calc_depth(int v, int p, int d, vector<vector<int>> &g,
                vector<int> &depth) {
    depth[v] = d;
    for(auto ch : g[v]) {
        if(ch == p)
            continue;
        calc_depth(ch, v, d + 1, g, depth);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(i, t) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);

        REP(i, n - 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].pb(v);
            g[v].pb(u);
        }

        vector<int> depth(n);
        calc_depth(0, -1, 0, g, depth);

        int max_depth = 0, r = 0;

        REP(i, n) {
            if(max_depth < depth[i]) {
                max_depth = depth[i];
                r = i;
            }
        }

        vector<int> dist(n, inf);
        queue<int> q;
        dist[r] = 0;
        q.push(r);

        while(not q.empty()) {
            int p = q.front();
            q.pop();
            for(auto adj : g[p]) {
                if(dist[adj] == inf) {
                    dist[adj] = dist[p] + 1;
                    q.push(adj);
                }
            }
        }

        vector<int> diam_by_k(n, 0);

        REP(i, n) {
            if(i == 0)
                continue;
            diam_by_k[depth[i] - 1] =
                max(diam_by_k[depth[i] - 1], (int)ceil(dist[i] / 2.0));
        }
        // cout << depth << endl;
        // cout << dist << endl;
        // cout << diam_by_k << endl;
        for(int i = n - 2; i >= 0; i--)
            diam_by_k[i] = max(diam_by_k[i], diam_by_k[i + 1]);

        for(int x = 1; x <= n; x++) {
            int ok = n, ng = -1;
            while(ok - ng > 1) {
                int k = (ok + ng) / 2;
                if(k - diam_by_k[k] >= x)
                    ok = k;
                else
                    ng = k;
            }
            cout << min(ok, max_depth);
            if(x < n)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}