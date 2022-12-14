#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <class T> using p = pair<T, T>;
template <class T> using vt = vector<T>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define pb          push_back
#define eb          emplace_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, d, m;
    cin >> n >> d >> m;
    vt<int> a(n);
    for (int& i : a) cin >> i;
    sort(all(a));

    auto low = upper_bound(all(a), m);
    int r = distance(a.begin(), low);
    int l = r;
    ll ps = 0;
    while (l > 0 && r - l < d) {
        ps += a[--l];
    }

    ll fun = 0;
    int xr = n - 1;
    if (r != n) {
        fun += a[xr];
        xr--;
        n--;
    }
    while (n) {
        if (a[xr] > m && n > d && a[xr] > ps) {
            n -= d;
            fun += a[xr--];
        } else if (r > 0) {
            fun += a[--r];
            ps -= a[r];
            if (l > 0) ps += a[--l];
        }
        n--;
    }

    cout << fun;
}