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
int st[1 << 18] = {};
const int off = 1 << 17;

void stUpdate(int pos, int val) {
    st[off + pos] = val;
    for (pos = (pos + off) >> 1; pos >= 1; pos >>= 1) {
        st[pos] = max(st[pos << 1], st[(pos << 1) | 1]);
    }
}

int stGet(int v, int L, int R, int l, int r) {
    if (l > r) return -1;
    if (L == l && R == r) {
        return st[v];
    }
    int mid = (L + R) >> 1;
    return max(stGet(v << 1, L, mid, l, min(r, mid)),
               stGet((v << 1) | 1, mid + 1, R, max(l, mid + 1), r));
}

int x[100000], h[100000], ord[100000], nx[100000], nh[100000], ans[100000];

inline bool cmp(const int &lhs, const int &rhs) {
    return x[lhs] < x[rhs];
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, h + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) nx[i] = x[ord[i]], nh[i] = h[ord[i]];
    REP(i, n) x[i] = nx[i], h[i] = nh[i];
    for (int i = n - 1; i >= 0; --i) {
        int lo = i, hi = n - 1, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (x[i] + h[i] > x[mid])
                lo = mid;
            else
                hi = mid - 1;
        }
        int best = i;
        if (lo > i) best = stGet(1, 0, off - 1, i + 1, lo);
        ans[ord[i]] = best - i + 1;
        stUpdate(i, best);
    }
    REP(i, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}