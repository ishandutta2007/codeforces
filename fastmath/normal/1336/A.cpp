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
const int N = 5e5 + 7;
vector <int> g[N];
int n, k, h[N], cnt[N];
void dfs(int u, int p) {
    cnt[u] = 1;
    for (int v : g[u]) {
        if (v != p) {
            h[v] = h[u] + 1;
            dfs(v, u);
            cnt[u] += cnt[v];
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
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    dfs(1, 1);
    vector <int> a;
    for (int i = 1; i <= n; ++i)
        a.app(h[i] - (cnt[i] - 1));
    sort(all(a));
    reverse(all(a));
    int ans = 0;
    for (int i = 0; i < k; ++i)
        ans += a[i];
    cout << ans << endl;
}