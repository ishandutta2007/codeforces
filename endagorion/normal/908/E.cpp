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

const int maxn = 1100;
const i64 P = 1000000000 + 7;
i64 cnk[maxn][maxn];
i64 dp[maxn];

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

    dp[0] = 1;
    for1(i, maxn - 1) forn(j, i) (dp[i] += cnk[i - 1][j] * dp[i - j - 1]) %= P;

    int m, n;
    cin >> m >> n;
    vector<string> col(m);
    forn(i, n) {
        string s;
        cin >> s;
        forn(j, m) col[j] += s[j];
    }
    map<string, int> types;
    for (string t: col) ++types[t];
    i64 ans = 1;
    for (auto w: types) (ans *= dp[w.se]) %= P;
    cout << ans << '\n';
    
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}