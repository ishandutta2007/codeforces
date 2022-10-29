#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;
const int N = 1e5 + 10;
int n;
long long k, all;
long long a[N], b[N];
long long calc(long long a, long long b, long long c) {
    return (-b - sqrtl((long double) b * b - (long double)4 * a * c)) / (2 * a);
}
long long get(long long v) {
    long long sum = 0;
    for (int i = 1; i <= n; i ++)
        b[i] = min(max(1ll * 0, calc(-3, 3, -1 - v + a[i])), a[i]), sum += b[i];
    return sum;
}
long long calc1(long long a, long long b) {
    return a - b * b * 3 + 3 * b - 1;
}
int main() {
    scanf("%d %lld", &n, &k);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]);
    long long l = LONG_LONG_MIN, r = LONG_LONG_MAX, s = LONG_LONG_MIN, mid = 0;
    while (l <= r) {
        if (get(mid =  (l / 2 +  r/ 2 + ((l & 1 )&&(r & 1))) ) >= k) l = mid +1, s = max(s, mid);
        else
            r = mid - 1;
    }
    long long delta = get(s) - k;
    for (int i = 1; i <= n && delta; i ++)
        while (b[i] && calc1(a[i], b[i]) == s)
            b[i] --, delta --;
    for (int i= 1; i <= n; i ++)
        printf("%lld%c", b[i], " \n"[i == n]);
    return 0;
}