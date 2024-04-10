#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        int m , d, w;
        scanf("%d %d %d", &m, &d, &w);
        int x = __gcd(w, d - 1);
        w /= x;
        m = min(m, d);
        long long y = (m / w);
        printf("%lld\n", y * m - (y + 1) * y / 2 * w);
    }
    return 0;
}