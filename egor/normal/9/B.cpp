#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n, vb, vs;
    scanf("%d%d%d", &n, &vb, &vs);
    vector <int> x(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    int xr, yr;
    scanf("%d%d", &xr, &yr);
    int ans = -1;
    double t = 1e100;
    double dist = 1e100;
    for (int i = 1; i < n; i++) {
        double ct = double(x[i]) / vb + hypot(double(xr - x[i]), double(yr)) / vs;
        double cdist = hypot(double(xr - x[i]), double(yr));
        
        if (ct < t - 1e-8 || ct < t + 1e-8 && cdist < dist) {
            ans = i + 1;
            dist = cdist;
            t = ct;
        }
    }
    printf("%d\n", ans);
    return 0;
}