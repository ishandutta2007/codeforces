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
int x[100000], y[100000], a[100000];
bool ok[100000] = {};

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", x + i);
    REP(i, n) scanf("%d", y + i);
    REP(i, n) a[i] = x[i] - y[i];
    for (int i = 1; i < n; ++i) a[i] += a[i - 1];
    int lo = a[0];
    REP(i, n) lo = min(lo, a[i]);
    REP(i, n) if (a[i] == lo) {
        ok[(i + 1) % n] = true;
    }
    REP(i, n) a[i] = x[n - 1 - i] - y[(2 * n - 2 - i) % n];
    for (int i = 1; i < n; ++i) a[i] += a[i - 1];
    lo = a[0];
    REP(i, n) lo = min(lo, a[i]);
    REP(i, n) if (a[i] == lo) {
        ok[(2 * n - 2 - i) % n] = true;
    }
    int cnt = 0;
    REP(i, n) if (ok[i]) ++cnt;
    printf("%d\n", cnt);
    REP(i, n) if (ok[i]) printf("%d ", i + 1);
    printf("\n");
    return 0;
}