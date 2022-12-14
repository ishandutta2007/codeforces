#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;

const int N = 500;
bitset<N> dp[N + 1];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    ll x_sum = 0, y_sum = 0;
    for (auto &[x, y] : a) {
        cin >> x >> y;
        x_sum += x;
        y_sum += y;
    }

    ll ans = x_sum / k + y_sum / k;
    x_sum %= k;
    y_sum %= k;

    dp[0][x_sum] = true;
    for (int i = 0; i < n; i++) {
        auto &[x, y] = a[i];
        for (int r = 1; r <= min(x, k - 1); r++) if (r + y >= k) {
            for (int u = 0; u < k; u++) if (dp[i][u]) {
                int v = u - r < 0 ? u - r + k : u - r;
                dp[i + 1][v] = 1;
            }
        }

        dp[i + 1] |= dp[i];
    }

    for (int i = 0; i <= x_sum + y_sum - k; i++) {
        if (dp[n][i]) {
            ans++;
            break;
        }
    }

    cout << ans;
}