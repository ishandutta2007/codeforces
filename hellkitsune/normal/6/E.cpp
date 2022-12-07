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

int tmx[1 << 18], tmn[1 << 18];
int off = 1 << 17;
int n, k;
int a[100001];
int best = 0;
vector<PII> ans;

const int INF = 1e9;

void mx_init() {
    for (int i = 0; i < n; ++i)
        tmx[off + i] = a[i];
    for (int i = n; i < off; ++i)
        tmx[off + i] = 0;
    for (int i = off - 1; i >= 1; --i)
        tmx[i] = max(tmx[i << 1], tmx[(i << 1) | 1]);
}

void mn_init() {
    for (int i = 0; i < n; ++i)
        tmn[off + i] = a[i];
    for (int i = n; i < off; ++i)
        tmn[off + i] = INF;
    for (int i = off - 1; i >= 1; --i)
        tmn[i] = min(tmn[i << 1], tmn[(i << 1) | 1]);
}

int mx_get(int l, int r, int L, int R, int v) {
    if (l > r) return 0;
    if (l == L && r == R) return tmx[v];
    int M = (L + R) >> 1;
    return max(mx_get(l, min(r, M), L, M, v << 1), mx_get(max(l, M + 1), r, M + 1, R, (v << 1) | 1));
}

int mn_get(int l, int r, int L, int R, int v) {
    if (l > r) return INF;
    if (l == L && r == R) return tmn[v];
    int M = (L + R) >> 1;
    return min(mn_get(l, min(r, M), L, M, v << 1), mn_get(max(l, M + 1), r, M + 1, R, (v << 1) | 1));
}

int mxget(int l, int r) {
    return mx_get(l, r, 0, off - 1, 1);
}

int mnget(int l, int r) {
    return mn_get(l, r, 0, off - 1, 1);
}

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    mx_init();
    mn_init();
    int j = 0;
    REP(i, n) {
        while (mxget(j, i) - mnget(j, i) > k) {
            ++j;
        }
        if (i - j + 1 > best) {
            best = i - j + 1;
            ans.clear();
        }
        if (i - j + 1 == best) ans.pb(mp(j + 1, i + 1));
    }
    printf("%d %d\n", best, (int)ans.size());
    REP(i, ans.size())
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}