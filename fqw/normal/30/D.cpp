#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

typedef long long int64;
typedef unsigned long long qword;
typedef unsigned int uint;

const int INFI_INT = 1<<30;
const int64 INFI_INT64 = (int64)(1<<30) * (int64)(1<<30);
const double PI = acos(-1);

template <class T> T sqr(T x) { return x * x; }
template <class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }
template <class T> T absval(T x) { return x > 0 ? x : -x; }

#define forint(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)
#define forintdown(i, s, t) for (int i = (int)(s); i >= (int)(t); -- i)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define movechar(a, b) memmove(b, a, sizeof(a))

double x[100010], x_0, y_0;
int n, start;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

double d0(int i) {
    return dist(x_0, y_0, x[i], 0.0);
}

double cal(int st, int en) {
    if (st <= start && start <= en) {
        return x[en] - x[st] + min(x[en] - x[start] + d0(st), x[start] - x[st] + d0(en));
    } else {
        return x[en] - x[st] + min(d0(st), d0(en));
    }
}

void solve() {
    scanf("%d%d", &n, &start);
    forint (i, 1, n)
        scanf("%lf", &x[i]);
    scanf("%lf%lf", &x_0, &y_0);
    double start_x = x[start];
    sort(x+1, x+n+1);
    if (start <= n)
        forint (i, 1, n)
            if (fabs(x[i]-start_x) < 1e-5)
                start = i;
    
    double ans = 1E50;
    if (start == n+1)
        ans = min(d0(1), d0(n)) + x[n] - x[1];
    else {
        ans = min(ans, x[start]-x[1] + x[n]-x[1] + d0(n));
        ans = min(ans, x[n]-x[start] + x[n]-x[1] + d0(1));
        forint (i, 1, n-1)
            ans = min(ans, cal(1, i) + cal(i+1, n));
    }
    printf("%.9lf\n", ans);
}

int main() {
    /*
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
    //*/
    //while(1)
    solve();
    return 0;
}