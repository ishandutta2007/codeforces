#include<bits/stdc++.h>
using namespace std;
#define int long long
#define v first
#define c second
const int N = 1e5 + 9;
vector <pair <int, int> > g[N];
pair <int, int> dfs(int u, int p) {
    pair <int, int> ans = {0, u};
    for (auto e : g[u]) {
        if (e.v != p) {
            auto t = dfs(e.v, u); t.first += e.c;
            ans = max(ans, t);
        }   
    }   
    return ans;
}   
vector <int> d;
bool getp(int u, int p, int w) {
    d.push_back(u);
    if (u == w) return 1;
    for (auto e : g[u]) {
        if (e.v != p) {
            if (getp(e.v, u, w)) return 1;
        }   
    }   
    d.pop_back();
    return 0;
}   
int pr[N], ps[N];
int dd[N];
const int INF = 1e18 + 7;

int h[N];
bool ind[N];
int geth(int u, int p) {  
    int ans = 0;
    for (auto e : g[u]) {
        if (e.v != p && !ind[e.v]) {
            ans = max(ans, geth(e.v, u) + e.c);
        }   
    }   
    return ans;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;

    map <pair <int, int> , int> ms;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
        ms[{u, v}] = c; ms[{v, u}] = c;
    }   
    auto t = dfs(1, 1);
    auto tt = dfs(t.second, t.second);
    getp(t.second, t.second, tt.second);
    k = min(k, (int)d.size());

    #ifdef HOME
    cout << "D: ";
    for (int e : d) cout << e << ' ';
    cout << '\n';
    #endif

    for (int e : d) ind[e] = 1;

    for (int i = 0; i < (int)d.size(); ++i) {
        h[i] = geth(d[i], d[i]);
    }   
    for (int i = 1; i < (int)d.size(); ++i) {
        dd[i] = dd[i - 1] + ms[{d[i], d[i - 1]}];
    }   
    pr[0] = -INF;
    for (int i = 0; i < (int)d.size(); ++i) {
        pr[i + 1] = max(pr[i], h[i] - dd[i]);
    }   
    ps[d.size()] = -INF;
    for (int i = (int)d.size() - 1; i >= 0; --i) {
        ps[i] = max(ps[i + 1], h[i] + dd[i]);
    }   
    
    int ans = INF;
    for (int l = 0; l + k - 1 < (int)d.size(); ++l) {
        int r = l + k - 1;
        int nn = 0;
        for (int i = l; i <= r; ++i) {
            nn = max(nn, h[i]);
        }   
        nn = max(nn, pr[l] + dd[l]);
        nn = max(nn, ps[r + 1] - dd[r]);

        #ifdef HOME
        cout << d[l] << ' ' << d[r] << " : " << nn << '\n';
        #endif

        ans = min(ans, nn);
    }   
    cout << ans << '\n';
}