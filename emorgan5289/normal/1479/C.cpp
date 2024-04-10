#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l, r; cin >> l >> r;
    vector<array<int, 3>> e;
    for (int i = 2; i <= 32; i++) {
        e.pb({1, i, 1});
        int p = 1;
        for (int j = 1; j < i; j++) {
            if (2*p >= r-l+1) {
                e.pb({1, ++i, l});
                for (int k = i-1; k > 1; k--) {
                    p = 1<<(k-2);
                    if (l+p <= r) e.pb({k, i, l}), l += p;
                }
                cout << "YES\n" << i << " " << e.size() << "\n";
                for (auto [a, b, c] : e)
                    cout << a << " " << b << " " << c << "\n";
                exit(0);
            }
            if (j != 1) e.pb({j, i, p}), p *= 2;
        }
    }
}