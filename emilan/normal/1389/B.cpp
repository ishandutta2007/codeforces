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
        int n, k, z;
        cin >> n >> k >> z;
        vi a(n);
        rep(i, n) cin >> a[i];
        
        int cur = accumulate(a.begin(), a.begin() + k + 1, 0);
        int mx = cur;
        rep(i, z) {
            if (k - i * 2 < 2) break;
            cur -= a[k - i * 2] + a[k - i * 2 - 1];
            int mx2 = 0;
            rep(j, k - i * 2 - 1) mx2 = max(mx2, a[j] + a[j + 1]);
            mx = max(mx, cur + mx2 * (i + 1));
        }

        cout << mx << '\n';
    }

    return 0;
}