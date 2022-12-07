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
int c[2001], r[2001], ord[2001], nc[2001], nr[2001];
bool used[2001] = {};
vector<int> ans[2001];
int cnt[2001] = {};
int d[2001], p[2001];
bool take[2001];
vector<int> ret;

bool cmp(const int &lhs, const int &rhs) {
    return c[lhs] + r[lhs] < c[rhs] + r[rhs];
}

void go(int v) {
    if (ord[v] != n - 1)
        ret.pb(ord[v] + 1);
    for (int to : ans[v]) go(to);
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", c + i, r + i);
    c[n] = 500000000; r[n] = 1500000005;
    ++n;
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) nc[i] = c[ord[i]], nr[i] = r[ord[i]];
    REP(i, n) c[i] = nc[i], r[i] = nr[i];
    REP(i, n) {
        int v = -1;
        REP(j, n) if (!used[j] && (v == -1 || r[j] < r[v])) {
            v = j;
        }
        int ll = c[v] - r[v];
        int rr = c[v] + r[v];
        REP(j, n) {
            if (j == 0) d[j] = 0;
            else d[j] = d[j - 1];
            p[j] = j - 1;
            take[j] = false;
            if (used[j] && c[j] - r[j] >= ll && c[j] + r[j] <= rr) {
                int lo = -1, hi = j - 1, mid;
                while (lo < hi) {
                    mid = (lo + hi + 1) >> 1;
                    if (c[mid] + r[mid] <= c[j] - r[j])
                        lo = mid;
                    else
                        hi = mid - 1;
                }
                int cur = cnt[j];
                if (lo != -1) cur += d[lo];
                if (cur > d[j]) {
                    d[j] = cur;
                    take[j] = true;
                    p[j] = lo;
                }
            }
        }
        cnt[v] = d[n - 1] + 1;
        used[v] = true;
        for (int j = n - 1; j >= 0; j = p[j]) {
            if (take[j]) ans[v].pb(j);
        }
    }
    go(n - 1);
    printf("%d\n", (int)ret.size());
    for (int x : ret) printf("%d ", x);
    printf("\n");
    return 0;
}