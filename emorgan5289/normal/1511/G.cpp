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
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const int N = 2e5+5, B = 10;
ll f[N], large[N], small[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        f[a] ^= 1;
    }
    for (int i = 0; i <= m; i++) {
        for (int j = i; j < min(m+1, i+(1<<B)); j++) {
            large[i] ^= f[j];
            if (f[j]) small[i] ^= j-i;
        }
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        ll ans = 0;
        for (int i = 0; l+(i<<B) <= r; i++) {
            if (l+((i+1)<<B) <= r) {
                if (large[l+(i<<B)])
                    ans ^= (i<<B);
                ans ^= small[l+(i<<B)];
            } else {
                for (int j = l+(i<<B); j <= r; j++)
                    if (f[j]) ans ^= (j-l);
            }
        }
        cout << (ans ? 'A' : 'B');
    }
    cout << "\n";
}