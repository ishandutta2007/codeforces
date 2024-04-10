#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
int a[N], sum[26];
long long ans[26];
char c[N];
int main() {
    int T;
    int n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        memset(sum, 0, sizeof(sum));
        memset(ans, 0, sizeof(ans));
        scanf("%s", c + 1);
        for (int i = 1; i <= n; i ++)
            a[i] = 0;
        for (int i = 1; i <=m ;i ++) {
            int x;
            scanf("%d", &x);
            a[x] ++;
        }
        a[n] ++;
        for (int i =1;i <= n; i ++) {
            sum[c[i] - 'a'] ++;
            for (int j = 0; j < 26; j ++)
                ans[j] += 1ll * sum[j] *a[i];
        }
        for (int j = 0; j < 26; j ++)
            printf("%lld%c", ans[j], " \n"[j == 25]);
    }
}