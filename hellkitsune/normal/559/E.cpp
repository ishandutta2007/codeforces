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
int a[103], l[103], ord[103], na[103], nl[103];
int d[103][103][103], nd[103][103][103];
int pre[103][103][103] = {}, nx[103];
int dist[103][103][103];
int upto[103];

bool cmp(const int &lhs, const int &rhs) {
    return a[lhs] < a[rhs];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", a + i, l + i);
    for (int i = 1; i <= n; ++i) ord[i] = i;
    sort(ord + 1, ord + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) na[i] = a[ord[i]], nl[i] = l[ord[i]];
    for (int i = 1; i <= n; ++i) a[i] = na[i], l[i] = nl[i];
    for (int i = 1; i <= n; ++i) for (int j = 1; j < i; ++j) {
        int res = 0;
        int (&di)[103] = dist[i][j];
        for (int p = j; p < i; ++p) {
            di[p] = a[p] + l[p];
        }
        for (int p = j + 1; p < i; ++p) {
            di[p] = max(di[p], di[p - 1]);
        }
        for (int p = i - 1; p >= j; --p) {
            int from = max(di[p], a[i] - l[i]);
            int to = a[p + 1];
            if (to > from) res += to - from;
            pre[i][j][p] = res;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int end = i + 1;
        while (end <= n && a[end] < a[i] + l[i]) ++end;
        upto[i] = end - 1;
    }
    memset(d, -1, sizeof d);
    d[0][0][0] = 0;
    for (int cur = 1; cur <= n; ++cur) {
        memset(nd, -1, sizeof nd);
        REP(le, cur) REP(rile, cur) REP(ri, cur) if (d[le][rile][ri] != -1) {
            int nle = cur;
            int nrile = 0;
            if (ri != 0 && a[ri] + l[ri] > a[cur]) nrile = ri;
            int nri = 0;
            if (ri != 0 && a[ri] + l[ri] > a[cur]) nri = ri;
            int nres = d[le][rile][ri];
            int j = le + 1;
            if (rile != 0) j = max(j, upto[rile] + 1);
            if (j < cur) nres += pre[cur][le + 1][j];
            if (rile != 0 && upto[rile] > le && upto[rile] < cur) {
                int from = max(dist[cur][le + 1][upto[rile]], max(a[cur] - l[cur], a[rile] + l[rile]));
                int to = a[upto[rile] + 1];
                if (to > from) nres += to - from;
            }
            if (le == 0) {
                int from = a[cur] - l[cur];
                int to = a[1];
                if (to > from) nres += to - from;
            } else {
                int from = max(a[cur] - l[cur], a[le]);
                if (rile != 0) from = max(from, a[rile] + l[rile]);
                int to = a[le + 1];
                if (to > from) nres += to - from;
            }
            nd[nle][nrile][nri] = max(nd[nle][nrile][nri], nres);

            nle = le;
            nrile = rile;
            nri = ri;
            if (ri == 0 || a[cur] + l[cur] > a[ri] + l[ri]) nri = cur;
            nres = d[le][rile][ri];
            int pos = a[cur];
            if (ri != 0) pos = max(pos, a[ri] + l[ri]);
            nres += max(0, a[cur] + l[cur] - pos);
            nd[nle][nrile][nri] = max(nd[nle][nrile][nri], nres);
        }
        memcpy(d, nd, sizeof d);
    }
    int ans = 0;
    REP(i, n + 1) REP(j, n + 1) REP(k, n + 1) ans = max(ans, d[i][j][k]);
    cout << ans << endl;
    return 0;
}