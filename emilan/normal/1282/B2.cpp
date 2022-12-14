#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, p, k;
        cin >> n >> p >> k;
        vi a(n);
        rep(i, n) cin >> a[i];
        sort(all(a));

        int l = 0, r = n / k;
        while (l < r) {
            int mi = (l + r + 1) / 2;
            int c = 0;

            for (int i = mi * k - 1; i >= 0; i -= k) {
                c += a[i];
            }

            if (c > p) r = mi - 1;
            else l = mi;
        }

        int l1 = 0, r1 = min(n - l * k, k - 1);
        while (l1 < r1) {
            int mi = (l1 + r1 + 1) / 2;
            int c = 0;

            int i = l * k + mi - 1;
            while (i >= 0) {
                c += a[i];
                if (i - k >= -1) i -= k;
                else i--;
            }

            if (c > p) r1 = mi - 1;
            else l1 = mi;
        }

        cout << l * k + l1 << '\n';
    }

    return 0;
}