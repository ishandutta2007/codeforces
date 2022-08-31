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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

string s[600];
int v[600][600], h[600][600];

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
    forn(i, n) cin >> s[i];
    forn(i, n) forn(j, m) {
        h[i + 1][j + 1] = h[i + 1][j] + h[i][j + 1] - h[i][j] + (j + 1 < m && s[i][j] == '.' && s[i][j + 1] == '.');
        v[i + 1][j + 1] = v[i + 1][j] + v[i][j + 1] - v[i][j] + (i + 1 < n && s[i][j] == '.' && s[i + 1][j] == '.');
    }
    int q;
    cin >> q;
    forn(i, q) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        --lx; --ly;
        int ans = v[rx - 1][ry] - v[rx - 1][ly] - v[lx][ry] + v[lx][ly];
        ans += h[rx][ry - 1] - h[rx][ly] - h[lx][ry - 1] + h[lx][ly];
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}