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
    int p, f, ns, nw, s, w;
    cin >> p >> f >> ns >> nw >> s >> w;
    if (s > w) {
        swap(ns, nw);
        swap(s, w);
    }

    int ans = 0;
    for (int i = 0; i <= min(nw, p / w); i++) {
        int cans = i;
        int cp = p - i * w;

        int p_hold_s = min(ns, cp / s);
        cans += p_hold_s;

        int f_hold_s = min(ns - p_hold_s, f / s);
        cans += f_hold_s;
        int cf = f - f_hold_s * s;

        cans += min(nw - i, cf / w);

        ans = max(cans, ans);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}