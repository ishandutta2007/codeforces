#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1), q(n + 1);
    for (int i = 1; i <= n; i += 1) {
        cin >> p[i];
        q[p[i]] = i;
    }
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i += 1)
        for (int j = i + 1; j <= n; j += 1)
            s[i] += q[j] < q[i];
    int inf = n * n;
    vector dp(n + 1, vector<int>(1 << k, inf));
    auto mini = [&](int& x, int y) {
        if (y < x) x = y;
    };
    for (int i = 1; i <= n; i += 1) {
        if (i <= k + 1) {
            int& res = dp[i][(1 << k) - (1 << (i - 1))];
            res = s[i];
            for (int j = 1; j < i; j += 1)
                res += q[j] < q[i];
        }
        for (int mask = 0; mask < (1 << k); mask += 1)
            if (dp[i][mask] < inf) {
                for (int j = 0; j < k; j += 1)
                    if ((mask >> j) % 2 == 0) {
                        int nmask = mask | (1 << j);
                        int pres = s[i - j - 1];
                        pres -= q[i] < q[i - j - 1];
                        for (int x = 0; x < k; x += 1) {
                            if (x < j and (mask >> x) % 2 and q[i - x - 1] < q[i - j - 1])
                                pres -= 1;
                            if (x > j and (mask >> x) % 2 == 0 and q[i - x - 1] < q[i - j - 1])
                                pres += 1;
                        }
                        mini(dp[i][nmask], dp[i][mask] + pres);
                    }
                for (int j = i + 1; j <= n and j <= i + k + 1; j += 1) {
                    if (j == i + k + 1) {
                        if (mask == (1 << k) - 1) {
                            int pres = s[j];
                            for (int x = i + 1; x < j; x += 1)
                                pres += q[x] < q[j];
                            mini(dp[j][0], dp[i][mask] + pres);
                        }
                        break;
                    }
                    if ((mask >> (k - (j - i))) == (1 << (j - i)) - 1) {
                        int nmask = ((mask & ((1 << (k - (j - i))) - 1)) << (j - i)) | (1 << (j - i - 1));
                        int pres = s[j];
                        for (int x = 0; x < k; x += 1)
                            if (j - x - 1 >= 1 and (nmask >> x) % 2 == 0)
                                pres += q[j - x - 1] < q[j];
                        mini(dp[j][nmask], dp[i][mask] + pres);
                    }
                }
            }
    }
    cout << dp[n][(1 << k) - 1];
}