#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vt<vt<int>> a(n, vt<int>(m));
    for (auto &b : a) {
        for (int &x : b) cin >> x;
    }

    ll ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < (m + 1) / 2; j++) {
            set<pii> p{
                {i, j},
                {i, m - j - 1},
                {n - i - 1, j},
                {n - i - 1, m - j - 1}
            };
            vt<int> t;
            for (pii idx : p) {
                t.push_back(a[idx.fi][idx.se]);
            }
            sort(all(t));

            for (pii idx : p) {
                ans += abs(t[sz(t) / 2] - a[idx.fi][idx.se]);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}