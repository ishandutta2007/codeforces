#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = LL(1e18);

LL n, m, k, x, y;
LL mn = INF, mx = -INF;

LL ask(LL r, LL c, LL k) {
    if (n == 1) {
        return (k + m - 1 - c) / m;
    }
    LL tot = (2 * n - 2) * m;
    if (r == 0 || r == n - 1) {
        if (r == n - 1) {
            k -= (n - 1) * m;
        }
        return (k + tot - 1 - c) / tot;
    }
    k -= r * m;
    LL res = (k + tot - 1 - c) / tot;
    k = ::k;
    k -= (2 * n - 2 - r) * m;
    res += (k + tot - 1 - c) / tot;
    return res;
}

int main() {
    cin >> n >> m >> k >> x >> y;
    forn(i, n) {
        mn = min(mn, ask(i, m - 1, k));
        mx = max(mx, ask(i, 0, k));
    }
    cout << mx << ' ' << mn << ' ' << ask(x - 1, y - 1, k) << endl;
    return 0;
}