#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
const int LG = 19;
int a[N];
int dp[N][LG];
int l[LG];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < LG; ++i) l[i] = n + 1;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < LG; ++j) dp[i][j] = n + 1;
        for (int j = 0; j < LG; ++j) {
            if (l[j] == n + 1) continue;
            if ((a[i] >> j) & 1) {
                for (int k = 0; k < LG; ++k) {
                    dp[i][k] = min(dp[i][k], dp[l[j]][k]);
                }   
            }   
        }   
        for (int j = 0; j < LG; ++j) {
            if ((a[i] >> j) & 1) {
                dp[i][j] = i;
            }   
        }   
        for (int j = 0; j < LG; ++j) {
            if ((a[i] >> j) & 1) {
                l[j] = i;
            }   
        }
    }   
    while (q--) {
        int l, r;
        cin >> l >> r;
        string ans = "Fou";
        for (int i = 0; i < LG; ++i) {
            if ((a[r] >> i) & 1) {
                if (dp[l][i] <= r) {
                    ans = "Shi";
                }   
            }   
        }   
        cout << ans << '\n';        
    }   
}