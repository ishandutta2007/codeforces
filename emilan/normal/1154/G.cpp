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

const int maxk = 1e7 + 1;
const ll inf = 1ll << 60;

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> f(maxk);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[x].push_back(i);
    }

    ll mx = inf;
    vt<int> mx_pair;
    for (int i = 1; i < maxk; i++) {
        vt<pii> cur;
        for (int j = i; j < maxk && sz(cur) < 2; j += i) {
            for (int k = 0; k < sz(f[j]) && sz(cur) < 2; k++) {
                cur.emplace_back(j, f[j][k]);
            }
        }

        if (sz(cur) == 2) {
            ll lcm = ll(cur[0].fi) * cur[1].fi / i;
            if (lcm < mx) {
                mx = lcm;
                mx_pair = {cur[0].se, cur[1].se};
            }
        }
    }

    sort(all(mx_pair));
    for (int i : mx_pair) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}