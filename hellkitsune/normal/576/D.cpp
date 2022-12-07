#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int from[150], to[150], d[150], ord[150], tmp[150];

inline bool cmp(const int &lhs, const int &rhs) {
    return d[lhs] < d[rhs];
}

void reorder(int *arr) {
    REP(i, m) tmp[i] = arr[ord[i]];
    REP(i, m) arr[i] = tmp[i];
}

int v[150], nv[150];
int mat[150][150], res[150][150], mmat[150][150];
unsigned r[150][5], c[150][5];
int f[150][150];
const int INF = 1e9 + 1e7;
const unsigned ONE = (unsigned)1;

void matMul(int (&a)[150][150], int (&b)[150][150]) {
    REP(i, n) REP(j, 5) r[i][j] = c[i][j] = 0;
    REP(i, n) REP(j, n) if (a[i][j]) r[i][j >> 5] |= ONE << (j & 31);
    REP(i, n) REP(j, n) if (b[j][i]) c[i][j >> 5] |= ONE << (j & 31);
    REP(i, n) REP(j, n) {
        a[i][j] = 0;
        REP(k, 5) if (r[i][k] & c[j][k]) {
            a[i][j] = 1;
            break;
        }
    }
}

void matExp(int p) {
    REP(i, n) REP(j, n) res[i][j] = i == j;
    REP(i, n) REP(j, n) mmat[i][j] = mat[i][j];
    while (p) {
        if (p & 1) matMul(res, mmat);
        p >>= 1;
        if (!p) break;
        matMul(mmat, mmat);
    }
}

void vecMul() {
    REP(i, n) nv[i] = 0;
    REP(i, n) REP(j, n) if (res[i][j] && v[i]) {
        nv[j] = 1;
    }
    REP(i, n) v[i] = nv[i];
}

bool vis[150];

void dfs(int v) {
    vis[v] = true;
    REP(i, n) if (mat[v][i] && !vis[i]) {
        dfs(i);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        scanf("%d%d%d", from + i, to + i, d + i), --from[i], --to[i];
    }
    REP(i, m) ord[i] = i;
    sort(ord, ord + m, cmp);
    reorder(from);
    reorder(to);
    reorder(d);
    if (d[0] != 0) {
        printf("Impossible\n");
        return 0;
    }
    REP(i, n) v[i] = 0;
    v[0] = 1;
    REP(i, n) REP(j, n) mat[i][j] = 0;
    for (int beg = 0; beg < m; ) {
        int end = beg + 1;
        while (end < m && d[end] == d[beg]) ++end;
        for (int i = beg; i < end; ++i) {
            mat[from[i]][to[i]] = 1;
        }
        REP(i, n) REP(j, n) if (i == j) {
            f[i][j] = 0;
        } else if (mat[i][j]) {
            f[i][j] = 1;
        } else {
            f[i][j] = INF;
        }
        REP(i, n) vis[i] = false;
        REP(i, n) if (v[i] && !vis[i]) dfs(i);
        if (vis[n - 1]) {
            REP(k, n) REP(i, n) REP(j, n) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
            int ans = INF;
            REP(i, n) if (v[i] == 1) {
                ans = min(ans, f[i][n - 1]);
            }
            printf("%d\n", ans + d[beg]);
            return 0;
        }
        if (end >= m) {
            printf("Impossible\n");
            return 0;
        }
        matExp(d[end] - d[beg]);
        vecMul();
        beg = end;
    }
    printf("Impossible\n");
    return 0;
}