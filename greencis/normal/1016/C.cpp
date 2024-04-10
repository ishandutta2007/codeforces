#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
ll a[2][300105];
ll sum[2][300105];  /// a[1] + a[2] + ...
ll pref[2][300105]; /// a[1] * 1 + a[2] * 2 + ...
ll suff[2][300105]; /// a[n] * 1 + a[n - 1] * 2 + ...

ll calc_rest(int row, int col) {
    if (row == 0) {
        ll upper_norm = pref[0][n] - pref[0][col - 1] + (sum[0][n] - sum[0][col - 1]) * (col - 1);
        ll lower_norm = suff[1][col] + (sum[1][n] - sum[1][col - 1]) * (n + col - 1);
        return upper_norm + lower_norm;
    } else {
        ll upper_norm = suff[0][col] + (sum[0][n] - sum[0][col - 1]) * (n + col - 1);
        ll lower_norm = pref[1][n] - pref[1][col - 1] + (sum[1][n] - sum[1][col - 1]) * (col - 1);
        return upper_norm + lower_norm;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int z = 0; z < 2; ++z) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[z][i];
            sum[z][i] = sum[z][i - 1] + a[z][i];
            pref[z][i] = pref[z][i - 1] + a[z][i] * i;
        }
        for (int i = n; i >= 1; --i) {
            suff[z][i] = suff[z][i + 1] + a[z][i] * (n - i + 1);
        }
    }
    ll ans = 0;
    ll cur = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, cur + calc_rest(1 - i % 2, i));
        cur += a[1 - i % 2][i] * (2 * i - 1) + a[i % 2][i] * (2 * i);
    }
    ans = max(ans, cur);
    cout << ans - sum[0][n] - sum[1][n] << endl;
}