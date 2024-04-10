#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e2;
char a[N][N];
bool bz[N][N];
int n, m;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        memset(bz, 0, sizeof(bz));
        for (int i = 1 ; i <= n;i  ++)
            scanf("%s", a[i] + 1);
        int ans = 0;
        for (int i = n; i >= 1; i --)
            for (int j = m; j >= 1; j --)
                if (a[i][j] == 'C') {
                    bz[i][j] = 1;
                } else {
                    if (a[i][j] == 'R') {
                        if (!bz[i][j + 1])
                            ans++;
                    } else {
                        if (!bz[i + 1][j])
                            ans ++;
                    }
                    bz[i][j] = 1;
                }
        printf("%d\n", ans);
    }
    return 0;
}