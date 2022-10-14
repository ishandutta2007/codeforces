#line 1 "sol.cpp"
#include <bits/stdc++.h>

int n, last[1'000'001];

int main() {
    memset(last, -1, sizeof(last));
    scanf("%d", &n);
    long long result = 0, sum = 0;
    for (int i = 0, a; i < n; ++ i) {
        scanf("%d", &a);
        // (last[a] ... i]
        sum += i - last[a];
        result += 2 * sum - 1;
        last[a] = i;
    }
    printf("%.9f\n", 1.0 * result / n / n);
}