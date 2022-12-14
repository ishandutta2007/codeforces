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

    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];

    ll l = 1, r = 1ll << 62;
    while (l < r) {
        ll mi = (l + r) / 2;
        int idx = n - 1, p = 0;
        vi t(a);
        while (p != m) {
            while (idx != -1 && t[idx] == 0) idx--;
            if (idx == -1) break;

            p++;
            ll step = mi - idx - 1;

            while (idx != -1 && step >= t[idx]) {
                step -= t[idx];
                idx--;
            }
            if (idx != -1) t[idx] -= step;
        }
        
        if (idx == -1) r = mi;
        else l = mi + 1;
    }

    cout << l;

    return 0;
}