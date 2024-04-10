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

int n = 0, m, cnt;
int l[100000], r[100000], s[100000];
int sum[100001], revL[200001], revR[200001];
int d[100001];

int main() {
    scanf("%d%d", &cnt, &m);
    REP(i, cnt) scanf("%d", sum + i);
    REP(i, m) scanf("%d", s + i);
    sort(sum, sum + cnt);
    sort(s, s + m);
    int pre = -3;
    REP(i, cnt) {
        if (pre < sum[i] - 1) {
            pre = l[n] = r[n] = sum[i];
            ++n;
        } else {
            pre = r[n - 1] = sum[i];
        }
    }
    sum[0] = 0;
    REP(i, n) sum[i + 1] = sum[i] + r[i] - l[i] + 1;
    int pos = 0;
    REP(i, 200001) {
        while (pos < n && sum[pos + 1] <= i) ++pos;
        revL[i] = pos;
    }
    pos = n;
    REP(i, 200001) {
        while (pos > 0 && sum[n] - sum[pos - 1] <= i) --pos;
        revR[i] = pos;
    }
    REP(i, n + 1) d[i] = 0;
    REP(i, n) {
        if (i) d[i] = max(d[i], d[i - 1]);
        int from = lower_bound(s, s + m, l[i]) - s;
        int to = upper_bound(s, s + m, r[i]) - s;
        int best = d[i] + to - from;
        for (int x = from - 1; x >= 0; --x) {
            int val = sum[i] - l[i] + s[x];
            if (val < 0) break;
            best = max(best, d[revL[val]] + to - x);
        }
        d[i + 1] = max(d[i + 1], best);
        for (int x = to; x < m; ++x) {
            int val = sum[n] - sum[i + 1] - s[x] + r[i];
            if (val < 0) break;
            d[revR[val]] = max(d[revR[val]], best + x - to + 1);
        }
    }
    printf("%d\n", d[n]);
    return 0;
}