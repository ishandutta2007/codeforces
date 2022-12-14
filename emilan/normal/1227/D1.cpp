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
    vii a(n);
    rep(i, n) cin >> a[i].fi, a[i].se = i;
    int m;
    cin >> m;

    sort(all(a), [](ii& x, ii& y) {
            if (x.fi > y.fi) return true;
            else if (x.fi == y.fi && x.se < y.se) return true;
            return false;
    });

    while (m--) {
        int k, p;
        cin >> k >> p;

        map<int, int> b;
        rep(i, k) b[a[i].se] = a[i].fi;

        auto it = b.begin();
        while (--p) it++;
        cout << it->se << '\n';
    }

    return 0;
}