#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int la, ra, ta, lb, rb, tb;
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    int x = gcd(ta, tb);
    int mem = (lb - la) / x;
    lb -= mem * x;
    rb -= mem * x;
    int ans = 0;
    for (int i = -100; i <= 100; ++i) {
        int nl = lb + (i * x);
        int nr = rb + (i * x);
        ans = max(ans, max(0ll, min(nr, ra) - max(nl, la) + 1));
    }
    cout << ans << '\n';
}