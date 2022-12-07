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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[300000];
int f[300001][2], ff[300001], _fs[300001][2], _ffs[300001];
int t[1 << 20];
int tp[1 << 20][2] = {};
const int off = 1 << 19;

const int MOD = 1e9 + 9;

int &fs(const int &x, const int &y) {
    return _fs[x + 1][y];
}

int &ffs(const int &x) {
    return _ffs[x + 1];
}

void init_st() {
    REP(i, n) t[off + i] = a[i];
    for (int i = n; i < off; ++i) t[off + i] = 0;
    for (int i = off - 1; i >= 1; --i)
        t[i] = (t[i << 1] + t[(i << 1) | 1]) % MOD;
}

void update_st(int v, int L, int R, int l, int r, int x) {
    if (l > r) return;
    if (l == L && r == R) {
        tp[v][0] = (tp[v][0] + ff[x]) % MOD;
        tp[v][1] = (tp[v][1] + ff[x + 1]) % MOD;
        t[v] = (t[v] + ffs(r - l + x) - ffs(x - 1));
        while (t[v] < 0) t[v] += MOD;
        t[v] %= MOD;
        return;
    }
    int mid = (L + R) >> 1;
    int was = t[v << 1] + t[(v << 1) | 1];
    update_st(v << 1, L, mid, l, min(r, mid), x);
    update_st((v << 1) | 1, mid + 1, R, max(mid + 1, l), r, x + max(0, mid - l + 1));
    t[v] += (t[v << 1] + t[(v << 1) | 1]) % MOD - was;
    while (t[v] < 0) t[v] += MOD;
    t[v] %= MOD;
}

int query_st(int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (l == L && r == R) return t[v];
    int mid = (L + R) >> 1;
    if (tp[v][0] || tp[v][1]) {
        int v1 = v << 1, v2 = (v << 1) | 1;
        int add00 = tp[v][0];
        int add01 = tp[v][1];
        int add10 = (f[R - mid][0] * (LL)tp[v][0] + f[R - mid][1] * (LL)tp[v][1]) % MOD;
        int add11 = (f[R - mid + 1][0] * (LL)tp[v][0] + f[R - mid + 1][1] * (LL)tp[v][1]) % MOD;
        if (L != R - 1) {
            tp[v1][0] = (tp[v1][0] + tp[v][0]) % MOD;
            tp[v1][1] = (tp[v1][1] + tp[v][1]) % MOD;
            tp[v2][0] = (tp[v2][0] + add10) % MOD;
            tp[v2][1] = (tp[v2][1] + add11) % MOD;
        }
        t[v1] = (t[v1] + fs(mid - L, 0) * (LL)add00 + fs(mid - L, 1) * (LL)add01) % MOD;
        t[v2] = (t[v2] + fs(mid - L, 0) * (LL)add10 + fs(mid - L, 1) * (LL)add11) % MOD;
    }
    tp[v][0] = tp[v][1] = 0;
    return (query_st(v << 1, L, mid, l, min(r, mid)) +
            query_st((v << 1) | 1, mid + 1, R, max(mid + 1, l), r)) % MOD;
}

int main() {
    fs(-1, 0) = fs(-1, 1) = ffs(-1) = 0;
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    f[0][0] = f[1][1] = 1;
    f[0][1] = f[1][0] = 0;
    for (int i = 2; i <= n; ++i) REP(j, 2) f[i][j] = (f[i - 1][j] + f[i - 2][j]) % MOD;
    REP(i, n + 1) ff[i] = (f[i][0] + f[i][1]) % MOD;
    fs(0, 0) = f[0][0], fs(0, 1) = f[0][1];
    for (int i = 1; i < n; ++i) REP(j, 2) fs(i, j) = (fs(i - 1, j) + f[i][j]) % MOD;
    REP(i, n) ffs(i) = (fs(i, 0) + fs(i, 1)) % MOD;
    init_st();
    REP(i, m) {
        int q, l, r;
        scanf("%d%d%d", &q, &l, &r), --l, --r;
        if (q == 1) {
            update_st(1, 0, off - 1, l, r, 0);
        } else {
            printf("%d\n", query_st(1, 0, off - 1, l, r));
        }
    }
    return 0;
}