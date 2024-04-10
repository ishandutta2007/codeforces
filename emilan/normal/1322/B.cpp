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

    int n;
    cin >> n;
    vi a(n);
    for (int& i : a) cin >> i;

    int ans = 0;
    if (~n & 1) {
        rep(i, 24) {
            rep(j, n) if (a[j] >> i & 1) ans ^= 1 << i;
        }
    }

    for (int i = 1; i <= 24; i++) {
        vi t(n);
        rep(j, n) t[j] = a[j] & ((1 << i) - 1);
        sort(all(t));

        rep(j, n - 1) {
            if (t[j] + t.back() < 1 << i) continue;

            int l = j + 1, r = n - 1;
            while (l < r) {
                int mi = (l + r) / 2;
                if (t[j] + t[mi] < 1 << i) l = mi + 1;
                else r = mi;
            }

            ans ^= ((n - l) & 1) << i;
        }
    }

    cout << ans;
}