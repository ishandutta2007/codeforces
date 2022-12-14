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

const int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vt<pii> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].fi;
        p[i].se = i;
    }
    sort(rall(p));

    ll val = 0;
    for (int i = 0; i < k; i++) {
        val += p[i].fi;
    }

    vt<int> a;
    for (int i = 0; i < k; i++) {
        a.push_back(p[i].se);
    }
    sort(all(a));

    ll cnt = 1;
    for (int i = 1; i < k; i++) {
        cnt = cnt * (a[i] - a[i - 1]) % mod;
    }

    cout << val << ' ' << cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}