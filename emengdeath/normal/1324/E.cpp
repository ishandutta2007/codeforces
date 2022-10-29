#include <algorithm>
#include <cstdio>
using namespace std;
int f[2001][2001];
int n, h, l, r;
int main() {
    f[0][0] = 1;
    scanf("%d %d %d %d",&n,&h,&l,&r);
    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < h; j ++)
            if (f[i][j])
                for (int xx = x - 1; xx <= x; xx++) {
                    int tmp = j + xx;
                    if (tmp >= h) tmp -= h;
                    f[i + 1][tmp] = max(f[i + 1][tmp], f[i][j] + (tmp >= l && tmp <= r ));
                }
        }
    int ans = 0;
    for (int i = 0; i < h; i ++)
        ans = max(ans, f[n][i]);
    printf("%d\n", ans - 1);
    return 0;
}