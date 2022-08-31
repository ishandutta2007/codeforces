#include <bits/stdc++.h>
using namespace std;
int t, n, a[110];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        for (int i = 2; i <= n; i += 2) {
            if (abs(a[i]) < abs(a[i - 1])) {
                if (a[i - 1] > 0) a[i] = -abs(a[i]), a[i + 1] = abs(a[i + 1]);
                else a[i] = abs(a[i]), a[i + 1] = -abs(a[i + 1]);
            }
            else {
                a[i] = -abs(a[i]), a[i + 1] = abs(a[i + 1]);
            }
        }
        for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
    }
}