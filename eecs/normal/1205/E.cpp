#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, K, ans, mu[maxn], pw[maxn];
vector<int> sum[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = pw[0] = 1; i <= n; i++) {
        pw[i] = 1LL * K * pw[i - 1] % P;
    }
    for (int i = mu[1] = 1; i <= n; i++) {
        for (int j = i + i; j <= n; j += i) {
            mu[j] = (mu[j] - mu[i] + P) % P;
        }
        sum[i] = {0};
        for (int j = i; j <= n; j += i) {
            sum[i].push_back((sum[i].back() + pw[j]) % P);
        }
    }
    int foo = qp(pw[n], P - 2);
    for (int g = 1; g < n; g++) {
        for (int d = 1; d * g < n; d++) {
            int m = (n + g) / d / g + 1, b = (n - 1) / d / g;
            for (int i = 1; i <= b; i++) {
                int j = min(b, m - 1 - i);
                ans = (ans + 1LL * mu[d] * pw[g] % P * j) % P;
                ans = (ans + 1LL * mu[d] * foo % P * pw[i * d * g] % P * (sum[d * g][b] - sum[d * g][j] + P)) % P;
            }
        }
    }
    printf("%lld\n", 1LL * ans * foo % P);
    return 0;
}