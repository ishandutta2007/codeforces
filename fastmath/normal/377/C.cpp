#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-reorder-functions")
#pragma GCC optimize("profile-values")
#pragma GCC optimize("tracer")
#pragma GCC optimize("vpt")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("ssse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")
#include<bits/stdc++.h>
using namespace std;
const int M = 20;
const int N = 101;
int a[N];
int dp[M + 1][1 << M];
char type[M];
int team[M];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> type[i] >> team[i];
    sort(a, a + n);
    reverse(a, a + n);
    n = min(n, m);
    for (int i = m - 1; i >= 0; --i) {
        if (type[i] == 'p') {  
            dp[i][0] = dp[i + 1][0];
            for (int mask = 1; mask < (1 << n); ++mask) {
                int p = -1;
                for (int b = 0; b < n; ++b) {
                    if ((mask >> b) & 1) {
                        p = b;
                        break;
                    }   
                }   
                if (team[i] == 1) {
                    dp[i][mask] = dp[i + 1][mask ^ (1 << p)] + a[p];
                }
                else {
                    dp[i][mask] = dp[i + 1][mask ^ (1 << p)] - a[p];
                }   
            }
        }       
        else {
            for (int mask = 0; mask < (1 << n); ++mask) {
                dp[i][mask] = dp[i + 1][mask];
                for (int b = 0; b < n; ++b) {
                    if ((mask >> b) & 1) {
                        if (team[i] == 1) dp[i][mask] = max(dp[i][mask], dp[i + 1][mask ^ (1 << b)]);
                        else dp[i][mask] = min(dp[i][mask], dp[i + 1][mask ^ (1 << b)]);
                    }   
                }   
            }            
        }   
    }       
    cout << dp[0][(1 << n) - 1] << '\n';
}