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

i64 P;
string f[101];
int comp[111][111];
int vis[111][111];

int N, M;

bool dfs(int x, int y, int px, int py, int c) {
    if (x == px && y == py) return true;
    if (vis[x][y] == 1) return false;
    if (vis[x][y] == 2) return true;
    comp[x][y] = c;
    vis[x][y] = 1;
    if (x < N && y < M && f[x][y] == '\\' && mp(x + 1, y + 1) != mp(px, py)) {
        if (!dfs(x + 1, y + 1, x, y, c)) return false;
    }
    if (x < N && y > 0 && f[x][y - 1] == '/' && mp(x + 1, y - 1) != mp(px, py)) {
        if (!dfs(x + 1, y - 1, x, y, c)) return false;
    }
    if (x > 0 && y < M && f[x - 1][y] == '/' && mp(x - 1, y + 1) != mp(px, py)) {
        if (!dfs(x - 1, y + 1, x, y, c)) return false;
    }
    if (x > 0 && y > 0 && f[x - 1][y - 1] == '\\' && mp(x - 1, y - 1) != mp(px, py)) {
        if (!dfs(x - 1, y - 1, x, y, c)) return false;
    }
    vis[x][y] = 2;
    return true;
}

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) y *= x, y %= P;
        d /= 2;
        x *= x, x %= P;
    }
    return y;
}

i64 det(vvi64 a) {
    int n = a.size();
    i64 q = 1;
    forn(i, n) {
        int m = -1;
        for (int j = i; j < n; ++j) {
            if (a[j][i]) {
                m = j;
                break;
            }
        }
        if (m < 0) return 0;
        if (m != i) {
            swap(a[m], a[i]);
            q = -q;
        }
        i64 w = deg(a[i][i], -1);
        for (int j = i + 1; j < n; ++j) {
            i64 t = a[j][i] * w % P;
            for (int k = i; k < n; ++k) {
                a[j][k] -= t * a[i][k];
                a[j][k] %= P;
            }
        }
        q *= a[i][i];
        q %= P;
    }
    return q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> N >> M >> P;
    forn(i, N) cin >> f[i];
    forn(i, N + 1) forn(j, M + 1) comp[i][j] = -1;
    int cc = 0;
    forn(i, N + 1) forn(j, M + 1) {
        if (vis[i][j]) continue;
        if (!dfs(i, j, -1, -1, cc++)) {
            cout << 0 << '\n';
            return 0;
        }
    }
    i64 ans = 0;
    forn(t, 2) {
        map<int, int> en;
        forn(x, N + 1) forn(y, M + 1) {
            if (((x + y) & 1) != t) continue;
            if (en.count(comp[x][y])) continue;
            int z = en.size();
            en[comp[x][y]] = z;
        }
        int K = en.size();
        vvi64 a(K, vi64(K));
        forn(x, N + 1) forn(y, M + 1) {
            if (((x + y) & 1) != t) continue;
            if (x < N && y < M && f[x][y] == '*') {
                int c1 = en[comp[x][y]], c2 = en[comp[x + 1][y + 1]];
                if (c1 != c2) --a[c1][c2], ++a[c1][c1];
            }
            if (x < N && y > 0 && f[x][y - 1] == '*') {
                int c1 = en[comp[x][y]], c2 = en[comp[x + 1][y - 1]];
                if (c1 != c2) --a[c1][c2], ++a[c1][c1];
            }
            if (x > 0 && y < M && f[x - 1][y] == '*') {
                int c1 = en[comp[x][y]], c2 = en[comp[x - 1][y + 1]];
                if (c1 != c2) --a[c1][c2], ++a[c1][c1];
            }
            if (x > 0 && y > 0 && f[x - 1][y - 1] == '*') {
                int c1 = en[comp[x][y]], c2 = en[comp[x - 1][y - 1]];
                if (c1 != c2) --a[c1][c2], ++a[c1][c1];
            }
        }
        forn(i, K) forn(j, K) a[i][j] %= P;
        a.resize(K - 1);
        forn(i, K - 1) a[i].resize(K - 1);
        i64 res = det(a);
        cerr << res << '\n';
        ans += res;
    }
    ans %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}