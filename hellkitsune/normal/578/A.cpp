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

int a, b;
const int MX = 1e9 + 111;

int main() {
    scanf("%d%d", &a, &b);
    if (b > a) {
        printf("-1\n");
        return 0;
    }
    if (a == b) {
        printf("%d\n", a);
        return 0;
    }
    double x = 1e50;
    int lo = 0, hi = MX, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (a - b < b * 2ll * mid) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    if (lo > 0) {
        x = (a - b) / (2.0 * lo);
    }

    lo = 0, hi = MX;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (a + b < b * 2ll * (mid + 1)) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    x = min(x, (a + b) / (2.0 * (lo + 1)));

    printf("%.15f\n", x);
    return 0;
}