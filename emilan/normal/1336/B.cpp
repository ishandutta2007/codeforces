#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

void solve(int tc) {
    vt<int> n(3);
    for (int &i : n) cin >> i;
    vt<vt<int>> a(3);
    for (int i = 0; i < 3; i++) {
        a[i].resize(n[i]);
        for (int &j : a[i]) cin >> j;
        sort(all(a[i]));
    }

    vt<int> p(3);
    iota(all(p), 0);

    ll ans = 1ll << 62;
    do {
        for (int i = 0; i < n[p[0]]; i++) {
            int x = a[p[0]][i];
            auto it1 = upper_bound(all(a[p[1]]), x);
            auto it2 = lower_bound(all(a[p[2]]), x);
            if (it1 == a[p[1]].begin() || it2 == a[p[2]].end()) continue;

            int y = *--it1, z = *it2;
            auto sq = [](int _x, int _y) {
                return (ll)(_x - _y) * (_x - _y);
            };
            ans = min(ans, sq(x, y) + sq(x, z) + sq(y, z));
        }
    } while (next_permutation(all(p)));
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}