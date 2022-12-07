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

int n, c;
int mxL[1000000], mnR[1000000], mxR[1000000];
int l[1000000], r[1000000];
char s[10];

int build(int v, int lo, int bound) {
    if (mxR[v] > bound || mxL[v] > bound || mxL[v] >= mnR[v] || lo > bound) {
        printf("IMPOSSIBLE\n");
        exit(0);
    }
    if (v == lo && mxL[v] == v && mxR[v] == v) {
        return v;
    }
    if (mnR[v] == n) {
        l[v] = v + 1;
        return build(v + 1, max(max(lo, v + 1), mxL[v]), bound);
    } else if (mxL[v] == v) {
        r[v] = v + 1;
        return build(v + 1, max(max(lo, v + 1), mxR[v]), bound);
    } else {
        l[v] = v + 1;
        r[v] = build(v + 1, mxL[v], mnR[v] - 1) + 1;
        return build(r[v], max(max(lo, r[v]), mxR[v]), bound);
    }
}

void out(int v) {
    if (l[v] != -1) out(l[v]);
    printf("%d ", v + 1);
    if (r[v] != -1) out(r[v]);
}

int main() {
    scanf("%d%d", &n, &c);
    REP(i, n) mxL[i] = mxR[i] = i, mnR[i] = n, l[i] = r[i] = -1;
    REP(i, c) {
        int from, to;
        scanf("%d%d%s", &from, &to, s), --from, --to;
        if (from >= to) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        if (s[0] == 'L') {
            mxL[from] = max(mxL[from], to);
        } else {
            mnR[from] = min(mnR[from], to);
            mxR[from] = max(mxR[from], to);
        }
    }
    build(0, n - 1, n - 1);
    out(0);
    return 0;
}