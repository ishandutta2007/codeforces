#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
inline long long calc(long long x) {
    long long ans = 1e18;
    for (int i = 2; 1ll * i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            long long now = 0;
            for (int j = 1; j <= n; j++) {
                if (a[j] < i) now += i - a[j];
                else now += min(a[j] % i, i - a[j] % i);
            }
            ans = min(ans, now);
        }
    }
    if (x > 1) {
        long long now = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] < x) now += x - a[j];
            else now += min(a[j] % x, x - a[j] % x);
        }
        ans = min(ans, now);
    }
    return ans;
}
inline int Rand() {
    return (rand() & 65535) << 15 | rand();
}
int main() {
    srand(time(0));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    random_shuffle(a + 1, a + 1 + n);
    long long ans = 1e18;
    for (int i = 1; i <= 50; i++) {
        int id = Rand() % n + 1;
        ans = min(ans, calc(a[id]));
        if (a[id] > 1) ans = min(ans, calc(a[id] - 1));
        ans = min(ans, calc(a[id] + 1));
    }
    return cout << ans << endl, 0;
}