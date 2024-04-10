#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const i64 P = 998244353;

void add(i64 &x, i64 y) {
    (x += y) %= P;
}

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        (x *= x) %= P;
        d /= 2;
    }
    return y;
}

const int maxn = 2100;
i64 scc[maxn], cut[maxn][maxn];
i64 pdeg[maxn], qdeg[maxn];
i64 dp[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    i64 p = 1LL * a * deg(b, -1) % P;
    i64 q = (P + 1 - p) % P;
    pdeg[0] = qdeg[0] = 1;
    forn(i, n) pdeg[i + 1] = pdeg[i] * p % P, qdeg[i + 1] = qdeg[i] * q % P;
    cut[0][0] = 1;
    forn(i, n) forn(j, i + 1) {
        add(cut[i + 1][j + 1], cut[i][j] * qdeg[i - j]);
        add(cut[i + 1][j], cut[i][j] * pdeg[j]);
    }

    forn(i, n + 1) {
        scc[i] = 1;
        for1(k, i - 1) add(scc[i], -scc[k] * cut[i][k]);
    }

    for (int i = 2; i <= n; ++i) {
        i64 q = scc[i];
        for1(j, i - 1) {
            i64 t = scc[j] * cut[i][j] % P;
            add(dp[i], t * (j * (i - j) + j * (j - 1) / 2 + dp[j] + dp[i - j]));
        }
        add(dp[i], q * i * (i - 1) / 2);
        (dp[i] *= deg(1 - q, -1)) %= P;
    }
    i64 ans = dp[n];
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}