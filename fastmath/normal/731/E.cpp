#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 7;
int n;
int a[MAXN], pref[MAXN], dp[MAXN];
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }   
    dp[n - 1] = 0;
    int mx = pref[n];
    for (int i = n - 2; i >= 0; --i) {
        dp[i] = mx;
        mx = max(mx, pref[i + 1] - dp[i]);
    }   
    cout << dp[0] << '\n';
    #ifdef HOME
        cerr << "TIME: " << (double)clock() / CLOCKS_PER_SEC << '\n';
    #endif
}