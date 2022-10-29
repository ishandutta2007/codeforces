#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 201;
int f[N][N][26][26];
char s[N + 10];
int n;
int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++)
        s[i] -= 'a';
    for (int i = 1; i <= n; i ++)
        for (int l = 1; l + i - 1 <= n; l ++) {
            int r = l + i - 1;
            for (int lc = 0; lc < 26; lc ++)
                for (int rc = 0; rc < 26; rc ++) {
                    for (int mid = l; mid <= r; mid++) {
                        if ((s[mid] - 1 == lc && f[l][mid - 1][lc][s[mid]] == mid - l) ||
                            (s[mid] - 1 == rc && f[mid + 1][r][s[mid]][rc] == r - mid))
                            f[l][r][lc][rc] = max(f[l][r][lc][rc],
                                                  f[l][mid - 1][lc][s[mid]] + f[mid + 1][r][s[mid]][rc] + 1);
                        else
                            f[l][r][lc][rc] = max(f[l][r][lc][rc],
                                                  f[l][mid - 1][lc][s[mid]] + f[mid + 1][r][s[mid]][rc]);
                    }
                    if (s[l] - 1 == lc)
                        f[l][r][lc][rc] = max(f[l][r][lc][rc], f[l + 1][r][lc][rc] + 1);
                    if (s[r] - 1 == rc)
                        f[l][r][lc][rc] = max(f[l][r][lc][rc], f[l][r - 1][lc][rc] + 1);
                }
        }
    printf("%d\n", f[1][n][25][25]);
    return 0;
}