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
const int N = 2e5 + 7;
vector <int> g[N];
bool h[N], w[N];
int cost[N];

void dfs1(int u, int p) {
    for (int v : g[u]) {
        if (v != p) {
            cost[v] = min(cost[v], cost[u]);
            dfs1(v, u);
        }   
    }   
}   

int ans = 0;
vector <int> dfs2(int u, int p) {
    vector <int> res(2);
    if (h[u] ^ w[u]) {
        ++res[h[u]];
    }   
    for (int v : g[u]) {
        if (v != p) {
            auto add = dfs2(v, u);
            for (int i = 0; i < 2; ++i)
                res[i] += add[i];
        }   
    }   
    int mn = min(res[0], res[1]);
    ans += 2 * mn * cost[u];
    res[0] -= mn;
    res[1] -= mn;
    return res;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> cost[i] >> h[i] >> w[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }
    dfs1(1, 1);
    auto res = dfs2(1, 1);
    if (res[0] || res[1]) {
        cout << -1 << endl;
        exit(0);
    }   
    cout << ans << endl;
}