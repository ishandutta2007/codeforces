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
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, k, l;
        cin >> n >> k >> l;
        vi a(n);
        rep(i, n) cin >> a[i];

        int t = k;
        bool ok = true;
        rep(i, n) {
            if (a[i] + k <= l) t = k;

            if ((t < 0 && a[i] - t > l) || a[i] > l) {
                ok = false;
                break;
            } else if (t > 0) t = min(t, l - a[i]);
            if (t == -k) t = k;
            t--;
        }

        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}