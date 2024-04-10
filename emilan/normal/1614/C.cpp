#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int K = 30;
const ll MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, K>> diff(n + 1);
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        x = ~x;

        for (int k = 0; k < K; k++) if (x >> k & 1) {
            diff[l][k]++;
            diff[r][k]--;
        }
    }

    array<int, K> ng_cur{};
    vector<array<ll, K>> zero(n + 1), one(n + 1);
    for (int i = 0; i < n; i++) {
        int or_val = 0;
        for (int k = 0; k < K; k++) {
            ng_cur[k] += diff[i][k];
            if (ng_cur[k] == 0) or_val |= 1 << k;
        }

        for (int k = 0; k < K; k++) {
            if (or_val >> k & 1) {
                zero[i + 1][k] = (zero[i][k] + one[i][k]) % MOD;
                one[i + 1][k] = (zero[i][k] + one[i][k] + 1) % MOD;
            } else {
                zero[i + 1][k] = (2 * zero[i][k] + 1) % MOD;
                one[i + 1][k] = 2 * one[i][k] % MOD;
            }
        }
    }

    ll ans = 0;
    for (int k = 0; k < K; k++) {
        ans = (ans + (one[n][k] << k)) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}