#include <algorithm>
#include <cstdio>
#include <cstring>
using  namespace std;
int k, t;
char s[17] = "0123456789abcdef";
int sum[17];
long long C[1000][1000];
long long f[1000];
char ans[1000];
void calc(int n) {
    for (int i = 1; i <= n; i ++)
        f[i] = 0;
    f[0] = 1;
    for (int i = 0; i < 16; i ++)
        for (int j = n; j >= 1;j --)
            for (int k = 1; k + sum[i] <= t && j - k >= 0; k ++)
                f[j] = f[j] + f[j - k] * C[j][k];
}
void calc_nlz(int n) {
    for (int i = 1; i <= n; i ++)
        f[i] = 0;
    f[0] = 1;
    for (int i = 1; i < 16; i ++)
        for (int j = n; j >= 1;j --)
            for (int k = 1; k + sum[i] <= t && j - k >= 0; k ++)
                f[j] = f[j] + f[j - k] * C[j][k];
    for (int j = n; j >= 1;j --)
        for (int k = 1; k + sum[0] <= t && j - k >= 0; k ++)
            f[j] = f[j] + f[j - k] * C[j - 1][k];
}
void work() {
    for (int len = 1; ; ++len) {
        memset(sum, 0, sizeof(sum));
        calc_nlz(len);
        long long all1 = 0;
        for (int i = 1; i <= len; i++)
            all1 += f[i];
        for (int id = 0; id < len; id ++) {
            for (int i = 0; i < 16; i++) {
                if (!id && !i) continue;
                ans[id] = i;
                for (int j = 0; j < 16; j++)
                    sum[j] = 0;
                for (int j = 0; j <= id; j++)
                    sum[ans[j]]++;
                bool sig = 1;
                for (int j = 0; j < 16; j++) {
                    if (sum[j] > t) sig = 0;
                    sum[j] = 0;
                }
                if (len == 4) {
                    int yy;
                    yy = 0;
                }
                if (!sig) continue;
                long long all = all1;
                for (int i = 0; i <= id; i++) {
                    for (int j = ans[i] + 1; j < 16; j++) {
                        sum[j]++;
                        if (sum[j] <= t) {
                            calc(len - i - 1);
                            all -= f[len - i - 1];
                        }
                        sum[j]--;
                    }
                    sum[ans[i]]++;
                }
                if (all < k) {
                    continue;
                }
                if (all == k && id == len - 1) {
                    for (int j = 0; j <= id; j++)
                        printf("%c", s[ans[j]]);
                    puts("");
                    return;
                }
                break;
            }
        }
    }
}
int main() {
    C[0][0] = 1;
    for (int i = 1; i < 1000; i ++) {
        C[i][0] = 1;
        for (int j = 1; j <= i;  j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    scanf("%d %d", &k, &t);
    work();
    return 0;
}