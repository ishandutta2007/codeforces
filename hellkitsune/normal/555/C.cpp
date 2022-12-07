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

int n, q;
char s[5];
set<int> se;
map<int, int> ma;
int mac = 0;
int qx[200000], tmp;
char qc[200000];
int _rev[200002], *rev = _rev + 1;
bool used[200000] = {};
int stx[1 << 19], sty[1 << 19];
const int off = 1 << 18;

void stxInit() {
    REP(i, off << 1) stx[i] = mac;
}

void styInit() {
    REP(i, off << 1) sty[i] = -1;
}

void stxMin(int v, int L, int R, int l, int r, int val) {
    if (L == l && R == r) {
        stx[v] = min(stx[v], val);
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid) stxMin(v << 1, L, mid, l, min(r, mid), val);
    if (r > mid) stxMin((v << 1) | 1, mid + 1, R, max(l, mid + 1), r, val);
}

int stxGet(int pos) {
    int ret = 1e9;
    for (pos += off; pos >= 1; pos >>= 1) {
        ret = min(ret, stx[pos]);
    }
    return ret;
}

void styMax(int v, int L, int R, int l, int r, int val) {
    if (L == l && R == r) {
        sty[v] = max(sty[v], val);
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid) styMax(v << 1, L, mid, l, min(r, mid), val);
    if (r > mid) styMax((v << 1) | 1, mid + 1, R, max(l, mid + 1), r, val);
}

int styGet(int pos) {
    int ret = -1;
    for (pos += off; pos >= 1; pos >>= 1) {
        ret = max(ret, sty[pos]);
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &q);
    REP(i, q) {
        scanf("%d%d%s", qx + i, &tmp, s), --qx[i];
        qc[i] = s[0];
    }
    REP(i, q) se.insert(qx[i]);
    for (int x : se) ma[x] = mac, rev[mac] = x, ++mac;
    REP(i, q) qx[i] = ma[qx[i]];
    rev[mac] = n;
    rev[-1] = -1;
    stxInit();
    styInit();
    REP(i, q) {
        if (used[qx[i]]) {
            printf("0\n");
            continue;
        }
        used[qx[i]] = true;
        if (qc[i] == 'U') {
            int lim = stxGet(qx[i]);
            printf("%d\n", rev[lim] - rev[qx[i]]);
            if (qx[i] + 1 <= lim - 1) styMax(1, 0, off - 1, qx[i] + 1, lim - 1, qx[i]);
        } else {
            int lim = styGet(qx[i]);
            printf("%d\n", rev[qx[i]] - rev[lim]);
            if (lim + 1 <= qx[i] - 1) stxMin(1, 0, off - 1, lim + 1, qx[i] - 1, qx[i]);
        }
    }
    return 0;
}