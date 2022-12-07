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
int x[1000000], y[1000000], rev[1000000];
int d[1000002];
const int INF = 1e9;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", x + i), --x[i];
    REP(i, n) scanf("%d", y + i), --y[i];
    REP(i, n) rev[y[i]] = i;
    REP(i, n) x[i] = rev[x[i]];
    reverse(x, x + n);
    REP(i, n + 2) d[i] = INF;
    d[0] = -1;
    REP(i, n) {
        int val = x[i];
        int pos = upper_bound(d, d + n, val - 1) - d;
        d[pos] = min(d[pos], val);
    }
    int ans = 0;
    while (d[ans] != INF) ++ans;
    printf("%d\n", ans - 1);
    return 0;
}