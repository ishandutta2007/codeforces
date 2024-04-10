#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 2e6+7;
int dp[N][2];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    const int MOD = 1000 * 1000 * 1000 + 7;

    dp[3][1] = 1;
    dp[4][0] = dp[4][1] = 1;
    for (int i = 5; i < N; ++i) {
        dp[i][0] = (2 * dp[i-2][1] + dp[i-1][1])%MOD;
        dp[i][1] = dp[i][0];
        if (i % 3 == 0)
            dp[i][1] = (dp[i][1]+1)%MOD;
    }   

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][1]*4)%MOD << endl;
    }
}