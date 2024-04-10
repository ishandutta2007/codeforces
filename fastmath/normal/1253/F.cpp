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
const int N = 3e5 + 7, INF = 1e18 + 7;
int n, m, k, q, dist[N], to[N];
vector <ii> g[N];
struct Edge {int u, v, c; };
vector <Edge> ed;
bool comp(Edge a, Edge b) { return a.c < b.c; }
int c[N];
vector <int> a[N];
vector <ii> mem[N];
int ans[N];
void merge(int c1, int c2, int cost) {
    if (a[c2].size() < a[c1].size()) swap(c1, c2);
    for (auto u : a[c1]) 
        for (auto q : mem[u]) 
            if (c[q.f] == c2) 
                ans[q.s] = cost;
    for (auto u : a[c1]) {
        c[u] = c2;
        a[c2].app(u);
    }
    a[c1].clear();
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        g[u].app(mp(v, c)); g[v].app(mp(u, c));
        ed.app({u, v, c});
    }   
    for (int i = 0; i < q; ++i) {
        int u, v; 
        cin >> u >> v;
        mem[u].app(mp(v, i));
        mem[v].app(mp(u, i));
    }   
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    set <ii> ms;
    for (int i = 1; i <= k; ++i) {
        dist[i] = 0; to[i] = i;
        ms.insert(mp(0, i));
    }   
    while (ms.size()) {
        int u = ms.begin()->s; ms.erase(ms.begin());
        for (auto e : g[u]) {
            if (dist[u] + e.s < dist[e.f]) {
                ms.erase(mp(dist[e.f], e.f));
                dist[e.f] = dist[u] + e.s;
                to[e.f] = to[u];
                ms.insert(mp(dist[e.f], e.f));
            }   
        }   
    }   
    vector <Edge> mst;
    for (auto e : ed) 
        if (to[e.u] != to[e.v]) 
            mst.app({to[e.u], to[e.v], dist[e.u] + dist[e.v] + e.c});
    sort(all(mst), comp);
    for (int i = 1; i <= k; ++i) {
        c[i] = i;
        a[i] = {i};
    }   
    for (auto e : mst) 
        if (c[e.u] != c[e.v]) 
            merge(c[e.u], c[e.v], e.c);
    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}