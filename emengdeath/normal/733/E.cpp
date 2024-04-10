#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6 + 10;
struct node{
    int x;
    long long all;
}f[2][N];
int tot[2];
int n;
bool bz[N];
long long get(int sig, int l, int r) {
    return f[sig][r].all - f[sig][l - 1].all;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        char c;
        scanf(" %c", &c);
        bz[i] = (c == 'D');
        f[bz[i]][++tot[bz[i]]].x = i;
        f[bz[i]][tot[bz[i]]].all = i + f[bz[i]][tot[bz[i]]- 1].all;
    }
    int l[2] = {0, 1};
    for (int i = 1; i <= n; i ++){
        while (l[0] < tot[0] && f[0][l[0] + 1].x <= i) l[0] ++;
        while (l[1] <= tot[1] && f[1][l[1]].x < i) l[1] ++;
        int sum[2];
        sum[0] = l[0];
        sum[1] = tot[1] - l[1] + 1;
        long long ans;
        if (bz[i]) {
            if (sum[0] >= sum[1]) {
                ans = get(1, l[1], l[1] + sum[1] - 1) * 2 - i + n + 1 - get(0, l[0] - sum[1] + 1,l[0]) * 2;
            } else {
                ans = get(1, l[1], l[1] + sum[0]) * 2 - i - get(0, 1, l[0]) * 2;
            }
        } else {
            if (sum[1] >= sum[0]) {
                ans = get(1, l[1], l[1] + sum[0] - 1) * 2 - get(0, l[0] - sum[0] + 1,l[0]) * 2 + i;
            } else {
                ans = get(1, l[1], l[1] + sum[1] - 1) * 2 + n + 1- get(0, l[0] - sum[1], l[0]) * 2 + i;
            }
        }
        printf("%lld ", ans);
    }
    return 0;
}