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

int n;
int a[300000];
int l[300000], r[300000], ll[300000], rr[300000];
const int MOD = 1e9 + 7, MMOD = 1e9 + 9;
const int MU = 7, MMU = 13;
int mu[300001], mmu[300001];

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

inline void fenInc(int *fen, int pos, int val) {
    for (; pos < n; pos |= pos + 1) {
        modAdd(fen[pos], val);
    }
}

inline int fenGet(int *fen, int pos) {
    int ret = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        modAdd(ret, fen[pos]);
    }
    return ret;
}

inline void mmodAdd(int &x, int y) {
    x += y;
    if (x >= MMOD) x -= MMOD;
}

inline void ffenInc(int *fen, int pos, int val) {
    for (; pos < n; pos |= pos + 1) {
        mmodAdd(fen[pos], val);
    }
}

inline int ffenGet(int *fen, int pos) {
    int ret = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        mmodAdd(ret, fen[pos]);
    }
    return ret;
}

void setBitL(int pos) {
    fenInc(l, pos, mu[pos]);
    ffenInc(ll, pos, mmu[pos]);
}

void setBitR(int pos) {
    pos = n - 1 - pos;
    fenInc(r, pos, mu[pos]);
    ffenInc(rr, pos, mmu[pos]);
}

int getHashL(int from, int to) {
    int h = fenGet(l, to) - fenGet(l, from - 1);
    if (h < 0) h += MOD;
    h = (LL)h * mu[n - from] % MOD;
    return h;
}

int getHashLL(int from, int to) {
    int h = ffenGet(ll, to) - ffenGet(ll, from - 1);
    if (h < 0) h += MMOD;
    h = (LL)h * mmu[n - from] % MMOD;
    return h;
}

int getHashR(int from, int to) {
    swap(from, to);
    from = n - 1 - from;
    to = n - 1 - to;
    int h = fenGet(r, to) - fenGet(r, from - 1);
    if (h < 0) h += MOD;
    h = (LL)h * mu[n - from] % MOD;
    return h;
}

int getHashRR(int from, int to) {
    swap(from, to);
    from = n - 1 - from;
    to = n - 1 - to;
    int h = ffenGet(rr, to) - ffenGet(rr, from - 1);
    if (h < 0) h += MMOD;
    h = (LL)h * mmu[n - from] % MMOD;
    return h;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i), --a[i];
    mu[n] = mmu[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        mu[i] = (LL)mu[i + 1] * MU % MOD;
        mmu[i] = (LL)mmu[i + 1] * MMU % MMOD;
    }
    REP(i, n) {
        int val = a[i];
        int len = min(val + 1, n - val) - 1;
        if (getHashL(val - len, val) != getHashR(val, val + len) ||
            getHashLL(val - len, val) != getHashRR(val, val + len)) {
            printf("YES\n");
            return 0;
        }
        setBitL(val);
        setBitR(val);
    }
    printf("NO\n");
    return 0;
}