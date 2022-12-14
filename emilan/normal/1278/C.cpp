#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        cin >> n;
        vi l(n), r(n);
        for (int& i : l) cin >> i;
        for (int& i : r) cin >> i;

        int tot = count(all(l), 1) + count(all(r), 1) -
                  count(all(l), 2) - count(all(r), 2);

        map<int, int> p{{0, 0}};
        int cur = 0;
        rep(i, n) {
            cur += r[i] == 1 ? 1 : -1;
            if (!p.count(cur)) p[cur] = i + 1;
        }

        int mn = 1 << 30;
        for (int i = n; i >= 0; i--) {
            if (i != n) tot -= l[i] == 1 ? 1 : -1;
            if (p.count(tot)) mn = min(mn, n - i + p[tot]);
        }

        cout << mn << '\n';
    }
}