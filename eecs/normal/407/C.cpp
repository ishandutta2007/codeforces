#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, m, a[maxn], s[maxn][110], binom[maxn][110];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= 100005; i++) {
        for (int j = binom[i][0] = 1; j <= min(100, i); j++) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % P;
        }
    }
    while (m--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        for (int i = 0; i <= k; i++) {
            s[l][i] = (s[l][i] + binom[k][k - i]) % P;
            s[r + 1][i] = (s[r + 1][i] - binom[r - l + 1 + k][k - i] + P) % P;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 101; j; j--) {
            s[i + 1][j - 1] = (1LL * s[i + 1][j - 1] + s[i][j] + s[i][j - 1]) % P;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", (a[i] + s[i][0]) % P);
    }
    return 0;
}