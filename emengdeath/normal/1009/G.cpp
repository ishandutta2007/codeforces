#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5  +10;
int f[1<<6], ff[1<<6], g[1<<6], gg[1<<6];
int b[N];
char s[N], w[100];
int n, m;
bool check() {
    for (int i = 1; i < (1 << 6) ; i ++)
        gg[i] = gg[i - (i&-i)] + g[i & -i];
    for (int i = 1; i < (1 << 6) - 1; i ++)
        if (gg[i] > f[i] || ff[i] > gg[i])
            return 0;
    return 1;
}
int main() {
    scanf("%s", s + 1);
    n = strlen(s+1);
    for (int i = 1; i <= n; i ++)
        g[1<<(s[i] - 'a')] ++;
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++){
        int x, y, z = 0;
        scanf("%d %s", &x, w);
        y = strlen(w);
        for (int j = 0; j < y;j ++)
            z |= (1<<(w[j] - 'a'));
        for (int j = 0; j < (1 << 6); j ++) {
            if (j & z)
                f[j]++;
            if ((j & z) == z)
                ff[j] ++;
        }
        b[x] = z;
    }
    for (int i = 1; i <= n; i ++)
        if (!b[i]) {
            ff[b[i] = (1<<6) - 1]++;
            for (int j = 0; j < (1 << 6); j++)
                f[j]++;
        }
    if (!check()) {
        printf("Impossible\n");
        return 0;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < (1 << 6) ; j++) {
            if (j & b[i])
                f[j]--;
            if ((j & b[i]) == b[i])
                ff[j]--;
        }
        for (int j = 0; j < 6; j++)
            if (g[1 << j] && ((b[i] >> j) & 1)) {
                g[1 << j]--;
                if (check()) {
                    printf("%c", j + 'a');
                    break;
                }
                g[1 << j]++;
            }
    }
    return 0;
}