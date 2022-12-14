#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

int query(int z) {
    cout << "+ " << z << endl;
    int r;
    cin >> r;
    return r;
}

int mod_pos(int x, int m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

void solve() {
    int n;
    cin >> n;

    int q = 0, s = 0;
    auto f = [&](int g) {
        int y = mod_pos(-s - g, n);
        s += y;

        int nq = query(y);
        bool ge = nq == q + 1;
        q = nq;

        return ge;
    };

    int l = 0, r = n;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (f(m)) l = m;
        else r = m;
    }
    cout << "! " << s + l << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}