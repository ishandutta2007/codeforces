#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 3e5+7;

int n, m, k;

map <ii, int> num;

namespace B {
const int MAXN = N;
vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];

bool isb[N];
 
void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v])
                isb[num[mp(v,to)]] = 1;
        }
    }
}
 
void find_bridges() {
    timer = 0;
    for (int i=1; i<=n; ++i)
        used[i] = false;
    for (int i=1; i<=n; ++i)
        if (!used[i])
            dfs (i);
}
};
vector <int> t[N];
int comp[N];
bool used[N];
void go(int u, int c) {
    used[u] = 1;
    comp[u] = c;
    for (int v : t[u])
        if (!used[v])
            go(v, c);
}   
int W = 0;
vector <ii> g[N];
int c[N];
bool is[N];
int cnt[N];
int dp[N];
int par[N];
void dfs(int u, int p) {
    par[u] = p;
    cnt[u] = is[u];
    dp[u] = c[u];
    for (auto e : g[u]) {
        int v = e.f, c = e.s;
        if (v != p) {
            dfs(v, u);
            cnt[u] += cnt[v];
            int add = dp[v];
            if (cnt[v] && cnt[v] < W) 
                add -= c;
            dp[u] += max(0ll, add);                        
        }
    }   
}   
int up[N];
void dfs2(int u, int p) {
    int sum = up[u] + dp[u];
    for (auto e : g[u]) {
        int v = e.f, c = e.s;
        if (v != p) {
            int add = dp[v];
            if (cnt[v] && cnt[v] < W) 
                add -= c;
            add = max(0ll, add);
            up[v] = sum - add;
            if (cnt[v] && cnt[v] < W)
                up[v] -= c;
            up[v] = max(up[v], 0ll);
            dfs2(v, u);
        }
    }
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> k;
    vector <int> sp1(k), is1(n+1), c1(n+1), w1(m);
    for (int i = 0; i < k; ++i) {
        cin >> sp1[i];
        is1[sp1[i]] = 1;
    }
    for (int i = 1; i <= n; ++i)
        cin >> c1[i];
    for (int i = 0; i < m; ++i) 
        cin >> w1[i];        
    vector <ii> ed;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        num[mp(u,v)] = num[mp(v,u)] = i;
        B::g[u].app(v);
        B::g[v].app(u);
        ed.app(mp(u,v));
    }   
    B::find_bridges();
    for (int i = 0; i < m; ++i) {
        if (!(B::isb[i])) {
            t[ed[i].f].app(ed[i].s);
            t[ed[i].s].app(ed[i].f);
        }   
    }   
    int ptr = 1;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            go(i, ptr);
            ++ptr;
        }   
    }   
    --ptr;
    for (int i = 0; i < m; ++i) {
        if (B::isb[i]) {
            int u = comp[ed[i].f];
            int v = comp[ed[i].s];
            assert(u != v);
            g[u].app(mp(v,w1[i]));
            g[v].app(mp(u,w1[i]));
        }   
    }       
    for (int i = 1; i <= n; ++i)
        c[comp[i]] += c1[i];
    for (int i = 1; i <= n; ++i)
        is[comp[i]] = is[comp[i]] | is1[i];
    int was_n = n;
    n = ptr;
    vector <int> ans(n+1);
    for (int i = 1; i <= n; ++i)
        W += is[i];    
    dfs(1, 1);
    dfs2(1, 1);

    for (int u = 1; u <= n; ++u) {
        ans[u] = up[u] + dp[u];        
    }   

    for (int i = 1; i <= was_n; ++i)    
        cout << ans[comp[i]] << ' ';
    cout << endl;
}