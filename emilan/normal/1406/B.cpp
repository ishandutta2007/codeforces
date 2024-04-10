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

const ll inf = 1ll << 60;

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    sort(all(a), [](int x, int y) {
        if (y == 0 || (x > 0 && y < 0)) return false;
        else if (x == 0 || (x < 0 && y > 0)) return true;
        return x > y;
    });

    ll ans = -inf;
    for (int i = 0; i <= n - 5; i++) {
        ans = max(ans, accumulate(
            a.begin() + i,
            a.begin() + i + 5,
            1ll,
            multiplies<ll>()
        ));
    }

    cout << ans << '\n';
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