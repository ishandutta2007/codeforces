#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n;
double ans, p[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
        if (p[i] == 0) i--, n--;
        if (p[i] == 1) puts("1"), exit(0);
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
        double prod = 1, sum = 0;
        for (int j = i; j <= n; j++) {
            prod *= 1 - p[j], sum += p[j] / (1 - p[j]);
            ans = max(ans, prod * sum);
        }
    }
    printf("%.9f\n", ans);
    return 0;
}