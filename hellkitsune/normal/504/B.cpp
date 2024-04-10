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
int p[200000], q[200000];
int a[200002] = {};
int fen[200000];

void fenInit() {
    REP(i, n) fen[i] = 0;
}

void fenInc(int pos) {
    for (; pos < n; pos |= pos + 1)
        ++fen[pos];
}

int fenGet(int pos) {
    int ret = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        ret += fen[pos];
    return ret;
}

void go(int *p) {
    fenInit();
    REP(i, n) {
        a[n - i] += p[i] - fenGet(p[i] - 1);
        fenInc(p[i]);
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", p + i);
    REP(i, n) scanf("%d", q + i);
    go(p);
    go(q);
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= i) {
            ++a[i + 1];
            a[i] -= i;
        }
    }
    fenInit();
    REP(i, n) {
        int val = a[n - i];
        int lo = 0, hi = n - 1, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (mid - fenGet(mid) < val) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        fenInc(lo);
        printf("%d ", lo);
    }
    printf("\n");
    return 0;
}