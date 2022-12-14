#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

pii solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int x = a + 1; x <= c; x++) {
        ll g = gcd(x, ll(a) * b);
        ll y = ll(a) * b / g;
        y *= b / y + 1;
        if (y <= d) return {x, int(y)};
    }
    return {-1, -1};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        auto [x, y] = solve();
        cout << x << ' ' << y << '\n';
    }
}