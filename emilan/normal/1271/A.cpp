#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int m1 = min(a, d);
    int mx = m1 * e + min({b, c, d - m1}) * f;
    int m2 = min({b, c, d});
    mx = max(mx, min(a, d - m2) * e + m2 * f);
    cout << mx;
}