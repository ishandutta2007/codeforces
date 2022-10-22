#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 2e5 + 7;
vector<int> g[N];
bool used[N];
int timer, tin[N], fup[N];
int cnt[N], dp[N];
bool inp[N];
int color[N];
int n, m, a, b;
void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    cnt[v] = 1;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (color[to] != color[v]) {
            fup[v] = -1;
            continue;
        }   
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            cnt[v] += cnt[to];
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] >= tin[v]) {
                dp[v] += cnt[to];
            }   
        }
    }
}
vector <int> path, cur;
void go(int u, int want) {
    cur.app(u);
    if (want == u) path = cur;
    used[u] = 1;
    for (int v : g[u]) 
        if (!used[v])
            go(v, want);
    cur.pop_back();
}

bool tc = 0;
void col(int u, int c) {
    used[u] = 1;
    if (color[u] != -1)
        tc = 1;
    color[u] = c;
    for (int v : g[u]) 
        if (!inp[v] && !used[v])
            col(v, c);
}     

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> a >> b;

        timer = 0; tc = 0;
        for (int u = 1; u <= n; ++u) {
            cnt[u] = dp[u] = tin[u] = fup[u] = used[u] = inp[u] = 0;
            color[u] = -1;
            g[u].clear();
        }   

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].app(v); g[v].app(u);
        }   
        for (int i = 0; i <= n; ++i)
            used[i] = 0;
        go(a, b);
        for (int e : path) {
            inp[e] = 1;
            color[e] = 0;
        }        

        for (int i = 0; i <= n; ++i)
            used[i] = 0;
        col(a, 1);
        for (int i = 0; i <= n; ++i)
            used[i] = 0;
        col(b, 2);

        for (int i = 0; i <= n; ++i)
            used[i] = 0;
        dfs(a);
        for (int i = 0; i <= n; ++i)
            used[i] = 0;
        dfs(b);

        cout << dp[a] * dp[b] << '\n';
    }   
}