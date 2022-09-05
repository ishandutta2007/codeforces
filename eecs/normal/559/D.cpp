#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, x[maxn], y[maxn];
double ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        x[i + n] = x[i], y[i + n] = y[i];
    }
    auto area = [&](int i, int j, int k) {
        return 1LL * (x[j] - x[i]) * (y[k] - y[j]) - 1LL * (x[k] - x[j]) * (y[j] - y[i]);
    };
    double tmp = pow(2, -n);
    for (int i = 1; i <= n; i++) {
        double pw = 0.25;
        for (int j = i + 1; j < min(i + n, i + 50); j++, pw /= 2) {
            ans -= __gcd(abs(x[i] - x[j]), abs(y[i] - y[j])) * (pw - tmp) / 2;
            ans += (1LL * x[i] * y[j] - 1LL * x[j] * y[i]) * (pw - tmp) / 2;
        }
    }
    if (n <= 50) {
        ans *= 1LL << n;
        ans /= (1LL << n) - n * (n - 1) / 2 - n - 1;
    }
    printf("%.12f\n", ans + 1);
    return 0;
}