#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int t;
int sum[64], sum1[64], sum2[64];
long long n;
int m;
int main() {
    scanf("%d", &t);
    while (t --) {
        memset(sum, 0, sizeof(sum));
        memset(sum1, 0, sizeof(sum1));
        scanf("%lld %d", &n, &m);
        long long all = 0;
        while (m --) {
            int a;
            scanf("%d", &a);
            if (a & n == a) {
                n -= a;
                continue;
            }
            all += a;
            int i = 0;
            while (!(a & 1)) a >>= 1, i ++;
            sum[i] ++;
        }
        if (all < n) {
            printf("-1\n");
            continue;
        }
        for (int i = 0; i < 63; i ++)
            sum1[i] = (n & 1), n >>= 1;
        int ans = 0;
        int v = 0;
        for (int i = 0; i < 63; i ++, v /= 2) {
            v += sum[i];
            if (sum1[i] > v) {
                ans ++;
                for (int j = i + 1; j < 63; j ++)
                    if (!sum[j]) sum[j] ++,ans ++;
                    else {
                        sum[j]--;
                        break;
                    }
                v += 2;
            }
            v -= sum1[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}