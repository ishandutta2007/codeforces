#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 401;
int f[2][N][N];
int a[N];
int n, m;
long long V;
struct node{
    int s, f, c, r;
}b[250001];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    bool bz = 0, bz1 = 1;
    for (int i = 1; i <= n ; i ++)
        for (int j = i; j <= n; j ++)
            f[0][i][j] = a[j] - a[i];
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d %d %d", &b[i].s, &b[i].f, &b[i].c, &b[i].r);
    }
    sort(b +1, b + m + 1, [](const node&a, const node &b){
        return a.r < b.r;
    });
    int st = 0;
    for (int i = 1; i <= m; i ++) {
        while (st < b[i].r) {
            for (int i = 1; i <= n; i ++) {
                f[bz1][i][i] = a[i] - a[i];
                int x = i;
                for (int j = i + 1; j <= n; j++) {
                    while (max(f[bz][i][x], a[j] - a[x]) >= max(f[bz][i][x + 1], a[j] - a[x + 1]) && x + 1 < j) x++;
                    f[bz1][i][j] = max(f[bz][i][x], a[j] - a[x]);
                }
            }
            swap(bz, bz1);
            ++st;
        }
        V = max(1ll * f[bz][b[i].s][b[i].f] * b[i].c, V);
    }
    printf("%lld\n", V);
    return 0;
}