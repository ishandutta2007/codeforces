#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int h, c, t;
        cin >> h >> c >> t;
        h -= c, t -= c;

        int l = 1, r = 1 << 20;
        while (l < r) {
            int mi = (l + r) / 2;
            if (t * (mi * 2 + 1ll) / (mi + 1) >= h) r = mi;
            else l = mi + 1;
        }

        ll d1 = (2 * l - 1ll) * (2 * l + 1ll) * abs(h - 2 * t);
        ll d2 = (2 * l + 1ll) * 2 * abs((ll)l * h - (2 * l - 1ll) * t);
        ll d3 = (2 * l - 1ll) * 2 * abs((l + 1ll) * h - (2 * l + 1ll) * t);
        if (d1 <= d2 && d1 <= d3) cout << 2;
        else if (d2 <= d3) cout << 2 * l - 1;
        else cout << 2 * l + 1;
        cout << '\n';
    }

    return 0;
}