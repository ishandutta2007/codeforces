#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, ans, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        long long s = 0;
        for (int j = i + 1; j < n; j++) {
            if ((s += a[j]) > 2 * a[i]) break;
            if (a[i] >= a[j + 1] && s == (a[i] ^ a[j + 1])) ans++;
        }
    }
    for (int i = n; i; i--) {
        long long s = 0;
        for (int j = i - 1; j > 1; j--) {
            if ((s += a[j]) > 2 * a[i]) break;
            if (a[i] > a[j - 1] && s == (a[i] ^ a[j - 1])) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}