#include <bits/stdc++.h>
using namespace std;

int m, n;
double ans;

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        ans += 1 - pow(1.0 * (m - i) / m, n);
    }
    printf("%.9f\n", ans);
    return 0;
}