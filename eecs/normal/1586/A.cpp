#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int s = accumulate(a + 1, a + n + 1, 0);
        bool flag = 0;
        for (int i = 2; i < s; i++) {
            if (!(s % i)) flag = 1;
        }
        if (flag) {
            printf("%d\n", n);
            for (int i = 1; i <= n; i++) printf("%d ", i);
            putchar('\n');
        } else {
            printf("%d\n", n - 1);
            bool fir = 0;
            for (int i = 1; i <= n; i++) {
                if (!(a[i] % 2) || fir) printf("%d ", i);
                else fir = 1;
            }
            putchar('\n');
        }
    }
    return 0;
}