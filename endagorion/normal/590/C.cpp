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

string s[1100];
int dist[4][1100][1100];

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool ok(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void bfs(int t) {
    vector<pii> q;
    forn(i, N) forn(j, M) {
        dist[t][i][j] = 1e8;
        if (s[i][j] == (char)(t + '1')) dist[t][i][j] = 0, q.pb(mp(i, j));
    }
    forn(c, q.size()) {
        int x = q[c].fi, y = q[c].se;
        forn(d, 4) {
            int xx = x + dx[d], yy = y + dy[d];
            if (!ok(xx, yy) || s[xx][yy] == '#' || dist[t][xx][yy] < 1e7) continue;
            dist[t][xx][yy] = dist[t][x][y] + 1;
            q.pb(mp(xx, yy));
        }
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
    forn(t, 3) bfs(t);
    int ans = 1e8;
    forn(i, N) forn(j, M) {
        int res = 1;
        forn(t, 3) res += max(0, dist[t][i][j] - 1);
        uin(ans, res);
    }
    forn(t, 3) {
        int d1 = 1e9, d2 = 1e9;
        forn(i, N) forn(j, M) {
            if (s[i][j] != (char)('1' + t)) continue;
            uin(d1, dist[(t + 1) % 3][i][j]);
            uin(d2, dist[(t + 2) % 3][i][j]);
        }
        uin(ans, d1 + d2 - 2);
    }
    if (ans > 1e7) ans = -1;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}