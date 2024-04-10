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

const int maxn = 701;
const int P = 1000000000 + 7;
i64 cnk[maxn][maxn], dg[11][maxn];
i64 dp1[maxn][10], dp2[maxn][10];

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        (x *= x) %= P;
        d /= 2;
    }
    return y;
}

void add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

i64 eff(int j, int k, int s, int d) {
    i64 res = deg(100 - 9 * d, s) * dg[10][j + k] - deg(91 - 9 * d, s) * dg[10][k];
    res %= P;
    res *= d;
    res %= P;
    if (res < 0) res += P;
    res *= deg(9, -1);
    res %= P;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cnk[0][0] = 1;
    for1(i, maxn - 1) {
        cnk[i][0] = 1;
        for1(j, i) forn(k, 2) (cnk[i][j] += cnk[i - 1][j - k]) %= P;
    }

    forn(d, 11) {
        dg[d][0] = 1;
        for1(i, maxn - 1) dg[d][i] = d * dg[d][i - 1] % P;
    }

    string s;
    cin >> s;
    int l = s.size();
/*    forn(s, l) forn(d, 10) {
        forn(nj, s + 1) forn(nk, s - nj + 1) {
            dp1[s][d] += cnk[s][nj] * cnk[s - nj][nk] % P * dg[d][s - nj - nk] % P * dg[9 - d][nk] % P * dg[10][nj + nk];
            dp1[s][d] %= P;

            dp2[s][d] += cnk[s][nj] * cnk[s - nj][nk] % P * dg[d][s - nj - nk] % P * dg[9 - d][nk] % P * dg[10][nk];
            dp2[s][d] %= P;
        }        

        assert( dp1[s][d] == deg(100 - 9 * d, s));
        assert(dp2[s][d] == deg(91 - 9 * d, s));
    }*/

    i64 ans = 0;
    for1(d, 9) {
        int j = 0, k = 0;
        forn(i, l) {    
            forn(dd, s[i] - '0') (ans += eff(j + int(dd == d), k + int(dd > d), l - i - 1, d)) %= P;
            j += int(s[i] - '0' == d);
            k += int(s[i] - '0' > d);
        }
        (ans += eff(j, k, 0, d)) %= P;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}