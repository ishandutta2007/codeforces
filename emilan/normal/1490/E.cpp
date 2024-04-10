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

void solve() {
    int n;
    cin >> n;
    vt<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    sort(all(a));

    int p = 0;
    ll cur = a[0].fi;
    for (int i = 1; i < n; i++) {
        if (cur < a[i].fi) p = i;
        cur += a[i].fi;
    }

    vt<int> ans;
    for (int i = p; i < n; i++) {
        ans.push_back(a[i].se);
    }
    sort(all(ans));

    cout << sz(ans) << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}