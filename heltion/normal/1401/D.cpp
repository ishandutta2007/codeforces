#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
constexpr int maxn = 100000 + 1;
vector<int> G[maxn];
LL sz[maxn];
void DFS(int u, int p = 0){
    sz[u] = 1;
    for(int v : G[u]) if(p != v){
        DFS(v, u);
        sz[u] += sz[v];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) G[i].clear();
        for(int i = 1, u, v; i < n; i += 1){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        DFS(1);
        vector<LL> v;
        for(int i = 2; i <= n; i += 1) v.push_back(sz[i] * (n - sz[i]));
        sort(v.begin(), v.end());
        int m;
        cin >> m;
        vector<LL> p(m);
        for(LL& x : p) cin >> x;
        sort(p.begin(), p.end());
        LL ans = 0;
        n -= 1;
        if(m <= n) for(int i = 0; i < n; i += 1) ans = (ans + v[i] % mod * (i + m - n >= 0 ? p[i + m - n] : 1)) % mod;
        else{
            for(int i = 0; i + 1 < n; i += 1) ans = (ans + v[i] % mod * p[i]) % mod;
            LL pans = v.back();
            for(int i = n - 1; i < m; i += 1) pans = pans * p[i] % mod;
            ans = (ans + pans) % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}