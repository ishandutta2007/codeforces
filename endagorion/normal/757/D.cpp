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

string s;
const int maxn = 80;
const int P = 1000000000 + 7;
int val[maxn][maxn];
int dp[maxn][1 << 20];

void add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n >> s;
    forn(l, n) {
        int x = 0;
        for (int r = l; r <= n; ++r) {
            val[l][r] = x;
            if (r == n) break;
            x = 2 * x + s[r] - '0';
            uin(x, 21);
        }
    }

    forn(i, n + 1) dp[i][0] = 1;
    forn(l, n) forn(mask, 1 << 20) {
        if (!dp[l][mask]) continue;
        for (int r = l + 1; r <= n && val[l][r] <= 20; ++r) {
            if (val[l][r]) add(dp[r][mask | 1 << (val[l][r] - 1)], dp[l][mask]);
        }
    }

    int ans = 0;
    forn(r, n + 1) for1(i, 20) add(ans, dp[r][(1 << i) - 1]);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}