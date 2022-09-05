#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int g = 0;
        for (int i = 0; i < 30; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (a[j] >> i & 1) cnt++;
            }
            g = __gcd(g, cnt);
        }
        for (int i = 1; i <= n; i++) if (!(g % i)) {
            printf("%d ", i);
        }
        putchar('\n');
    }
    return 0;
}