#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1e3 + 10;
struct node{
    int sum[4];
}l[N][N], r[N][N], u[N][N], d[N][N], lu[N][N], ru[N][N], ld[N][N], rd[N][N], o;
int sum[N * 4];
node operator+(node a, node b) {
    for (int i = 0; i < 4; i ++)
        a.sum[i] += b.sum[i];
    return a;
}
node operator-(node a, node b) {
    for (int i = 0; i < 4; i ++)
        a.sum[i] -= b.sum[i];
    return a;
}
char c[N][N];
int n;
node turn(int x) {
    node tmp = o;
    tmp.sum[x] = 1;
    return tmp;
}
node get(int sig, int x, int y, int len) {
    switch(sig) {
        case 0:
            return l[x][y] - l[x][y - len];
        case 1:
            return r[x][y] - r[x][y + len];
        case 2:
            return u[x][y] - u[x - len][y];
        case 3:
            return d[x][y] - d[x + len][y];
        case 4:
            return lu[x][y] - lu[x - len][y - len];
        case 5:
            return ld[x][y] - ld[x + len][y - len];
        case 6:
            return ru[x][y] - ru[x - len][y + len];
        case 7:
            return rd[x][y] - rd[x + len][y + len];
    }
}
void update(const node&a) {
    sum[a.sum[2]] = max(sum[a.sum[2]], a.sum[3]);
}
int ans[2];
int main() {
    scanf("%d", &n);
    bool all_zero = 1;
    for (int i = 1; i <= n; i ++) {
        scanf("%s", c[i]+1);
        for (int j = 1; j <= n; j ++)
            c[i][j] -= '0', all_zero &= !c[i][j];
    }
    if (all_zero) {
        puts("0");
        return 0;
    }
    for (int i = 0; i <= n * 4 ; i ++) sum[i] = -1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            l[i][j] = l[i][j - 1] + turn(c[i][j]), u[i][j] = u[i - 1][j] + turn(c[i][j]), lu[i][j] = lu[i-1][j-1] + turn(c[i][j]), ru[i][j] = ru[i - 1][j + 1] + turn(c[i][j]);

    for (int i = n; i >=1; i --)
        for (int j = n; j >= 1; j --)
            r[i][j] = r[i][j + 1] + turn(c[i][j]), d[i][j] = d[i + 1][j] + turn(c[i][j]), ld[i][j] = ld[i+1][j-1] + turn(c[i][j]), rd[i][j] = rd[i + 1][j + 1] + turn(c[i][j]);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        if (c[i][j]){
            node tmp = turn(c[i][j]);
            tmp = tmp + tmp + tmp;
            int l = 1, r = min(i, min(j, min(n - i + 1, n - j + 1))), mid, s = 0;
            while (l <= r) {
                mid = (l + r) / 2;
                if ((get(0, i, j, mid) + get(1, i, j , mid) + get(2, i, j, mid) + get(3, i, j, mid) - tmp).sum[0] == 0) l = mid + 1, s = max(s, mid);
                else
                    r = mid - 1;
            }
            update((get(0, i, j, s) + get(1, i, j , s) + get(2, i, j, s) + get(3, i, j, s) - tmp));


            l = 1, r = min(i, min(j, min(n - i + 1, n - j + 1))), mid, s = 0;
            while (l <= r) {
                mid = (l + r) / 2;
                if ((get(4, i, j, mid) + get(5, i, j , mid) + get(6, i, j, mid) + get(7, i, j, mid) - tmp).sum[0] == 0) l = mid + 1, s = max(s, mid);
                else
                    r = mid - 1;
            }
            update((get(4, i, j, s) + get(5, i, j , s) + get(6, i, j, s) + get(7, i, j, s) - tmp));
        }
    for (int i = 0; i <= n * 4; i ++)
        if (sum[i] >= 0) {
            int commonx = min(ans[0], i), commony = min(ans[1], sum[i]);
            long double v = log2l(3) * (sum[i] - commony) + i - commonx;
            long double vans = log2l(3) * (ans[1] - commony) + ans[0] - commonx;
            if (v > vans)
                ans[0] = i, ans[1] = sum[i];
        }
    long long output = 1;
    for (int i = 1; i <= ans[0]; i ++)
        output = output * 2 % 1000000007;
    for (int i = 1; i <= ans[1]; i ++)
        output = output * 3 % 1000000007;
    printf("%lld\n", output);
    return 0;
}