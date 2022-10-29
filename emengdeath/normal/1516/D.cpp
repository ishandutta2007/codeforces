#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int N = 1e5 + 10;
const int S = 17;
int f[N][S + 1];
int n, m;
int a[N], l[N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        int L = 1;
        for (int j = 2; 1ll *j *j <= a[i]; j ++)
            if (a[i] % j == 0) {
                while (a[i] % j == 0) a[i] /= j;
                L = max(L, l[j] + 1);
                l[j] = i; 
            }
        if (a[i] != 1) {
            L = max(L, l[a[i]] + 1), l[a[i]] = i;
        }
        L = max(f[i - 1][0], L);
        f[i][0] = L;
    }
    for (int i = 0; i < S; i ++)
        for (int j = 1; j <= n; j ++)
            if (f[j][i])
                f[j][i + 1] = f[f[j][i] - 1][i];
    while (m --) {
        int ans = 0;
        int l, r;
        scanf("%d %d", &l, &r);
        int i = S;
        while (r >= l) {
            while (i && f[r][i] < l) i --;
            if (f[r][i] < l) {
                ans ++;
                break;
            }
            ans += (1 << i);
            r = f[r][i] - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}