#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const i64 P = 1000000000 + 7;

void add(i64 &x, i64 y) {
    x += y; x %= P;
}

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) y *= x, y %= P;
        x *= x, x %= P;
        d /= 2;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 N, K, L;
    cin >> N >> L >> K;
    vector<pii> a(N);
    forn(i, N) cin >> a[i].fi, a[i].se = i;
    sort(all(a));
    i64 W = L / N % P;
    vi64 dp(N, 1);
    i64 cw = 1, cw1 = 1;
    i64 ans = 0;
    for1(x, K) {
        forn(i, N) {
            if (x <= L / N) ans += (W - x + 1) * dp[i]; ans %= P;
            if (a[i].se < L % N && x - 1 <= L / N) ans += dp[i]; ans %= P;
        }
        vi64 ndp(N);
        int l = 0;
        i64 s = 0;
        while (l < N) {
            int r = l;
            while (r < N && a[r].fi == a[l].fi) ++r;
            for (int i = l; i < r; ++i) add(s, dp[i]);
            for (int i = l; i < r; ++i) ndp[i] = s;
            l = r;
        }
        dp = ndp;
    }
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}