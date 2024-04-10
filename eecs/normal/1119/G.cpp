#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, m, sum, hp[maxn], rem[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &hp[i]);
        rem[i] = (sum += hp[i]) % n;
    }
    rem[m] = n, sort(rem + 1, rem + m + 1);
    printf("%d\n", (sum + n - 1) / n);
    for (int i = m; i; i--) {
        rem[i] -= rem[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        printf("%d%c", rem[i], " \n"[i == m]);
    }
    int p = 1;
    for (int i = 1; i <= m; i++) {
        for (; hp[i] > 0; p = p % m + 1) {
            printf("%d%c", i, " \n"[p == m]), hp[i] -= rem[p];
        }
    }
    if (p > 1) {
        for (; p <= m; p++) {
            printf("%d%c", m, " \n"[p == m]);
        }
    }
    return 0;
}