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
int x[400000], y[400000], ord[400000];
int h[800000], sz = 0;

bool cmp(const int &lhs, const int &rhs) {
    if (x[lhs] != x[rhs]) return x[lhs] < x[rhs];
    return y[lhs] < y[rhs];
}

bool cw(int a, int b, int c) {
    return LL(x[b] - x[a]) * (y[c] - y[a]) - LL(y[b] - y[a]) * (x[c] - x[a]) < 0;
}

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        x[4 * i] = xx + 1;
        y[4 * i] = yy;
        x[4 * i + 1] = xx - 1;
        y[4 * i + 1] = yy;
        x[4 * i + 2] = xx;
        y[4 * i + 2] = yy + 1;
        x[4 * i + 3] = xx;
        y[4 * i + 3] = yy - 1;
    }
    n *= 4;
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    for (int i = 0; i < n; h[sz++] = ord[i++]) {
        for (; sz >= 2 && !cw(h[sz - 2], h[sz - 1], ord[i]); --sz);
    }
    for (int i = n - 2, beg = sz; i >= 0; h[sz++] = ord[i--]) {
        for (; sz > beg && !cw(h[sz - 2], h[sz - 1], ord[i]); --sz);
    }
    LL ans = 0;
    REP(i, sz - 1) {
        int p = h[i];
        int q = h[i + 1];
        ans += max(abs(x[p] - x[q]), abs(y[p] - y[q]));
    }
    cout << ans << endl;
    return 0;
}