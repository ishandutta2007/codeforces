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
    ll a, b, m;
    cin >> a >> b >> m;

    if (a == b) return void(cout << "1 " << a << '\n');

    for (int k = 2; k <= __lg(b / a) + 5; k++) {
        vt<ll> x(k);
        x[0] = a;
        ll fs = (a + 1) << (k - 2);
        ll ps = a;

        for (int i = 1; i < k; i++) {
            int s = i == k - 1 ? 0 : k - i - 2;

            ll l = 0, r = m;
            while (l + 1 < r) {
                ll mi = (l + r) / 2;

                if (fs + (mi << s) <= b) l = mi;
                else r = mi;
            }

            fs += l << s;
            x[i] = ps + l + 1;
            ps += x[i];
        }

        if (x[k - 1] == b) {
            cout << k;
            for (ll i : x) cout << ' ' << i;
            cout << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}