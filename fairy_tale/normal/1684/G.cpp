#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int maxn = 1e5 + 5;
const int mod = 998244353;


struct Match {
    // n  m
    vector<int> g[maxn];
    int pa[maxn];  //    -1
    int pb[maxn];  // 
    int vis[maxn];  // 
    int n, m;         //   node[0,n-1],[0,m-1]
    int dfn;          // 
    int res;          // 

    void init(int _n, int _m) {
        n = _n, m = _m;
        fill(pa, pa + n, -1);
        fill(pb, pb + m, -1);
        fill(vis, vis + n, 0);
        for (int i = 0; i < n; i++) g[i].clear();
        res = dfn = 0;
    }

    void add_edge(int from, int to) { // 
        g[from].push_back(to);
    }

    bool dfs(int v) {
        vis[v] = dfn;
        for (int u : g[v]) {
            if (pb[u] == -1) {
                pb[u] = v;
                pa[v] = u;
                return true;
            }
        }
        for (int u : g[v]) {
            if (vis[pb[u]] != dfn && dfs(pb[u])) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
    }

    int solve() {
        while (true) {
            dfn++;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (pa[i] == -1 && dfs(i)) {
                    cnt++;
                }
            }
            if (cnt == 0) {
                break;
            }
            res += cnt;
        }
        return res;
    }
} graph;

vector<int> fa, fb;
void solve()
{
    int n, m;
    LL x;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x * 3 <= m) fa.push_back(x);
        else if (x * 2 + 1 <= m) fb.push_back(x);
        else {
            cout << -1 << endl;
            return;
        }
    }

    int L = fa.size();
    int R = fb.size();
    if (L < R) {
        cout << -1 << endl;
        return;
    }

    graph.init(L, R);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            if (fb[j] % fa[i] == 0 && fa[i] + fb[j] * 2 <= m) graph.add_edge(i, j);
        }
    }

    if (graph.solve() != R) {
        cout << -1 << endl;
        return;
    }

    vector<P> ans;
    for (int i = 0; i < R; i++) {
        if (graph.pb[i] != -1) {
            int j = graph.pb[i];
            ans.push_back(P(fb[i] * 2 + fa[j], fb[i] + fa[j]));
        }
    }
    for (int i = 0; i < L; i++) {
        if (graph.pa[i] == -1) {
            ans.push_back(P(fa[i] * 3, fa[i] * 2));
        }
    }

    cout << ans.size() << endl;
    for (auto e:ans) cout << e.fi << " " << e.se << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    //cin >> pT;
    while (pT--)
    {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}