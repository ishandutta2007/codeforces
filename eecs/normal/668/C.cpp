#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n;
double mn[maxn], mx[maxn], a[maxn], b[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &mx[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &mn[i]);
    }
    double pa = 1, pb = 1;
    for (int i = n; i; i--) {
        // a[i] * pb + b[i] * pa - a[i] * b[i] = mx[i]
        // a[i] * sb + b[i] * sa + a[i] * b[i] = mn[i]
        double x = 1;
        double y = pb - pa - mn[i] - mx[i];
        double z = (mn[i] + mx[i]) * pa - mx[i];
        double d = sqrt(max(0.0, y * y - 4 * x * z));
        double a1 = (-y + d) / (2 * x);
        double a2 = (-y - d) / (2 * x);
        a[i] = max(0.0, a1), b[i] = mn[i] + mx[i] - a[i];
        pa -= a[i], pb -= b[i];
    }
    for (int i = 1; i <= n; i++) {
        printf("%.6f%c", a[i], " \n"[i == n]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%.6f%c", b[i], " \n"[i == n]);
    }
    return 0;
}