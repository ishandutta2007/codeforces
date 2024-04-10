#include <algorithm>
#include <cstdio>
using namespace std;
int n, m;
char s[10000000];
char d[8][2][2] = {{{'1', '0'}, {'0', '0'}},{{'0', '1'}, {'0', '0'}},{{'0', '0'}, {'1', '0'}}, {{'0', '0'}, {'0', '1'}}, {{'1', '1'}, {'1', '0'}}, {{'1', '1'}, {'0', '1'}}, {{'1', '0'}, {'1', '1'}}, {{'0', '1'}, {'1', '1'}}};
inline int id(int x, int y) {
   return x * m + y;
}
int f[2][1 << 3];
bool can[1<<3][1<<3];
int a[10000000];
int did(int x, int v) {
    return __builtin_popcount(a[x] ^ v);
}
int main() {
    scanf("%d %d", &n, &m);
    if (n > m) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf(" %c", &s[id(i, j)]), s[id(i, j)] -= '0';
    } else {
        swap(n, m);
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
                scanf(" %c", &s[id(i, j)]), s[id(i, j)] -= '0';
    }
    if (m > 3) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            a[i] = (a[i] << 1) + s[id(i, j)];
    for (int i = 0; i < (1 << m); i ++)
        for (int j = 0; j < (1 << m); j ++) {
            can[i][j] = 1;
            int mask = 3;
            for (int k = 0; k < (m - 1) ; k ++, mask <<= 1)
            {
                can[i][j] &= ((__builtin_popcount(i & mask) + __builtin_popcount(j & mask)) & 1);
            }
        }
    bool bz = 0, bz1 = 1;
    for (int i = 0; i < (1 << m); i ++) {
        f[1][i] = 1e9;
        f[0][i] = did(0, i);
    }
    for (int i = 1; i < n; i ++, swap(bz, bz1))
        for (int j = 0; j < (1 << m) ; j ++)
            if (f[bz][j] != 1e9) {
                for (int k = 0; k < (1 << m); k ++)
                    if (can[j][k])
                        f[bz1][k] = min(f[bz1][k], f[bz][j] + did(i, k));
                f[bz][j] = 1e9;
            }
    int ans = 1e9;
    for (int i = 0; i <(1 << m) ; i ++)
        ans = min(ans, f[bz][i]);
    printf("%d", ans);
    return 0;
}