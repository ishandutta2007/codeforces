#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// computes maximum matching in a bipartite graph
// N vertices on the left, and M vertices on the right
template<int N, int M>
struct matcher {

    vector<int> adj[N];
    int ord[N], L[N], R[M];
    bool vis[N];

    // add an edge between i on the left, and j on the right
    void edge(int i, int j) {
        adj[i].push_back(j);
    }

    bool dfs(int i) {
        if (vis[i]) return 0;
        vis[i] = 1;
        for (int j : adj[i])
            if (R[j] == -1) {
                L[i] = j;
                R[j] = i;
                return 1;
            }
        for (int j : adj[i])
            if (dfs(R[j])) {
                L[i] = j;
                R[j] = i;
                return 1;
            }
        return 0;
    }

    // returns a list of edges {left, right}. runs in O(E \sqrt V) time.
    vector<pair<int, int>> solve() {
        iota(ord, ord+N, 0);
        random_shuffle(ord, ord+N);
        fill(L, L+N, -1);
        fill(R, R+M, -1);
        bool v = 1;
        while (v) {
            v = 0;
            fill(vis, vis+N, 0);
            for (int i : ord)
                if (!vis[i] && L[i] == -1)
                    v |= dfs(i);
        }
        vector<pair<int, int>> out;
        for (int i = 0; i < N; i++)
            if (L[i] != -1)
                out.emplace_back(i, L[i]);
        return out;
    }
};

matcher<50000, 50000> b;
bool a[500][500];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            a[i][j] = c == '#';
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (!a[i][j]) continue; ans++;
            if (a[i+1][j]) ans--;
            if (a[i][j+1]) ans--;
            if (a[i-1][j] && a[i][j-1]) b.edge(i*m+j, i*m+j);
            if (a[i+1][j] && a[i][j-1]) b.edge(i*m+j+m, i*m+j);
            if (a[i-1][j] && a[i][j+1]) b.edge(i*m+j, i*m+j+1);
            if (a[i+1][j] && a[i][j+1]) b.edge(i*m+j+m, i*m+j+1);
        }
    cout << ans+int(b.solve().size()) << "\n";
}