#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 507;
const int INF = 1e18 + 7;
struct Credit {
    int a, b, k;
};  
Credit a[N];
int dp[N][N];
bool comp(Credit a, Credit b) {
    return a.b > b.b;
}   
int max(int a, int b, int c) {
    return max(max(a, b), c);
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].a >> a[i].b >> a[i].k;
    }   
    sort(a, a + n, comp);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = -INF;
        }   
    }   

    #ifdef HOME
    for (int i = 0; i < n; ++i) cout << a[i].a << ' ' << a[i].b << ' ' << a[i].k << '\n';
    cout << '\n';
    #endif

    int ans = 0;
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = max(dp[i][0], dp[i][0] + a[i].a - a[i].b * a[i].k);
        for (int j = 1; j <= i + 1; ++j) {
            dp[i + 1][j] = max(dp[i][j], dp[i][j - 1] + a[i].a - a[i].b * (j - 1), dp[i][j] + a[i].a - a[i].b * a[i].k);
            ans = max(ans, dp[i + 1][j]);
        }   
    }   
    cout << ans << '\n';
}