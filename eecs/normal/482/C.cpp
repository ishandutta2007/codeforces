#include <bits/stdc++.h>
using namespace std;

int n, A;
long long ban[1 << 20];
char s[55][21];
double f[1 << 20];
mt19937 rnd(time(0));

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]), A = strlen(s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (i ^ j) {
            int S = 0;
            for (int k = 0; k < A; k++) {
                if (s[i][k] == s[j][k]) S |= 1 << k;
            }
            ban[S] |= 1LL << i;
        }
    }
    for (int i = (1 << A) - 1; ~i; i--) {
        for (int j = 0; j < A; j++) if (!(i >> j & 1)) {
            ban[i] |= ban[i | (1 << j)];
        }
        int cnt = n - __builtin_popcountll(ban[i]), t = __builtin_popcount(i);
        if (i < (1 << A) - 1) {
            for (int j = 0; j < A; j++) if (!(i >> j & 1)) {
                f[i] += f[i | (1 << j)];
            }
            f[i] /= A - t;
        }
        f[i] += cnt;
    }
    printf("%.10f\n", A + 1 - f[0] / n);
    return 0;
}