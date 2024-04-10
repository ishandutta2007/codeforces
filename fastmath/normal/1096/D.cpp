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
int dp[4], dp1[4];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    const int INF = 1e18;
    string w = "hard";
    for (int i = 0; i < n; ++i) {
        int x;        
        cin >> x;
        for (int j = 0; j < 4; ++j)
            dp1[j] = INF;
        for (int j = 0; j < 4; ++j) {
            if (s[i] != w[j]) {
                dp1[j] = min(dp1[j], dp[j]);
            }   
            else {
                dp1[j] = min(dp1[j], dp[j] + x);
                if (j < 3) {
                dp1[j + 1] = min(dp1[j + 1], dp[j]);
                }   
            }   
        }   
        for (int j = 0; j < 4; ++j)
            dp[j] = dp1[j];
    }   
    int ans = 1e18;
    for (int i = 0; i <= 3; ++i)
        ans = min(ans, dp[i]);
    cout << ans << endl;                
}