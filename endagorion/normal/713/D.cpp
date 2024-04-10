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

const int maxn = 1001;
int n, m;
int a[maxn][maxn], pa[maxn][maxn], sq[maxn][maxn];

const int maxt = 2 * maxn;
const int LOG = 10;
int sp[LOG + 1][maxn][LOG + 1][maxn];
int m2[maxn];

void build_sparse(int d, int v) {
    forn(i, LOG) forn(j, m) {
        sp[d][v][i + 1][j] = sp[d][v][i][j];
        if (j + (1 << i) < m) uax(sp[d][v][i + 1][j], sp[d][v][i][j + (1 << i)]);
    }
}

int rect_sum(int x1, int y1, int x2, int y2) {
    return pa[x2][y2] - pa[x1][y2] - pa[x2][y1] + pa[x1][y1];
}

int qsparse(int d, int v, int l, int r) {
    int k = m2[r - l];
    return max(sp[d][v][k][l], sp[d][v][k][r - (1 << k)]);
}

int qsparse2(int lx, int rx, int ly, int ry) {
    int k = m2[rx - lx];
    return max(qsparse(k, lx, ly, ry), qsparse(k, rx - (1 << k), ly, ry));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    scanf("%d%d", &n, &m);
    forn(i, n) forn(j, m) scanf("%d", &a[i][j]);
    forn(i, n) forn(j, m) pa[i + 1][j + 1] = a[i][j] + pa[i + 1][j] + pa[i][j + 1] - pa[i][j];
    forn(i, n) forn(j, m) {
        int l = 0, r = min(n - i, m - j) + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            (rect_sum(i, j, i + m, j + m) == m * m ? l : r) = m;
        }
        sq[i][j] = l;
    }

    forn(i, maxn) {
        m2[i] = 0;
        while ((1 << m2[i]) <= i) ++m2[i];
        --m2[i];
    }
    forn(j, n) {
        forn(k, m) sp[0][j][0][k] = sq[j][k];
        build_sparse(0, j);
    }
    forn(d, LOG) forn(j, n) forn(d1, LOG) forn(k, m) {
        sp[d + 1][j][d1][k] = sp[d][j][d1][k];
        if (j + (1 << d) < n) uax(sp[d + 1][j][d1][k], sp[d][j + (1 << d)][d1][k]);
    }

//    int root = build_tree(0, n);
    cerr << "built\n";

    int q;
    scanf("%d", &q);
    forn(i, q) {
        int lx, rx, ly, ry;
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        --lx; --ly;
        int l = 0, r = min(ry - ly, rx - lx) + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            (qsparse2(lx, rx - m + 1, ly, ry - m + 1) >= m ? l : r) = m;
        }
        printf("%d\n", l);
    }


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}