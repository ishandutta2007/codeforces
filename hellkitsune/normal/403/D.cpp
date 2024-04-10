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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int d[1001][1001] = {}, nd[1001][1001] = {};
int pre[1001][45] = {}, ans[1001][45] = {};
int f[45], c[1051][1051] = {};
const int MOD = 1e9 + 7;

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    f[0] = 1;
    for (int i = 1; i < 45; ++i) {
        f[i] = (f[i - 1] * (LL)i) % MOD;
    }
    c[0][0] = 1;
    for (int i = 1; i < 1051; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 1051; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD) c[i][j] -= MOD;
        }
    }
    d[0][0] = 1;
    for (int k = 1; k <= 44; ++k) {
        REP(i, 1001) REP(j, 1000) {
            modAdd(d[i][j + 1], d[i][j]);
        }
        memset(nd, 0, sizeof nd);
        REP(i, 1001) for (int j = 1; j <= i; ++j) {
            nd[i][j] += d[i - j][j - 1];
        }
        memcpy(d, nd, sizeof d);
        REP(i, 1001) REP(j, 1001) {
            modAdd(pre[i][k], d[i][j]);
        }
        REP(i, 1001) REP(j, i + 1) {
            ans[i][k] = (ans[i][k] + pre[j][k] * (LL)c[k + i - j][i - j]) % MOD;
        }
        REP(i, 1001) {
            ans[i][k] = (ans[i][k] * (LL)f[k]) % MOD;
        }
    }
    int t;
    scanf("%d", &t);
    REP(i, t) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (k > 44) {
            printf("0\n");
        } else {
            printf("%d\n", ans[n][k]);
        }
    }
    return 0;
}