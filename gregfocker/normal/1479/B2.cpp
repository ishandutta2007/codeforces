#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 1e5 + 7;
const int INF = (int) 1e9;
int n, a[N], dp[N], b[N], lol[N];

/// dp[i] = col(i - 1) != col(i)

int sb(int l, int r) {
        assert(l <= r + 1);
        return b[r] - b[l - 1];
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

      ///  freopen ("input", "r", stdin);


        cin >> n;
        for (int i = 1; i <= n; i++)
                cin >> a[i];
        for (int i = 1; i <= n; i++) {
                dp[i] = INF;
                lol[i] = INF;
                b[i] = b[i - 1] + (a[i] != a[i - 1]);
        }
        int kek = INF;
        for (int i = 1; i <= n; i++) {
                dp[i] = sb(2, i) - b[i - 1];
                /// col(i - 1) != col(i)
                dp[i] = min(dp[i], kek);
                dp[i] = min(dp[i], lol[a[i]] - 1);
                dp[i] += b[i - 1];
                kek = min(kek, dp[i] - b[i] + 1);
                lol[a[i - 1]] = min(lol[a[i - 1]], dp[i] - b[i] + 1);
        }

        int ret = INF;
        for (int i = 1; i <= n; i++) {
                int cost = dp[i] + sb(i + 1, n);
                ret = min(ret, cost);
        }
        ret += 1;
        if (ret > n) {
                ret = n;
        }
        cout << ret << "\n";
}