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

void solve(int tc) {
    ll a, b;
    cin >> a >> b;

    ll a1 = a, b1 = b;
    while (~a1 & 1) a1 >>= 1;
    while (~b1 & 1) b1 >>= 1;
    if (a1 != b1) return void(cout << "-1\n");

    cout << (abs(__builtin_clzll(a) - __builtin_clzll(b)) + 2) / 3 << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case #" << tc << ": ";
        solve(tc);
    }
}