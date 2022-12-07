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

int n, x, y;

inline int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    scanf("%d%d%d", &n, &x, &y);
    if (x == y) {
        REP(i, n) printf("Both\n");
        return 0;
    }
    REP(i, n) {
        int cnt;
        scanf("%d", &cnt);
        int g = gcd(x, y);
        x /= g, y /= g;
        cnt %= x + y;
        if (cnt == 0 || cnt == x + y - 1) {
            printf("Both\n");
            continue;
        }
        LL lo = 0, hi = (LL)x * y, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (mid / x + mid / y < cnt)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (lo % x == 0) {
            printf("Vova\n");
        } else {
            printf("Vanya\n");
        }
    }
    return 0;
}