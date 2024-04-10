#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;

const int K = 30;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    array<vector<int>, K> pos;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < K; k++) if (a[i] >= 1 << k) {
            pos[k].push_back(i);
        }
    }

    vector<ll> pre(n + 1);
    partial_sum(all(a), pre.begin() + 1);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int r = 1; i - r >= 0 && i + r + j < n;) {
                ll sum = pre[i + r + j] - pre[i - r + 1];
                if ((a[i - r] ^ a[i + r + j]) == sum) ans++;

                sum += a[i - r] + a[i + r + j];
                if (sum >= 1 << K) break;
                int k = __lg(sum);

                int nr = n;
                auto it_l = lower_bound(all(pos[k]), i - r);
                if (it_l != pos[k].begin()) {
                    nr = min(nr, i - *prev(it_l));
                }
                auto it_r = upper_bound(all(pos[k]), i + r + j);
                if (it_r != pos[k].end()) {
                    nr = min(nr, *it_r - i - j);
                }
                r = nr;
            }
        }
    }

    cout << ans << "\n";
}