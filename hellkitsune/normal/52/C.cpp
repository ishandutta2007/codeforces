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

LL st[1 << 19], sp[1 << 18];
const int off = 1 << 18;
const LL INF = 1e18;

void stInit() {
    for (int i = off - 1; i >= 1; --i) {
        st[i] = min(st[i << 1], st[(i << 1) | 1]);
        sp[i] = 0;
    }
}

void stPush(int v, bool eq) {
    for (int i = v << 1; i <= ((v << 1) | 1); ++i) {
        st[i] += sp[v];
        if (!eq) {
            sp[i] += sp[v];
        }
    }
    sp[v] = 0;
}

int updVal;
void stUpdate(int v, int L, int R, int l, int r) {
    if (L == l && R == r) {
        st[v] += updVal;
        if (L != R) {
            sp[v] += updVal;
        }
        return;
    }
    stPush(v, L == R - 1);
    int mid = (L + R) >> 1;
    if (l <= mid) stUpdate(v << 1, L, mid, l, min(r, mid));
    if (r > mid) stUpdate((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
    st[v] = min(st[v << 1], st[(v << 1) | 1]);
}

LL stGet(int v, int L, int R, int l, int r) {
    if (l > r) return INF;
    if (L == l && R == r) {
        return st[v];
    }
    stPush(v, L == R - 1);
    int mid = (L + R) >> 1;
    return min(stGet(v << 1, L, mid, l, min(r, mid)),
               stGet((v << 1) | 1, mid + 1, R, max(l, mid + 1), r));
}

int n, q;
char s[100];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%I64d", st + off + i);
    stInit();
    scanf("%d", &q);
    gets(s);
    REP(i, q) {
        gets(s);
        int from, to, v;
        string ss = string(s);
        istringstream iss(ss);
        iss >> from >> to;
        if (iss >> v) {
            updVal = v;
            if (from <= to) {
                stUpdate(1, 0, off - 1, from, to);
            } else {
                stUpdate(1, 0, off - 1, from, n - 1);
                stUpdate(1, 0, off - 1, 0, to);
            }
        } else {
            LL ans;
            if (from <= to) {
                ans = stGet(1, 0, off - 1, from, to);
            } else {
                ans = stGet(1, 0, off - 1, from, n - 1);
                ans = min(ans, stGet(1, 0, off - 1, 0, to));
            }
            printf("%I64d\n", ans);
        }
    }
    return 0;
}