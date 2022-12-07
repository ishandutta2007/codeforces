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

int n, a[200000];

double solve(double x) {
    double sum = 0, rev = 0, ret = 0;
    REP(i, n) {
        sum += a[i] + x;
        rev += -(a[i] + x);
        if (sum < 0) sum = 0;
        if (rev < 0) rev = 0;
        ret = max(ret, sum);
        ret = max(ret, rev);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    double lo = -10000, hi = 10000;
    REP(times, 150) {
        double x = (2 * lo + hi) / 3;
        double y = (lo + 2 * hi) / 3;
        if (solve(x) < solve(y)) {
            hi = y;
        } else {
            lo = x;
        }
    }
    printf("%.15f\n", solve(lo));
    return 0;
}