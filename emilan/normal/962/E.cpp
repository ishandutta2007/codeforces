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

const ll nil = 1ll << 60;

void solve() {
    int n;
    cin >> n;

    vt<ll> b, r;
    ll p = nil, ans = 0;
    while (n--) {
        int x;
        char c;
        cin >> x >> c;

        if (c == 'B') b.push_back(x);
        else if (c == 'R') r.push_back(x);
        else {
            if (p == nil) {
                if (!b.empty()) ans += x - b[0];
                if (!r.empty()) ans += x - r[0];
            } else {
                ll b_max_dist = x - b.back();
                for (int i = 1; i < sz(b); i++) {
                    b_max_dist = max(b_max_dist, b[i] - b[i - 1]);
                }

                ll r_max_dist = x - r.back();
                for (int i = 1; i < sz(r); i++) {
                    r_max_dist = max(r_max_dist, r[i] - r[i - 1]);
                }

                ans += min(
                    3 * (x - p) - b_max_dist - r_max_dist,
                    2 * (x - p)
                );
            }

            p = x;
            b = r = vt<ll>{p};
        }
    }

    if (!b.empty()) ans += b.back() - b[0];
    if (!r.empty()) ans += r.back() - r[0];

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}