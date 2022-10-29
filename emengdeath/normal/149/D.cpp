#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N = 1e3;
char s[N];
int r[N], d[N];
int f[N][N][3][3];
int F[2][3];
int n;
const int mod = 1e9 + 7;
int add(int x, int y) {
    return (x + y) % mod;
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
int main() {
    scanf("%s", s + 1);
    s[0] = '(';
    n = strlen(s);
    s[n] = ')';
    n ++;
    for (int i = 0; i < n; i ++)
        if (s[i] == '(') {
            d[++d[0]] = i;
        } else {
            r[d[d[0]]] = i;
            d[0] --;
        }
    bool bz = 0, bz1 = 1;
    for (int i = 2; i <= n; i += 2)
        for (int l = 0; l + i - 1 < n; l ++)
            if (r[l] == l + i - 1) {
                for (int cl = 0; cl <= 2; cl ++)
                    for (int cr = 0; cr <= 2; cr ++) {
                        if (i != n && ((!cl && !cr) || (cl && cr))) continue;
                        if (i == 2) {
                            f[l][r[l]][cl][cr] = 1;
                            continue;
                        }
                        memset(F, 0, sizeof(F));
                        F[bz][cl] = 1;
                        for (int j = l + 1; j < r[l]; j = r[j] + 1, swap(bz, bz1))
                            for (int cr = 0; cr <= 2; cr ++) {
                                for (int cll = 0; cll <= 2; cll ++) {
                                    if (cr && cll == cr) continue;
                                    for (int crr = 0; crr <= 2; crr ++)
                                        F[bz1][crr] = add(F[bz1][crr], mul(F[bz][cr], f[j][r[j]][cll][crr]));
                                }
                                F[bz][cr] = 0;
                            }
                        for (int crr = 0; crr <= 2; crr ++) {
                            if (crr && crr == cr) continue;
                            f[l][r[l]][cl][cr] = add(f[l][r[l]][cl][cr], F[bz][crr]);
                        }
                    }
            }
    printf("%d\n", f[0][n - 1][0][0]);
    return 0;
}