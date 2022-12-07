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

int n;
int a[1 << 17];
int st[1 << 18][60], sv[1 << 18][60];
const int off = 1 << 17;
int bad[60][7] = {};
char c[5];

inline int pMod(int x) {
    if (x >= 60) return x - 60;
    return x;
}

void buildSt() {
    for (int i = n; i < off; ++i) a[i] = 2;
    REP(i, off) REP(j, 60)
        st[off + i][j] = pMod(j + 1 + bad[j][a[i]]), sv[off + i][j] = 1 + bad[j][a[i]];
    for (int i = off - 1; i >= 1; --i) REP(j, 60) {
        st[i][j] = st[(i << 1) | 1][st[i << 1][j]];
        sv[i][j] = sv[i << 1][j] + sv[(i << 1) | 1][st[i << 1][j]];
    }
}

void updateSt(int pos, int val) {
    if (a[pos] == val) return;
    a[pos] = val;
    REP(j, 60)
        st[off + pos][j] = pMod(j + 1 + bad[j][val]), sv[off + pos][j] = 1 + bad[j][val];
    for (int i = (off + pos) >> 1; i >= 1; i >>= 1) REP(j, 60) {
        st[i][j] = st[(i << 1) | 1][st[i << 1][j]];
        sv[i][j] = sv[i << 1][j] + sv[(i << 1) | 1][st[i << 1][j]];
    }
}

int state, val;
void querySt(int v, int L, int R, int l, int r) {
    if (l == L && r == R) {
        val += sv[v][state];
        state = st[v][state];
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid) querySt(v << 1, L, mid, l, min(r, mid));
    if (r > mid) querySt((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
}

int main() {
    REP(i, 60) for (int j = 2; j <= 6; ++j)
        bad[i][j] = (i % j == 0);
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    buildSt();
    int q;
    scanf("%d", &q);
    REP(i, q) {
        int x, y;
        scanf("%s%d%d", c, &x, &y);
        if (c[0] == 'A') {
            state = val = 0;
            querySt(1, 0, off - 1, x - 1, y - 2);
            printf("%d\n", val);
        } else {
            updateSt(x - 1, y);
        }
    }
    return 0;
}