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

    int n, m, x, k, y;
    cin >> n >> m >> x >> k >> y;
    vi a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    int i = n - 1, cur = 0, prev = 0;
    ll cost = 0;

    auto f = [&](vi& t) {
        if (!t.empty()) {
            int mx = *max_element(all(t));
            int len = sz(t);
            
            if (mx > cur && mx > prev) {
                if (k > len) {
                    cout << -1;
                    exit(0);
                }

                len -= k;
                cost += x;
            }

            cost += (ll)y * (len % k);
            len -= len % k;
            if (x / k < y) cost += (ll)x * (len / k);
            else cost += (ll)y * len;
        }
    };

    for (int j = m - 1; j >= 0; j--) {
        while (i >= 0 && a[i] != b[j]) i--;
        if (i < 0) {
            cout << -1;
            return 0;
        }

        vi t(a.begin() + i + 1, a.end());
        cur = a[i];
        f(t);

        a.erase(a.begin() + i, a.end());
        prev = a[i--];
    }

    cur = 0;
    f(a);

    cout << cost;

    return 0;
}