#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

bool check(LL st, LL d, LL n, LL v)
{
    LL w = v - st;
    if (w < 0 || w % d) return false;
    w /= d;
    return w < n;
}

LL work(LL d, LL m)
{
    LL w = m / d;
    return w * w % mod;
}

void solve()
{
    int b, q, y;
    int c, r, z;
    cin >> b >> q >> y; // b + k*q
    cin >> c >> r >> z;// c + k*r

    LL st = c, ed = c + 1LL * (z - 1) * r;
    if (!check(b, q, y, st) || !check(b, q, y, ed)) {
        cout << 0 << endl;
        return;
    }

    if (r % q != 0) {
        cout << 0 << endl;
        return;
    }

    if (!check(b, q, y, st - r) || !check(b, q, y, ed + r)) {
        cout << -1 << endl;
        return;
    }

    LL x = r / q;
    LL gg = __gcd(x, 1LL * q);
    while (gg > 1) {
        x *= gg;
        q /= gg;
        gg = __gcd(x, 1LL * q);
    }
    LL ans = 0;
    for (int i = 1; i * i <= q; i++) {
        if (q % i == 0) {
            ans += work(x * i, r);

            if (i * i != q) {
                ans += work(q / i * x, r);
            }
        }
    }
    cout << ans % mod << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Pt = 1;
    cin >> Pt;
    while (Pt--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}