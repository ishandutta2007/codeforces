#include <algorithm>
#include <cstdio>
using namespace std;
int ans;
char a[1000][1000];
int n, m;
int mx[1000][1000];
bool check(int x, int y, int len) {
    if (y - len == 0 || y + len > m || x - len == 0) return 0;
    for (int i = -len; i <= len; i++)
        if (a[x - (len - abs(i))][y + i] != '*') return 0;
    return 1;
}
int main() {
    int T;
    scanf("%d", &T);
    //T = 10;
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1;i <= n; i ++)
            for (int j = 1; j <= m;j ++)
                mx[i][j] = 0, scanf(" %c", &a[i][j]);
        ans = 0;
        for (int i = 1; i <= n;i ++)
            for (int j = 1; j <= m;j ++) {
                int l = max(mx[i][j - 1] - 1, 0);
                ans += l;
                while (check(i, j, l)) {
                    ans ++;
                    l ++;
                }
                mx[i][j] = l;
            }
        printf("%d\n", ans);
    }
    return 0;
}