#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K, cnt[maxn];
long long ans;

int main() {
    scanf("%d %d", &n, &K);
    while (n--) {
        int x, y = 1;
        long long z = 1;
        scanf("%d", &x);
        for (int i = 2; i * i <= x; i++) if (!(x % i)) {
            int c = 0;
            while (!(x % i)) x /= i, c++;
            c %= K;
            for (int j = 0; j < (K - c) % K; j++) z = min(100001LL, z * i);
            while (c--) y *= i;
        }
        if (x > 1) {
            y *= x;
            for (int i = 0; i < K - 1; i++) z = min(100001LL, z * x);
        }
        ans += cnt[z], cnt[y]++;
    }
    printf("%lld\n", ans);
    return 0;
}