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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

const int maxn = 51;
string f[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, n) cin >> f[i];
    int sx, sy, fx, fy;
    forn(i, n) forn(j, m) { 
        if (f[i][j] == 'S') sx = i, sy = j;
        if (f[i][j] == 'E') fx = i, fy = j;
    }
    string comm;
    cin >> comm;
    vi mm(4);
    iota(all(mm), 0);
    int ans = 0;
    do {
        int x = sx, y = sy;
        bool ok = true;
        for (char c: comm) {
            int d = mm[c - '0'];
            x += dx[d], y += dy[d];
            if (x == fx && y == fy) break;
            if (min(x, y) < 0 || min(n - x, m - y) <= 0 || f[x][y] == '#') ok = false;
        }
        ok &= x == fx && y == fy;
        if (ok) ++ans;
    } while (next_permutation(all(mm)));
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}