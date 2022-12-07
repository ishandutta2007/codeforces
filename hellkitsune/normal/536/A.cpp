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

int a, b, n;
int l, t, m;

int main() {
    scanf("%d%d%d", &a, &b, &n);
    REP(i, n) {
        scanf("%d%d%d", &l, &t, &m), --l;
        if (a + (LL)l * b > t) {
            printf("-1\n");
            continue;
        }
        int lo = l, hi = (t - a) / b + 5, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            LL cnt = a + mid * b, tot = ((mid - l + 1) * ((a + l * b) + cnt)) / 2;
            cnt = max(cnt, (tot + m - 1) / m);
            if (cnt > t)
                hi = mid - 1;
            else
                lo = mid;
        }
        printf("%d\n", lo + 1);
    }
    return 0;
}