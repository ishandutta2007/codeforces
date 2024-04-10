#include <iostream>
#include <tuple>
#include <sstream>
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
typedef pair<i64, i64> pi64;
typedef double ld;
typedef unsigned int uint;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxp = 131;
uint cnk[maxp][maxp];
uint dp[maxp][maxp];
uint bigcnk[maxp], ways[maxp];

uint gcd(uint a, uint b) {
    return b ? gcd(b, a % b) : a;
}

uint bcnk(uint a, uint b) {
    if (b > a) return 0;
    vector<uint> v(b);
    forn(i, b) v[i] = a - i;
    for1(j, b) {
        uint k = j;
        forn(i, b) {
            uint g = gcd(k, v[i]);
            v[i] /= g;
            k /= g;
        }
        assert(k == 1);
    }
    uint ans = 1;
    forn(i, b) ans *= v[i];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    uint n, p, q;
    cin >> n >> p >> q;
    uin(p, n - 1);
    n -= p;
    forn(i, p + 1) cnk[0][i] = bcnk(n, i);
    for1(i, p) {
        cnk[i][0] = 1;
        for1(j, p) forn(k, 2) cnk[i][j] += cnk[i - 1][j - k];
    }
    forn(k, p + 1) dp[0][k] = 1;
    forn(i, p) forn(k, p + 1) {
        for1(j, p) {
            if (j + k > p) continue;
            dp[i + 1][j + k] += dp[i][k] * cnk[j + k][j];
        }
    }
    forn(i, p + 1) ways[i] = dp[i][p];

    bigcnk[0] = 1;
    uint ans = 0;
    for1(t, q) {
        ford(i, p) bigcnk[i + 1] += bigcnk[i];
        uint res = 0;
        forn(i, p + 1) res += bigcnk[i] * ways[i];
//        cerr << t << ' ' << res << '\n';
        ans ^= res * t;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}