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

int n, k, p, x, y;

int main() {
    scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
    int cnt = 0, sum = 0;
    REP(i, k) {
        int mark;
        scanf("%d", &mark);
        sum += mark;
        if (mark >= y)
            ++cnt;
    }
    sum += n - k;
    if (sum > x) {
        printf("-1\n");
        return 0;
    }
    int ext = 0;
    if (y == 1) cnt += ext = n - k;
    else cnt += ext = min(n - k, (x - sum) / (y - 1));
    if (cnt < (n + 1) / 2) {
        printf("-1\n");
        return 0;
    }
    REP(i, ext) printf("%d ", y);
    REP(i, n - k - ext) printf("1 ");
    printf("\n");
    return 0;
}