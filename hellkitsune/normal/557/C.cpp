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
int l[100000], d[100000], ord[100000], nl[100000], nd[100000];
int a[201][100001] = {};

bool cmp(const int &lhs, const int &rhs) {
    return l[lhs] > l[rhs];
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", l + i);
    REP(i, n) scanf("%d", d + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) nl[i] = l[ord[i]], nd[i] = d[ord[i]];
    REP(i, n) l[i] = nl[i], d[i] = nd[i];
    REP(i, n) a[d[i]][i] = 1;
    REP(i, 201) for (int j = n - 2; j >= 0; --j)
        a[i][j] += a[i][j + 1];
    int tot = 0;
    REP(i, n) tot += d[i];
    int ans = tot;
    for (int beg = 0; beg < n; ) {
        int end = beg + 1;
        while (end < n && l[beg] == l[end]) ++end;
        int cur = 0, rem = end - beg - 1;
        for (int i = beg; i < end; ++i) cur += d[i];
        for (int i = 200; i >= 1; --i) if (a[i][end]) {
            if (a[i][end] > rem) {
                cur += rem * i;
                break;
            }
            cur += a[i][end] * i;
            rem -= a[i][end];
        }
        ans = min(ans, tot - cur);
        beg = end;
    }
    cout << ans << endl;
    return 0;
}