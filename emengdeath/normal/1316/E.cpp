#include <algorithm>
#include <cstdio>
using namespace std;
int n, p, k;
long long f[2][1<<7];
int s[100001][7], a[100001];
int id[100001];
int main() {
    scanf("%d %d %d", &n, &p, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        id[i] = i;
    }
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < p; j ++)
            scanf("%d", &s[i][j]);
    sort(id + 0, id + n, [](int x, int y) {
        return a[x] > a[y];
    });
    f[0][0] = 1;
    bool bz = 0, bz1 = 1;
    for (int i = 0; i < n; i ++, swap(bz, bz1)) {
        int x = id[i];
        for (int j = 0; j < (1 << p); j ++)
            if (f[bz][j]) {
                int cnt = k - i;
                for (int k = 0; k < p; k ++)
                    if (!((j>>k)&1)) {
                        f[bz1][j | (1 << k)] = max(f[bz1][j | (1<<k)], f[bz][j] + s[x][k]);
                    }else cnt ++;
                if (cnt > 0)
                    f[bz1][j] = max(f[bz1][j], f[bz][j] + a[x]);
                else
                    f[bz1][j] = max(f[bz1][j], f[bz][j]);
                f[bz][j] = 0;
            }
    }
    printf("%lld\n", f[bz][(1 << p) - 1] - 1);
    return 0;
}