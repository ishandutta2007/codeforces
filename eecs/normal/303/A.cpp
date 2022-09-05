#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn], b[maxn];

int main() {
    scanf("%d", &n);
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            printf("%d%c", a[i] = i, " \n"[i == n - 1]);
        }
        for (int i = 0; i < n; i++) {
            printf("%d%c", b[i] = (i + 1) % n, " \n"[i == n - 1]);
        }
        for (int i = 0; i < n; i++) {
            printf("%d%c", (a[i] + b[i]) % n, " \n"[i == n - 1]);
        }
    } else {
        puts("-1");
    }
    return 0;
}