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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int n, m;
int x[N], s[N];
int dp[N], pref[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> x[i] >> s[i];
    const int INF = 1e18 + 7;
    for (int i = 1; i <= m; ++i) {
        dp[i] = INF;
        for (int j = 0; j < n; ++j) {
            int r = x[j] - max(abs(i - x[j]), s[j]) - 1;
            if (r < 0) {
                dp[i] = min(dp[i], max(0ll, i - x[j] - s[j]));
            }
            else {
                dp[i] = min(dp[i], pref[r] + x[j] - s[j] - 1);
            }
        }   
        dp[i] -= i;
        pref[i] = min(pref[i], dp[i]);
    }   
    cout << dp[m] + m << '\n';
}