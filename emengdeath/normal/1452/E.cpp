#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 4e3 + 10;
int g[N][6];
int n, m, k;
int l[N], r[N];
int get(int l, int r, int ll, int rr) {
    return max(0, min(rr, r) - max(ll, l) + 1);
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m;i++) {
        scanf("%d %d", &l[i], &r[i]);
    }
    int mx = 0;
    for (int i = 1; i <= n;i ++) {
        int all = 0;
        memset(g, 0, sizeof(g));
        for (int j = 1; j <= m;j ++) {
            int v = get(i, i + k - 1, l[j], r[j]);
            all += v;
            g[max(i, l[j] + v - 1 - k + 1)][1] ++;
            g[max(i, min(r[j] - k + 1, l[j]))][2] ++;
            g[max(i, max(r[j] - k + 1, l[j]))][3] ++;
            g[max(i, r[j] - v + 1)][4] ++;
        }
        int cnt = 0;
        mx = max(all, mx);
        for (int j = i + 1; j <= n; j ++) {
            cnt += g[j - 1][1] - g[j - 1][2] - g[j - 1][3] + g[j - 1][4];
            all += cnt;
            mx = max(all, mx);
        }
    }
    printf("%d\n", mx);
    return 0;
}