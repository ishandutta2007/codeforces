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

const int maxd = 11, maxn = 1111;
i64 P;
i64 dp[maxn][maxn][maxd], t[maxn];
i64 fact[maxn], tcaf[maxn];

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

void add(i64 &x, i64 y) {
    x += y; x %= P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, d;
    cin >> n >> d >> P;
    if (n <= 2) {
        cout << 1 << '\n';
        return 0;
    }
    fact[0] = 1;
    for1(i, n) fact[i] = fact[i - 1] * i % P;
    forn(i, n + 1) tcaf[i] = deg(fact[i], -1);

    t[1] = 1;
    //dp[1][1][1] = 1;
    dp[0][0][0] = 1;
    for1(i, n) {
        forn(k, d + 1) forn(q, d - k + 1) {
            i64 w = 1;
            forn(r, q) w *= t[i] + r, w %= P;
            w *= tcaf[q]; w %= P;
            forn(s, n + 1) {
                int ss = s + q * i;
                if (ss > n) break;
                if (!dp[s][i - 1][k]) continue;
                add(dp[ss][i][k + q], dp[s][i - 1][k] * w);
            }
        }
        t[i + 1] = dp[i][i][d - 1];
//        cerr << i + 1 << ' ' << t[i + 1] << '\n';
    }

    i64 ans = dp[n - 1][(n - 1) / 2][d];
    if (n % 2 == 0) {
        i64 w = dp[n / 2 - 1][n / 2 - 1][d - 1];
//        cerr << w << '\n';
        add(ans, w * (w + 1) % P * (P + 1) / 2);
    }
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}