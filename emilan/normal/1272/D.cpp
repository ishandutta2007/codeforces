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

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    int mx = 1, cur = 1, seg = 1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i]) {
            cur++, seg++;
            mx = max(mx, cur);
        } else {
            if (i > 1 && a[i - 2] < a[i] || i < n - 1 && a[i - 1] < a[i + 1]) {
                cur = seg;
            } else cur = 1;
            seg = 1;
        }
    }

    cout << mx;

    return 0;
}