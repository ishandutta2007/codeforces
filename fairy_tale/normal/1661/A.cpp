#include<bits/stdc++.h>
#define fi first
#define se second
#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int a[maxn], b[maxn];
LL dp[maxn][2];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    dp[0][0] = dp[0][1] = 0;
    n--;
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = min(dp[i][0] + abs(a[i + 1] - a[i]) + abs(b[i + 1] - b[i]), dp[i][1] + abs(a[i + 1] - b[i]) + abs(b[i + 1] - a[i]));
        dp[i + 1][1] = min(dp[i][0] + abs(b[i + 1] - a[i]) + abs(a[i + 1] - b[i]), dp[i][1] + abs(b[i + 1] - b[i]) + abs(a[i + 1] - a[i]));
    }

    cout << min(dp[n][0], dp[n][1]) << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}