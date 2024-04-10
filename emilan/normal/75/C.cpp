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
    int a, b, q;
    cin >> a >> b >> q;
    int g = __gcd(a, b);

    vt<int> div;
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            div.push_back(i);
            if (i * i != g) div.push_back(g / i);
        }
    }
    sort(all(div));

    while (q--) {
        int lo, hi;
        cin >> lo >> hi;

        auto it = upper_bound(all(div), hi);
        if (it == div.begin() || *--it < lo) cout << "-1\n";
        else cout << *it << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}