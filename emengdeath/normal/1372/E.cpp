#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e3;
int a[N][N];
int sum[N];
int l[N * N], r[N * N];
int n, m, cnt;
int f[N][N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i =1; i <= n;i  ++) {
        int x;
        scanf("%d", &x);
        while (x --) {
            ++cnt;
            int x, y;
            scanf("%d %d", &x, &y);
            for (int j = x; j <= y; j ++)
                a[i][j] = cnt;
            l[cnt] = x;
            r[cnt] = y;
        }
    }
    for (int len = 1; len <= m; len ++)
        for (int i = 1; i + len - 1 <= m; i ++){
            int j = i + len - 1;
            for (int k = i; k <= j; k ++) {
                int sum = 0;
                for (int w = 1; w <= n; w ++)
                    sum += (l[a[w][k]] >= i && r[a[w][k]] <= j);
                f[i][j] = max(f[i][j], f[i][k - 1] + f[k + 1][j] + sum * sum);
            }
        }
    printf("%d\n", f[1][m]);
    return 0;
}