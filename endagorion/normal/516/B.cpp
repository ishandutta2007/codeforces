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

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int N, M;
char s[2000][2001];
int d[2000][2000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool ok(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    scanf("%d%d", &N, &M);
    forn(i, N) {
        scanf("%s", s[i]);
    }
    vector<pii> q;
    int lft = 0;
    forn(i, N) forn(j, M) {
        if (s[i][j] == '*') continue;
        ++lft;
        forn(dd, 4) {
            int x = i + dx[dd], y = j + dy[dd];
            if (!ok(x, y)) continue;
            if (s[x][y] == '.') ++d[i][j];
        }
        if (d[i][j] == 1) {
            q.pb(mp(i, j));
        }
    }
    int cur = 0;
    while (cur < q.size()) {
        int x = q[cur].fi, y = q[cur].se;
        ++cur;
        if (d[x][y] != 1) {
            assert(d[x][y] == 0);
            continue;
        }
        forn(dd, 4) {
            int xx = x + dx[dd], yy = y + dy[dd];
            if (!ok(xx, yy) || d[xx][yy] == 0) continue;
            s[x][y] = "v>^<"[dd ^ 2];
            s[xx][yy] = "v>^<"[dd];
            lft -= 2;
            d[x][y] = d[xx][yy] = 0;
            forn(ddd, 4) {
                int xxx = xx + dx[ddd], yyy = yy + dy[ddd];
                if (!ok(xxx, yyy) || d[xxx][yyy] == 0) continue;
                if (--d[xxx][yyy] == 1) q.pb(mp(xxx, yyy));
            }
            break;
        }
    }
//    cerr l<< lft << '\n';
    if (!lft) {
        forn(i, N) printf("%s\n", s[i]);
    } else {
        printf("Not unique\n");
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}