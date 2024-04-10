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

int vis[600][600];
string s[600];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;

bool ok(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return false;
    return true;
}

void dfs(int x, int y) {
    if (!ok(x, y)) return;
    if (vis[x][y]) return;
//    cerr << x << ' ' << y << '\n';
    vis[x][y] = 1;
    forn(d, 4) {
        int xx = x + dx[d], yy = y + dy[d];
        if (!ok(xx, yy) || s[xx][yy] == 'X') continue;
        dfs(xx, yy);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> N >> M;
    forn(i, N) cin >> s[i];
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    --sx; --sy; --fx; --fy;

    dfs(sx, sy);
    bool good = vis[fx][fy];
    if (s[fx][fy] == 'X') {
        forn(d, 4) {
            int xx = fx + dx[d], yy = fy + dy[d];
            good |= ok(xx, yy) && vis[xx][yy];
        }
    } else if (good) {
        int cnt = 0;
        forn(d, 4) {
            int xx = fx + dx[d], yy = fy + dy[d];
            cnt += ok(xx, yy) && s[xx][yy] == '.';
            cnt += (sx == xx && sy == yy);
        }
        good = cnt >= 2;
    }

    if (sx == fx && sy == fy) {
        good = false;
        forn(d, 4) {
            int xx = sx + dx[d], yy = sy + dy[d];
            good |= ok(xx, yy) && s[xx][yy] == '.';
        }
    }
    cout << (good ? "YES" : "NO") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}