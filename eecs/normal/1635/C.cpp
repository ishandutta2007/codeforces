#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int T, n;
ll a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        if (is_sorted(a + 1, a + n + 1)) {
            puts("0");
        } else if (a[n - 1] > a[n] || a[n] < 0) {
            puts("-1");
        } else {
            printf("%d\n", n - 2);
            for (int i = n - 2; i; i--) {
                printf("%d %d %d\n", i, i + 1, n);
            }
        }
    }
    return 0;
}