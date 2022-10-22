#include<bits/stdc++.h>
using namespace std;
const int N = 51;
const int INF = 1e9 + 7;
struct Quer {
    int l, r, x, c;
};  
int n, h, m;
Quer a[N];
int dp[N][N][N];
int get(int mx, int l, int r) {
    if (r < l) return 0;
    int ans = -INF;
    for (int i = 0; i <= mx; ++i) {
        ans = max(ans, dp[i][l][r]);
    }   
    return ans;
}   
void solve(int mx, int l, int r) {
    vector <int> q;
    for (int i = 0; i < m; ++i) {
        if (l <= a[i].l && a[i].r <= r) {
            q.push_back(i);
        }   
    }   
    dp[mx][l][r] = -INF;
    for (int i = l; i <= r; ++i) {
        int add = mx * mx;
        for (int t : q) {
            if (a[t].l <= i && i <= a[t].r && a[t].x < mx) {
                add -= a[t].c;
            }   
        }   
        dp[mx][l][r] = max(dp[mx][l][r], get(mx, l, i - 1) + get(mx, i + 1, r) + add);
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> h >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].x >> a[i].c;
        --a[i].l; --a[i].r;
    }   
    for (int mx = 0; mx <= h; ++mx) {
        for (int len = 0; len <= n; ++len) {
            for (int l = 0; l + len - 1 < n; ++l) {
                solve(mx, l, l + len - 1);
            }   
        }   
    }   
    int ans = -INF;
    for (int i = 0; i <= h; ++i) {
        ans = max(ans, dp[i][0][n - 1]);
    }   
    cout << ans << '\n';
}