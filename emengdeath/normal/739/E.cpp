#include <algorithm>
#include <cstdio>
#include <assert.h>
using namespace std;
const int N = 2001;
int n, a, b;
double p[N], q[N];
double f[N];
int cnt[N][2];
void work(double P, double Q) {
    for (int i = 1; i <= n; i ++) {
        f[i] = 0;
        cnt[i][0] = cnt[i][1] = 0;
        if (p[i] - P >= f[i])
            f[i] = p[i] - P, cnt[i][0] = 1;
        if (q[i] - Q >= f[i])
            f[i] = q[i] - Q, cnt[i][0] = 0, cnt[i][1] = 1;
        if (p[i] + q[i] - P - Q - p[i] * q[i] >= f[i])
            f[i] = p[i] + q[i] - P - Q - p[i] * q[i], cnt[i][0] = cnt[i][1] = 1;
        cnt[i][0] += cnt[i - 1][0];
        cnt[i][1] += cnt[i - 1][1];
        f[i] += f[i - 1];
    }
}
int main() {
    scanf("%d %d %d", &n, &a, &b);
    for (int i= 1; i <= n; i ++)
        scanf("%lf", &p[i]);
    for (int i= 1; i <= n; i ++)
        scanf("%lf", &q[i]);
    double l = 0, r = 1, mid, l1, r1, mid1;
    for (int i = 0; i < 40; i ++){
        mid=  (l + r) / 2;
        l1 = 0, r1 = 1, mid1;
        for (int j = 0; j < 40; j ++){
            mid1 = (l1 + r1) / 2;
            work(mid, mid1);
            if (cnt[n][1] >= b) {
                l1 = mid1;
            } else
                r1 = mid1;
        }
        work(mid, l1);
        if (cnt[n][0] >= a) {
            l = mid;
        } else
            r = mid;
    }
    work(l, l1);
    printf("%.10f\n", f[n] + a * l + b * l1);
    return 0;
}