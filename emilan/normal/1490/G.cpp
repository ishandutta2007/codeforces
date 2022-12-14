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
using pli = pair<ll, int>;

void solve() {
    int n, q;
    cin >> n >> q;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    ll sum = a[0];
    vt<pli> d{{a[0], 0}};
    for (int i = 1; i < n; i++) {
        sum += a[i];
        if (sum > d.back().fi) {
            d.emplace_back(sum, i);
        }
    }

    while (q--) {
        ll x;
        cin >> x;

        auto it = lower_bound(all(d), pli{x, 0});
        if (it != d.end()) {
            cout << it->se;
        } else {
            if (sum <= 0) cout << -1;
            else {
                ll c = (x - d.back().fi + sum - 1) / sum;
                x -= c * sum;
                it = lower_bound(all(d), pli{x, 0});

                cout << c * n + it->se;
            }
        }

        cout << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}