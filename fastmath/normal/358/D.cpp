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
const int N = 3007;
int dp[N][2], a[3][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int t = 0; t < 3; ++t)
        for (int i = 0; i < n; ++i)
            cin >> a[t][i];
    dp[0][0] = a[0][0];
    dp[0][1] = a[1][0];
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + a[(j ^ 1) + k][i + 1]);
            }   
        }   
    }
    cout << dp[n - 1][0] << endl;
}