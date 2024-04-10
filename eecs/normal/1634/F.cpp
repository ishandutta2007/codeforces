#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, q, P, a[maxn], b[maxn], fib[maxn];
int w[maxn][25], s1[25], s2[25];
array<int, 2> coef[maxn][25];
mt19937_64 rnd(time(0));

int main() {
    scanf("%d %d %d", &n, &q, &P);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= n + 1; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % P;
    }
    for (int j = n; j; j--) {
        for (int i = 0; i < 25; i++) {
            w[j][i] = rnd() % P;
            coef[j][i][0] = coef[j + 1][i][1];
            coef[j][i][1] = (1LL * coef[j + 1][i][0] + coef[j + 1][i][1] + w[j][i]) % P;
            s1[i] = (s1[i] + 1LL * a[j] * w[j][i]) % P;
            s2[i] = (s2[i] + 1LL * b[j] * w[j][i]) % P;
        }
    }
    while (q--) {
        char op[2];
        int l, r;
        scanf("%s %d %d", op, &l, &r), r++;
        if (P == 1) { puts("YES"); continue; }
        if (op[0] == 'A') {
            for (int i = 0; i < 25; i++) {
                s1[i] = (s1[i] + 1LL * (P - fib[r - l]) * coef[r][i][0] + coef[l][i][1] + 1LL * (P - fib[r - l + 1]) * coef[r][i][1]) % P;
            }
        } else {
            for (int i = 0; i < 25; i++) {
                s2[i] = (s2[i] + 1LL * (P - fib[r - l]) * coef[r][i][0] + coef[l][i][1] + 1LL * (P - fib[r - l + 1]) * coef[r][i][1]) % P;
            }
        }
        bool flag = 1;
        for (int i = 0; i < 25 && flag; i++) flag &= s1[i] == s2[i];
        puts(flag ? "YES" : "NO");
    }
    return 0;
}