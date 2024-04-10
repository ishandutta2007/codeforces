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
int x[3000], c[3001], ord[3000], nx[3000], nc[3000];
LL sum[3000];
LL d[3001];
const LL INF = 1e18;

bool cmp(const int &lhs, const int &rhs) {
    return x[lhs] < x[rhs];
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, c + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) nc[i] = c[ord[i]], nx[i] = x[ord[i]];
    REP(i, n) c[i] = nc[i], x[i] = nx[i];
    sum[0] = x[0];
    for (int i = 1; i < n; ++i) sum[i] = sum[i - 1] + x[i];
    REP(i, n + 1) d[i] = INF;
    d[0] = c[0];
    c[n] = 0;
    REP(i, n) for (int j = i + 1; j <= n; ++j) {
        d[j] = min(d[j], c[j] + d[i] + sum[j - 1] - sum[i] - LL(j - i - 1) * x[i]);
    }
    cout << d[n] << endl;
    return 0;
}