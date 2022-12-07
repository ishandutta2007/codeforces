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
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int INF = 1e9;

int n, k;
int a[30000], sum[30001];
int neg[30001] = {}, pos[30001] = {}, _neg[30001], _pos[30001];

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    sum[0] = 0;
    REP(i, n) sum[i + 1] = sum[i] + a[i];

    int best = pos[0] = -INF;
    for (int j = 0; j < n; ++j) {
        best = max(best, -sum[j]);
        pos[j + 1] = max(pos[j], sum[j + 1] + best);
    }
    best = neg[0] = -INF;
    for (int j = 0; j < n; ++j) {
        best = max(best, sum[j]);
        neg[j + 1] = max(neg[j], -sum[j + 1] + best);
    }

    for (int i = 1; i < k - 1; ++i) {
        int best = -INF;
        for (int j = i; j < n; ++j) {
            best = max(best, -2 * sum[j] + neg[j]);
            _pos[j + 1] = 2 * sum[j + 1] + best;
        }
        best = -INF;
        for (int j = i; j < n; ++j) {
            best = max(best, neg[j]);
            _neg[j + 1] = best;
        }
        best = -INF;
        for (int j = i; j < n; ++j) {
            best = max(best, 2 * sum[j] + pos[j]);
            _neg[j + 1] = max(_neg[j + 1], -2 * sum[j + 1] + best);
        }
        best = -INF;
        for (int j = i; j < n; ++j) {
            best = max(best, pos[j]);
            _pos[j + 1] = max(_pos[j + 1], best);
        }
        neg[i + 1] = _neg[i + 1];
        pos[i + 1] = _pos[i + 1];
        for (int j = i + 2; j <= n; ++j) {
            neg[j] = max(neg[j - 1], _neg[j]);
            pos[j] = max(pos[j - 1], _pos[j]);
        }
    }

    int ans = 0;
    best = -INF;
    for (int j = k - 1; j < n; ++j) {
        best = max(best, -sum[j] + neg[j]);
        ans = max(ans, sum[j + 1] + best);
    }
    best = -INF;
    for (int j = k - 1; j < n; ++j) {
        best = max(best, sum[j] + pos[j]);
        ans = max(ans, -sum[j + 1] + best);
    }

    printf("%d\n", ans);
    return 0;
}