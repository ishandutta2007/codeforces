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
    vt<ll> v(n);
    for (ll &x : v) cin >> x;
    sort(rall(v));
    int x, a, y, b;
    ll k;
    cin >> x >> a >> y >> b >> k;

    if (x > y) {
        swap(x, y);
        swap(a, b);
    }

    vt<ll> p(n + 1);
    partial_sum(all(v), p.begin() + 1);

    int ac = 0, bc = 0, cc = 0;
    for (int i = 1; i <= n; i++) {
        if (i % a == 0 && i % b == 0) cc++;
        else if (i % a == 0) ac++;
        else if (i % b == 0) bc++;

        ll have = (x + y) * p[cc]
            + y * (p[bc + cc] - p[cc])
            + x * (p[ac + bc + cc] - p[bc + cc]);
        if (have >= k * 100) return void(cout << i << '\n');
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}