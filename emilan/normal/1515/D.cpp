#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> fl(n + 1), fr(n + 1);
    int d = 0;
    for (int i = 0; i < l; i++) {
        int c;
        cin >> c;
        fl[c]++;
    }
    for (int i = 0; i < r; i++) {
        int c;
        cin >> c;
        if (fl[c]) fl[c]--, d++;
        else fr[c]++;
    }
    l -= d, r -= d;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (l > r) {
            int c = fl[i] / 2;
            if (l - c * 2 <= r) {
                ans += (l - r) / 2;
                l = r;
            } else {
                ans += c;
                l -= c * 2;
            }
        } else if (l < r) {
            int c = fr[i] / 2;
            if (r - c * 2 <= l) {
                ans += (r - l) / 2;
                r = l;
            } else {
                ans += c;
                r -= c * 2;
            }
        }
    }
    ans += min(l, r);
    ans += abs(l - r);

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