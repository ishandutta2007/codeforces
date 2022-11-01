#include <bits/stdc++.h>

using namespace std;

int n;
double a, d, t, v;

int main() {
    scanf("%d %lf %lf", &n, &a, &d);
    double last = 0;
    for(int i=0; i<n; i++) {
        scanf("%lf %lf", &t, &v);

        double t1 = 0, t2 = 0, tf = 0, da = 0;
        t1 = v / a;
        da = v * v / (2 * a);

        if(da >= d) {
            tf = t + sqrtl(2 * d / a);
        } else {
            tf = t + t1 + (d - da) / v;
        }

        tf = max(last, tf);
        printf("%.9f\n", tf);
        last = tf;
    }
    return 0;
}