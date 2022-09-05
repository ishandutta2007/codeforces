#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, t[maxn], f[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        f[i] = f[i - 1] + 20;
        for (int j = i - 1; j > max(0, i - 1440); j--) {
            if (t[i] - t[j] < 1440) f[i] = min(f[i], f[j - 1] + 120);
            if (t[i] - t[j] < 90) f[i] = min(f[i], f[j - 1] + 50);
        }
        printf("%d\n", f[i] - f[i - 1]);
    }
    return 0;
}