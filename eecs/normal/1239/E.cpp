#include <bits/stdc++.h>
using namespace std;

int n, a[55], b[2][30];
bitset<1250010> f[55][30];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 2 * n + 1);
    b[0][1] = a[1], b[1][n] = a[2];
    for (int i = 3; i <= 2 * n; i++) {
        a[i - 2] = a[i];
    }
    int all = accumulate(a + 1, a + 2 * n - 1, 0);
    f[0][0][0] = 1;
    for (int i = 1; i <= 2 * n - 2; i++) {
        f[i][0][0] = 1;
        for (int j = 1; j <= min(i, n - 1); j++) {
            f[i][j] = (f[i - 1][j - 1] << a[i]) | f[i - 1][j];
        }
    }
    int l = n + 1, r = 0;
    function<void(int, int, int)> print = [&](int i, int j, int k) {
        if (!i) return;
        if (f[i - 1][j][k]) b[1][++r] = a[i], print(i - 1, j, k);
        else b[0][--l] = a[i], print(i - 1, j - 1, k - a[i]);
    };
    for (int i = all / 2; i; i--) {
        if (f[2 * n - 2][n - 1][i]) { print(2 * n - 2, n - 1, i); break; }
    }
    for (int i : {0, 1}) {
        for (int j = 1; j <= n; j++) printf("%d ", b[i][j]);
        putchar('\n');
    }
    return 0;
}