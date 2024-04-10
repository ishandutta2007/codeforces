#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>
#include <queue>


using namespace std;


const long double eps = 1e-9;
const int MaxN = 10007;
long double x[MaxN], y[MaxN];
long double w, v, u;
int n;


bool good(double t0) {
    bool wasLeft = false;
    bool wasRight = false;
    for (int i = 1; i <= n; i++) {
        double t = t0 + y[i] / u;
        double curPos = x[i] - v * t;
        if (curPos < 0) {
            wasLeft = true;
        } else {
            wasRight = true;
        }
    }
    if (wasLeft && !wasRight) {
        return true;
    }
    if (!wasLeft && wasRight) {
        return true;
    }
    return false;
}


int main() {
    scanf("%d", &n);
    double xx;
    scanf("%lf", &xx);
    w = xx;
    scanf("%lf", &xx);
    v = xx;
    scanf("%lf", &xx);
    u = xx;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &xx);
        x[i] = xx;
        scanf("%lf", &xx);
        y[i] = xx;
    }
    long double l = 0, r = 1e10;
    if (good(0)) {
        r = 0;
    }
    for (int i = 1; i <= 800; i++) {
        long double m = (l + r) / 2;
        if (good(m))  {
            r = m;
        } else {
            l = m;
        }
    }
    printf("%.20lf\n", (double)((l + r) / 2 + w / u));
    return 0;
}