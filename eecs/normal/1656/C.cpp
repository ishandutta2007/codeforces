#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool flag = 0, zero = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (!a[i]) zero = 1;
            if (a[i] == 1) flag = 1;
        }
        if (!flag) {
            puts("YES");
        } else if (zero) {
            puts("NO");
        } else {
            sort(a + 1, a + n + 1);
            bool flag = 1;
            for (int i = 1; i < n; i++) {
                if (a[i] > 0 && a[i + 1] == a[i] + 1) flag = 0;
            }
            puts(flag ? "YES" : "NO");
        }
    }
    return 0;
}