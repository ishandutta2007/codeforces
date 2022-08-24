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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const i64 P = 1000000000 + 7;
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

const int MAXN = 300000;
i64 fact[MAXN], tcaf[MAXN];

i64 CNK(int a, int b) {
    return fact[a] * tcaf[b] % P * tcaf[a - b] % P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    fact[0] = tcaf[0] = 1;
    for1(i, MAXN - 1) fact[i] = i * fact[i - 1] % P, tcaf[i] = deg(fact[i], -1);
    int H, W, N;
    cin >> H >> W >> N;
    vector<pii> a(N);
    forn(i, N) cin >> a[i].fi >> a[i].se;
    a.pb(mp(H, W));
    sort(all(a));
    vi64 dp(N + 1);
    forn(i, N + 1) {
        dp[i] = CNK(a[i].fi + a[i].se - 2, a[i].fi - 1);
        forn(j, i) {
            if (a[j].fi <= a[i].fi && a[j].se <= a[i].se) {
                dp[i] -= dp[j] * CNK(a[i].fi - a[j].fi + a[i].se - a[j].se, a[i].fi - a[j].fi);
                dp[i] %= P;
            }
        }
    }
    i64 res = dp[N];
    if (res < 0) res += P;
    cout << res << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}