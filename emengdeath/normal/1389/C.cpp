#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int l[10][10], r[10][10];
char s[1000000], a[100], b[100];
int f[10][10], g[10][10];
int n, T;
int sum[10];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s + 1);
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(f, 0, sizeof(f));
        memset(sum, 0, sizeof(sum));
        int n = strlen(s + 1);
        for (int i = 1; i <= n; i ++)
            s[i] -= '0';
        int mx = min(2, n);
        for (int i = 1; i <= n; i ++)
        {
            sum[s[i]] ++;
            mx = max(sum[s[i]], mx);
            for (int j = 0; j < 10; j ++) {
                f[j][s[i]] = max(f[s[i]][j] + 1, f[j][s[i]]);
                if (!(f[j][s[i]] & 1))mx = max(f[j][s[i]], mx);
            }
        }
        printf("%d\n", n - mx);
    }
    return 0;
}