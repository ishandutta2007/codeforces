#include <algorithm>
#include <cstdio>
using namespace std;
long long calc(long long x) {
    return x * (x + 1) / 2;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n, r;
        scanf("%d %d", &n, &r);
        r = min(r, n);
        if (r == n)
            printf("%lld\n", calc(r - 1) +1);
        else
            printf("%lld\n", calc(r));
    }
    return 0;
}