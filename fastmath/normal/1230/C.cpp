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
const int C = 6, N = 10;
int n, m;
bool can[C + 1][C + 1], g[N][N];
int a[N];
int get() {
    memset(can, 0, sizeof can);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = a[i], y = a[j];
            if (y < x) swap(x, y);
            can[x][y] |= g[i][j];
        }   
    }   
    int ans = 0;
    for (int i = 1; i <= C; ++i) {
        for (int j = 1; j <= C; ++j) ans += can[i][j];
    }   
    return ans;
}   
int ans = 0;
void gen(int i) {
    if (i == n) {
        ans = max(ans, get()); 
        return;
    }   
    for (a[i] = 1; a[i] <= C; ++a[i]) gen(i + 1);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        --u; --v;
        g[u][v] = g[v][u] = 1;
    }   
    gen(0);
    cout << ans << '\n';
}