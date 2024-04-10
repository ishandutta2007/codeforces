#include <stdio.h>
#include <math.h>

using namespace std;
typedef long long ll;

#define MN 1001000

int main() {
    ll r, x1, y1, x2, y2;
    scanf("%lld %lld %lld %lld %lld", &r, &x1, &y1, &x2, &y2);
    if (x1 == x2 && y1 == y2) puts("0");
    else {
        double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        ll ans = 1;
        while (dist >= 2 * r + 1e-9) {
            ans++;
            dist -= 2*r;
        }
        printf("%lld\n", ans);
    }
    return 0;
}