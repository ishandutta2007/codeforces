#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int f[2001][2001];
int T;
int n;
char s[2011], t[2011];
int sum[26], sum1[26];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        scanf("%s", s +1);
        scanf("%s", t + 1);
        for (int i = 0; i <= n ; i ++)
            for (int j = 0; j <= n; j ++)
                f[i][j] = 1e9;
        memset(sum1, 0, sizeof(sum1));
        f[n][n] = 0;
        for (int i = n; i>= 0; i --) {
            int cnt = 0;
            for (int j = 0; j < 26; j ++)
                sum[j] = sum1[j];
            for (int j = n; j >= 1 && !cnt; j--) {
                if (i) f[i - 1][j] = min(f[i - 1][j], f[i][j] + 1);
                if (sum[t[j] - 'a'])
                    f[i][j - 1] = min(f[i][j - 1], f[i][j]);
                if (i && s[i] == t[j])
                    f[i - 1][j - 1] = min(f[i - 1][j - 1], f[i][j]);
                sum[t[j] - 'a'] --;
                cnt += (sum[t[j] - 'a'] == -1);
            }
            if (i)
                sum1[s[i] - 'a'] ++;
        }
        if (f[0][0] == 1e9) puts("-1");
        else
            printf("%d\n", f[0][0]);
    }
    return 0;
}