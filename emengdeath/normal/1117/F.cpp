#include <algorithm>
#include <cstdio>
#include <bitset>
using namespace std;
const int N = 20;
bitset<300>f[1<<N], org, und[N];
bool g[1<<N], w[1<<N];
int s[1 << N];
int n, m;
int sum[N];
int id(int x, int y) {
    return x * m + y;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i ++)
        for (int j = 0; j < m; j ++)
            und[i][id(i, j)] = und[i][id(j, i)] = 1;
    for (int i = 1; i <= n; i ++) {
        char c;
        scanf(" %c", &c);
        int x = c - 'a';
        for (int j = 0; j < m; j ++) {
            if (sum[j]) {
                f[sum[j] ^ (1 << j)][id(j, x)] = 1;
                sum[j] |= 1 << x;
            }
        }
        sum[x] = 1 << x;
        s[1 << x] ++;
    }
    for (int i = 0; i < m; i ++)
        for (int j = 0;j < m; j ++) {
            int x;
            scanf("%d", &x);
            org[id(i, j)] =x;
        }
    for (int i = 1; i < (1 << m); i ++) {
        for (int j = 0; j < m; j++)
            if ((i >> j) & 1)
                f[i] |= f[i ^ (1 << j)];
        for (int j = 0; j < m; j++)
            if ((i >> j) & 1)
                f[i] ^= (f[i] & und[j]);
        s[i] = s[i & -i] + s[i ^ (i&-i)];
    }
    for (int i = 0; i < (1<< m); i ++)
        g[i] = ((f[i] & org) ==f[i]);
    w[0] = 1;
    int ans = n;
    for (int i = 1; i < (1 << m); i ++)
        if (g[i])
            for (int j = 0; j < m; j ++)
                if (((i >>j) & 1) && w[i ^ (1 << j)]) {
                    w[i] = 1;
                    ans = min(ans, s[(1 << m) - 1 - i]);
                    break;
                }
    printf("%d\n", ans);
    return 0;
}