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

string s, t;
int n;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

char opp(char c) {
    if (c == 'N' || c == 'S') return c ^ 'N' ^ 'S';
    else return c ^ 'E' ^ 'W';
}

bool poss(int x, int y, int d) {
    int xx = x + dx[d], yy = y + dy[d];
    int nx = min(x, xx), ny = min(y, yy);
    if (min(xx, yy) < 0 || max(xx, yy) > n) return false;
    if (d % 2 == 0) {
        if (x != xx) {
            return (ny == n || t[ny] != s[nx]) && (ny == 0 || opp(t[ny - 1]) != s[nx]);
        } else {
            return (nx == n || s[nx] != t[ny]) && (nx == 0 || opp(s[nx - 1]) != t[ny]);
        }
    }
    if (dx[d] == dy[d]) {
        return s[nx] == t[ny];
    } else {
        return s[nx] == opp(t[ny]);
    }
}

int q = 0;

bool dfs(int x, int y, int d, bool ft) {
    ++q;
    if (1.0 * clock() / CLOCKS_PER_SEC > 1.8) return false;
//    cerr << x << ' ' << y << ' ' << d << '\n';
    if (x == n && y == n) return true;
    if (x == 0 && y == 0 && !ft) return false;
    forn(dd, 8) {
        int nd = (d + dd) % 8;
        if (poss(x, y, nd)) return dfs(x + dx[nd], y + dy[nd], (nd + 5) % 8, false);
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> s >> t;
    --n;
    forn(i, n) t[i] = opp(t[i]);
    string u = string(rall(t)) + '#' + s;
    vi p(u.size());
    for1(i, u.size() - 1) {
        p[i] = p[i - 1];
        while (p[i] && u[i] != u[p[i]]) p[i] = p[p[i] - 1];
        if (u[i] == u[p[i]]) ++p[i];
    }
    cout << (p.back() ? "NO" : "YES") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}