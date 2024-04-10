#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
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
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)((n) - 1); i >= 0; --i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define debugv(a) forn(i, a.size()) cerr << a[i] << ' '; cerr << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

typedef long double ld;

const int MAXN = 30000;
const int INF = 1e9;

int a[MAXN], b[MAXN];
int mod[2 * MAXN];
char way[2 * MAXN];
int dpf[2][MAXN], dpb[2][MAXN];
int vis[2][MAXN];
int N, M, P;

inline int cost(int i, int j) {
    return mod[a[i] + b[j]];
}

void dp(int sx, int sy, int fx, int fy) {
//    cerr << sx << ' ' << sy << ' ' << fx << ' ' << fy << '\n';
    if (sx == fx) {
        forn(i, fy - sy) way[sx + sy + i] = 'S';
        return;
    }
    if (sy == fy) {
        forn(i, fx - sx) way[sx + sy + i] = 'C';
        return;
    }
    int M = (sx + sy + fx + fy) / 2;
    dpf[0][0] = 0;
    int D = M - sx - sy;
    for (int i = 1; i <= D; ++i) {
        int nx = i & 1, cur = nx ^ 1;
        for (int j = 0; j <= i && j <= fx - sx; ++j) {
            dpf[nx][j] = max(j ? dpf[cur][j - 1] : -1e9, i - j ? dpf[cur][j] : -1e9) + cost(sx + j, sy + i - j);
        }
    }
    dpb[0][0] = 0;
    int D1 = fx + fy - M;
    for (int i = 1; i <= D1; ++i) {
        int nx = i & 1, cur = nx ^ 1;
        for (int j = 0; j <= i && j <= fx - sx; ++j) {
            dpb[nx][j] = max(j ? dpb[cur][j - 1] : -1e9, i - j ? dpb[cur][j] : -1e9) + cost(fx - j, fy - (i - j));
        }        
    }
    int m = -1, bcost = -1;
    for (int j = max(0, D - fy + sy); j <= fx - sx && j <= D; ++j) {
        int cst = dpf[D & 1][j] + dpb[D1 & 1][fx - sx - j] - cost(sx + j, sy + D - j);
        if (cst > bcost) {
            bcost = cst;
            m = j;
        }
    }
    dp(sx, sy, sx + m, sy + D - m);
    dp(sx + m, sy + D - m, fx, fy);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d%d%d", &N, &M, &P);
    forn(i, 2 * MAXN) mod[i] = i % P;
    forn(i, N) scanf("%d", &a[i]);
    forn(i, M) scanf("%d", &b[i]);
    dp(0, 0, N - 1, M - 1);
    int total = 0;
    int x = 0, y = 0;
    forn(i, N + M - 2) {
        total += cost(x, y);
        if (way[i] == 'C') ++x;
        else ++y;
    }
    total += cost(x, y);
    //cout << total << '\n';
    printf("%d\n", total);
    printf("%s\n", way);


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}