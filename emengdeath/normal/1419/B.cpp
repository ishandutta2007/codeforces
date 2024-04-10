#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    long long f[100], len[100];
    f[1] = 1;
    len[1] = 1;
    int i = 1;
    while (f[i] <= 1e18)
        len[i + 1] = len[i] * 2 + 1, f[i +1] = (len[i + 1] + 1) * len[i + 1] / 2 + f[i], i ++;
    int T;
    scanf("%d", &T);
    while (T --) {
        long long n;
        scanf("%lld", &n);
        printf("%d\n", upper_bound(f +1, f + i + 1, n) - f - 1);
    }
    return 0;
}