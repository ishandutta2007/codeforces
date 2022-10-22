#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
map <int, vector <int> > d;
struct Edge {
    int u, v, c;
};  
Edge ed[N];
int par[N], cnt[N];
int root(int u) {
    if (par[u] == u) return u;
    else return par[u] = root(par[u]);
}   
bool merge(int u, int v) {
    u = root(u); v = root(v);
    if (u == v) return 0;
    if (cnt[u] < cnt[v]) {
        cnt[v] += cnt[u];
        par[u] = v;
    }
    else {
        cnt[u] += cnt[v];
        par[v] = u;
    }   
    return 1;
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> ed[i].u >> ed[i].v >> ed[i].c;
        --ed[i].u; --ed[i].v;
        d[ed[i].c].push_back(i);
    }   
    for (int i = 0; i < n; ++i) {
        par[i] = i; cnt[i] = 1;
    }   
    int ans = 0;
    for (auto e : d) {
        int cnt = 0;
        for (int i : e.second) {
            cnt += root(ed[i].u) != root(ed[i].v);
        }   
        int get = 0;
        for (int i : e.second) {
            get += merge(ed[i].u, ed[i].v);
        }   
        
        #ifdef HOME
            cout << e.first << ' ' << cnt << ' ' << get << '\n';
        #endif

        ans += cnt - get;
    }   
    cout << ans << '\n';
}