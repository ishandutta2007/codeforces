#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 501;
const int INF = 1e18 + 7;
int dp[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);            
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 2; i < n; ++i) {
        ans += i * (i + 1);
    }   
    cout << ans << '\n';
}