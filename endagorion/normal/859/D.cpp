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

const int maxk = 6;
ld dp[maxk + 1][1 << maxk];
ld p[1 << maxk][1 << maxk];
ld q[maxk + 1][1 << maxk];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int k;
    cin >> k;
    int n = 1 << k;
    forn(i, n) forn(j, n) {
        cin >> p[i][j];
        p[i][j] *= 0.01;
    }

    forn(i, n) q[0][i] = 1.0;
    forn(l, k) forn(i, n) {
        q[l + 1][i] = 0.0;
        forn(j, 1 << l) {
            int ii = i ^ (1 << l) ^ j;
            q[l + 1][i] += q[l][i] * q[l][ii] * p[i][ii];
        }
    }

    forn(l, k + 1) forn(i, n >> l) {
        forn(j, 1 << l) {
            int w = (i << l) + j;
            ld res = 0.0;
            forn(ll, l) res += q[ll + 1][w] * (1 << ll);
            forn(ll, l) res += dp[ll][(w >> ll) ^ 1];
            uax(dp[l][i], res);
        }
    }
    cout << dp[k][0] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}