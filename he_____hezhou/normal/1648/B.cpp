#include <bits/stdc++.h>
using namespace std;
int T, n, c;
int s[1000010], a[1000010];
void rmain() {
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= c; i++) a[i] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }
    for (int i = 1; i <= c; i++) s[i] = a[i] + s[i - 1];
    for (int i = 1; i <= c; i++) if (a[i]) {
        for (int j = i; j <= c; j += i) {
            int qwq = s[min(j + i - 1, c)] - s[j - 1];
            if (qwq && a[j / i] == 0) {
                puts("No");
                return;
            }
        }
    }
    puts("Yes");
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}