#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> a(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    set <pair <int, int>> have;
    for (int i = 0; i < n; ++i) have.insert({c[i], i});
    for (int i = 0; i < m; ++i) {
        int t, d;
        cin >> t >> d;
        --t;
        ll cur = 0;
        int can = min(d, a[t]);
        a[t] -= can;
        d -= can;
        cur += (ll)can * c[t];
        while (d > 0 && !have.empty()) {
            auto p = (*have.begin());
            have.erase(have.begin());
            int cr = min(a[p.second], d);
            d -= cr;
            a[p.second] -= cr;
            cur += (ll)cr * p.first;
            if (a[p.second]) {
                have.insert({c[p.second], p.second});
            }
        }
        if (d != 0) cur = 0;
        cout << cur << '\n';
    }
}