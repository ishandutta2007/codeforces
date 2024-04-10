#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;



int main() {
    ios_base::sync_with_stdio(false);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        ll n, l, r;
        cin >> n >> l >> r;
        ll idx = 1;
        for (int i = 1; i <= n - 1; ++i) {
            ll lo = idx, hi = idx + 2 * (n - i) - 1;
            for (ll j = max(l, lo); j <= min(r, hi); ++j) {
                ll cur = j - idx;
                if (cur % 2 == 0) cout << i << ' ';
                else cout << i + 1 + cur / 2 << ' ';
            }
            idx = hi + 1;
        }
        if (l <= idx && idx <= r) cout << "1 "; ++idx;
        cout << "\n";
    }
}