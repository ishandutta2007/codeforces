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

int n, k;
int a[10000];

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    double lo = 0, hi = 1009, mid;
    REP(times, 200) {
        mid = (lo + hi) / 2;
        double pos = 0, neg = 0;
        REP(i, n) if (a[i] > mid) {
            pos += a[i] - mid;
        } else {
            neg += mid - a[i];
        }
        if (pos * (1 - 0.01 * k) >= neg) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    printf("%.12f\n", lo);
    return 0;
}