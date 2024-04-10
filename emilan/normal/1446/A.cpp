#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

void solve() {
    int n;
    ll w;
    cin >> n >> w;
    vt<pli> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    sort(all(a));

    auto it = lower_bound(all(a), pli{(w + 1) / 2, 0});
    int idx = it - a.begin();
    if (idx != n && a[idx].fi <= w)
        return void(cout << "1\n" << a[idx].se << '\n');

    vt<int> ans;
    w = (w + 1) / 2;
    for (int i = 0; i < idx; i++) {
        ans.push_back(a[i].se);
        w -= a[i].fi;
        if (w <= 0) {
            cout << sz(ans) << '\n';
            for (int x : ans) cout << x << ' ';
            cout << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}