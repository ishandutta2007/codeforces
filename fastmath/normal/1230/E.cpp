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
#define gcd LMAO_ROFL
const int N = 1e5 + 7, LG = 20, MOD = 1000 * 1000 * 1000 + 7;
int to[N][LG], gcd[N][LG];
vector <int> g[N];
int n, a[N], h[N];
void dfs(int u, int p) {
    to[u][0] = p;
    gcd[u][0] = __gcd(a[u], a[p]);
    for (int i = 1; i < LG; ++i) {
        to[u][i] = to[to[u][i - 1]][i - 1];
        gcd[u][i] = __gcd(gcd[u][i - 1], gcd[to[u][i - 1]][i - 1]);
    }   
    for (int v : g[u]) if (v != p) { h[v] = h[u] + 1; dfs(v, u); }
}   
bool check(int a, int b) {
    if (b == 0) return a == 0;
    else return a % b == 0;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    dfs(1, 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = a[i];
        int down = i;
        while (1) {
            int up = down;
            for (int j = LG - 1; j >= 0; --j) {
                if (check(gcd[up][j], cur)) {
                    up = to[up][j];
                }
            }   
            ans += (h[down] - h[up] + 1) * cur;
            //cout << i << " : " << down << ' ' << up << ' ' << cur << '\n';
            if (up == 1) break;
            down = to[up][0];
            cur = __gcd(cur, a[down]);
        }   
        ans %= MOD;       
    }           
    cout << ans << '\n';
}