#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 82;
int a[N];
int n;
int f[2][N][N][N * (N+ 1) / 2], ans[N * N];
void upd(int&x, int y) {
    x = max(x, y);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n;i ++) {
        int x;
        scanf("%d", &x);
        if (x == 1) a[++a[0]] = i;
    }
    bool bz = 0, bz1 = 1;
    f[0][0][0][0] = 1;
    int M = n * (n - 1) / 2;
    for (int i = 1; i <= n; i ++, swap(bz, bz1))
        for (int j = 0; j <= a[0]; j ++)
            for (int l = 0; l <= i; l ++)
                for (int k = 0; k <= M; k ++)
                    if (f[bz][j][l][k]) {
                        if (j != a[0] && abs(a[j + 1]- i) + k <= M) {
                            upd(f[bz1][j + 1][0][k + abs(a[j + 1] - i)], f[bz][j][l][k]);
                        }
                        upd(f[bz1][j][l + 1][k], f[bz][j][l][k] +  (i - 1 - j - l) * (j > 0));
                        f[bz][j][l][k] = 0;
                    }

    for (int i = 0; i <= M; i ++) {
        for (int j = 0; j <= n; j ++)
            ans[i] = max(ans[i], f[bz][a[0]][j][i] - 1);
        if (i) ans[i] = max(ans[i - 1], ans[i]);
        printf("%d%c", ans[i], " \n"[i == M]);
    }
    return 0;
}