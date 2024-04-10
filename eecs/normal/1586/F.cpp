#include <bits/stdc++.h>
using namespace std;

int n, K, ans;

int main() {
    scanf("%d %d", &n, &K);
    int x = n - 1;
    while (x) x /= K, ans++;
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = i - 1, y = j - 1, t = 0;
            while (x ^ y) x /= K, y /= K, t++;
            printf("%d ", t);
        }
    }
    return 0;
}