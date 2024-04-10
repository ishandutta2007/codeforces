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
        int n, k;
        cin >> n >> k;
        vi a(n);
        rep(i, n) cin >> a[i];

        vi p(k * 2 + 2);
        rep(i, n / 2) {
            int m = a[i] + a[n - i - 1];
            p[m]++, p[m + 1]--;

            int l = min(a[i], a[n - i - 1]) + 1;
            int r = max(a[i], a[n - i - 1]) + k;
            p[l]++, p[r + 1]--;
        }

        int mx = 0, cur = 0;
        rep(i, sz(p)) {
            cur += p[i];
            mx = max(mx, cur);
        }

        cout << n - mx << '\n';
    }

    return 0;
}