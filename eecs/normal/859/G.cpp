#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn], b[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%1d", &a[i]);
    }
    int x = n;
    for (int i = 2; i <= x; i++) if (!(x % i)) {
        while (!(x % i)) x /= i;
        copy(a, a + n, b);
        for (int j = 0; j < n; j++) a[j] = b[(j + n / i) % n] - b[j];
    }
    puts(count(a, a + n, 0) == n ? "YES" : "NO");
    return 0;
}