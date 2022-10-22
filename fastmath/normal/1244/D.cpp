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
const int INF = 1e18 + 7;
const int N = 1e5 + 7;
int dp[N][4][4], a[4][N];
vector <int> ord;
vector <int> g[N];
void dfs(int u, int p) {
    ord.app(u);
    for (int v : g[u]) if (v != p) dfs(v, u);
}   
void upd(int &a, int b) { a = min(a, b); }
bool check(int a, int b) {
    return a == 0 || b == 0 || a != b;
}   
int n;
int color[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 1; i <= 3; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() > 2) {
            cout << "-1\n";
            exit(0);
        }   
    }   
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) { dfs(i, i); break; }
    }   
    for (int i = 0; i < N; ++i) for (int j = 0; j < 4; ++j) for (int k = 0; k < 4; ++k) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int v = ord[i];
        for (int c1 = 0; c1 < 4; ++c1) {
            for (int c2 = 0; c2 < 4; ++c2) {
                for (int c3 = 1; c3 <= 3; ++c3) {
                    if (check(c1, c2) && check(c2, c3) && check(c1, c3)) {
                        upd(dp[i + 1][c2][c3], dp[i][c1][c2] + a[c3][v]);
                    }
                }   
            }   
        }   
    }   
    int ans = INF;
    int c2 = -1, c3 = -1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (dp[n][i][j] < ans) {
                ans = dp[n][i][j];
                c2 = i; c3 = j;
            }   
        }
    }
    cout << ans << '\n';
    color[ord[n - 1]] = c3; color[ord[n - 2]] = c2;
    for (int i = n - 1; i >= 2; --i) {
        int v = ord[i];
        for (int c1 = 0; c1 <= 4; ++c1) {
            if (check(c1, c2) && check(c2, c3) && check(c1, c3) && dp[i][c1][c2] + a[c3][v] == dp[i + 1][c2][c3]) {
                c3 = c2;
                c2 = c1;
                color[ord[i - 2]] = c1;
                break;
            }   
        }   
    }   
    for (int i = 1; i <= n; ++i) cout << color[i] << ' ';
    cout << '\n';
}