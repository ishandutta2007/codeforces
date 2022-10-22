#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 57;

int a[MAXN];
bool dp[MAXN][MAXN];

int n, k;

bool ch(int want) {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) dp[i][j] = false;
    }

    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {

            int sum = 0;
            for (int t = i - 1; t >= 0; --t) {
                sum += a[t];
                if ((sum | want) == sum) dp[i][j] |= dp[t][j - 1];
            }

        }
    }

    return dp[n][k];
}

signed main()
{
    //freopen("1.txt", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int curr = 0;
    for (int bt = MAXN - 1; bt >= 0; --bt) {
        if (ch(curr + (1ll << bt))) {
            curr += (1ll << bt);
        }
    }

    cout << curr << '\n';
    return 0;
}