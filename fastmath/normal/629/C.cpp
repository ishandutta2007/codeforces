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

const int N = 5007, MOD = 1000 * 1000 * 1000 + 7;
int dp[N][N];

int mod(int n) {
    n %= MOD;
    if (n < 0)
        return n + MOD;
    else
        return n;
}

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    const int INF = 5e18;
    int mn = 0, mx = 0;
    int cur = 0;
    for (char c : s) {
        if (c == '(') {
            ++cur;
        }   
        else {
            --cur;
        }   
        mn = min(mn, cur);
        mx = max(mx, cur);
    }   

    dp[0][0] = 1;
    for (int i = 0; i + 1 < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i + 1][j + 1] = mod(dp[i + 1][j + 1] + dp[i][j]);
            if (j)
                dp[i + 1][j - 1] = mod(dp[i + 1][j - 1] + dp[i][j]);
        }   
    }   

    int ans = 0;
    for (int l = 0; l <= n - m; ++l) {
        int r = n - m - l;

        for (int bl = 0; bl <= l; ++bl) {
            if (bl + cur < 0)
                continue;
            int br = bl + cur;

            if (bl + mn >= 0 && bl < N && br < N) {
                ans = mod(ans + dp[l][bl] * dp[r][br]);
            }
        }   

    }   
    cout << ans << endl;
}