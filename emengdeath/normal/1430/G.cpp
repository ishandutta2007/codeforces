#include <algorithm>
#include <cstdio>
#include <ctime>
using namespace std;
const int N = 18;
struct node{
    long long v;
    int ans;
}f[N + 1][1<<N];
int ou[N];
int a[N], d[N], du[N];
int n, m;
void upd(node&a, node v) {
    if (a.v > v.v) {
        a = v;
    }
}
int ans[N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m;i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        x --;
        y --;
        ou[x] |= (1 << y);
        du[y] ++;
        a[x] += z;
        a[y] -= z;
    }
    int cnt = 0;
    for (int i = 0; i < n;i ++)
        if (!du[i]) d[cnt ++] = i;
    for (int i = 0; i < cnt; i ++) {
        for (int j = 0; j < n; j++)
            if (ou[d[i]] & (1 << j)) {
                if (!(--du[j]))
                    d[cnt ++] = j;
            }
    }
    bool bz = 0, bz1 = 1;
    for (int i = 1; i < (1 << n) ; i ++)
        for (int j = 0; j <=  n; j ++)f[j][i].v = 1e18;
    for (int i = 1; i <= n ; i ++)
        for (int j = 1; j <= n; j ++) {
            for (int k = 0; k < (1 << n); k ++)
            {
                upd(f[i][k], node{f[i - 1][k].v, 0});
                if ((k >> d[j - 1])&1) continue;
                if ((ou[d[j - 1]] & k) == ou[d[j - 1]]) {
                    upd(f[i][k|(1 << d[j - 1])], node{f[i][k].v + a[d[j - 1]] * i, (f[i][k].ans | (1 << d[j - 1]))});
                }
            }
        }
    int mask = (1 << n) - 1;
    for (int i = n ; i >= 1; i --) {
        for (int j = 0; j < n; j++)
            if ((f[i][mask].ans >> j) & 1) ans[j] = i;
        mask -= f[i][mask].ans;
    }
    for (int i = 0; i < n ; i++)
        printf("%d%c", ans[i], " \n"[i == n -1]);
    return 0;
}