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

const int inf = 1e9;

void solve() {
    vt<int> a(6);
    for (int &x : a) cin >> x;
    sort(all(a));
    int n;
    cin >> n;
    vt<int> b(n);
    for (int &x : b) cin >> x;
    sort(all(b));

    auto f = [&](int s) {
        vt<pii> choice(n, {-inf, inf});
        int base = b[0] - a[s];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                int cur = b[i] - a[j] - base;
                if (cur <= 0) choice[i].fi = max(choice[i].fi, cur);
                if (cur >= 0) choice[i].se = min(choice[i].se, cur);
            }
        }

        sort(all(choice));
        int ans = -choice[0].fi, hi = 0;
        for (int i = 1; i < n; i++) {
            hi = max(hi, choice[i - 1].se);
            ans = min(ans, hi - choice[i].fi);
        }
        ans = min(ans, hi);

        return ans;
    };

    int ans = inf;
    for (int i = 0; i < 6; i++) ans = min(ans, f(i));
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}