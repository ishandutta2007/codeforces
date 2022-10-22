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
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7, MOD = 1000 * 1000 * 1000 + 7;
int par[N], d[N];

int mod(int n) {
    n %= MOD;
    if (n < 0)
        return n + MOD;
    else
        return n;
}   

int root(int u) {
    if (par[u] == u) {
        return u;
    }
    else {
        int mem = par[u];
        par[u] = root(par[u]);
        d[u] = mod(d[u] + d[mem]);
        return par[u];
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < N; ++i) 
        par[i] = i;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int v, x;
            cin >> v >> x;
            int r = root(v);
            par[r] = i;
            d[r] = mod(d[v] + x);
            ans = mod(ans + d[r]);
        }   
    }   
    cout << ans << endl;
}