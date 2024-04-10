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

const int maxn = 311;
const i64 P = 1000000000 + 7;
i64 dp[2][maxn];
i64 fact[maxn], tcaf[maxn];
i64 spots[maxn][maxn];

void add(i64 &x, i64 y) {
    x += y; x %= P;
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

i64 cnk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
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
    for1(i, maxn - 1) fact[i] = i * fact[i - 1] % P, tcaf[i] = deg(fact[i], -1);

    map<int, int> cnt;
    int n;
    cin >> n;
    forn(i, n) {
        int x;
        cin >> x;
        for (int p = 2; p * p <= x; ++p) while (x % (p * p) == 0) x /= p * p;
        ++cnt[x];
    }

    spots[0][0] = 1;
    forn(i, n) forn(j, i + 1) {
        add(spots[i + 1][j], spots[i][j] * (i + j));
        add(spots[i + 1][j + 1], spots[i][j]);
    }

    dp[0][1] = 1;
    int total = 1;
    for (auto w: cnt) {
        int m = w.se;
        forn(dif, total + 1) {
            int same = total - dif;
            forn(ndif, dif + 1) forn(nsame, same + 1) {
                if (ndif + nsame > m) break;
                int new_dif = dif + ndif + 2 * nsame;
                i64 ways = dp[0][dif];
                (ways *= cnk(dif, ndif)) %= P;
                (ways *= cnk(same, nsame)) %= P;
                (ways *= fact[ndif + nsame]) %= P;
                (ways *= spots[m][ndif + nsame]) %= P;
                add(dp[1][new_dif], ways);
            }
        }
        forn(i, total + 1) dp[0][i] = 0;
        total += m;
        forn(i, total + 1) dp[0][i] = dp[1][i], dp[1][i] = 0;
    }
    cout << dp[0][total] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}