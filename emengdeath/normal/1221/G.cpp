#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 100;
int bz[N];
vector<int> g[N];
long long edge[N];
int n, m;
int id[N];
vector<int>d;
long long ans[1 << 3];
long long f[1 << 22];
void dfs(int x) {
    id[x] = d.size();
    d.push_back(x);
    for (auto u:g[x])
        if (!bz[u]) {
            bz[u] = bz[x] % 2 + 1;
            dfs(u);
        }
}
void merge(long long*a) {
    long long c[1<<3] = {0};
    for (int i = 0; i < 7; i ++)
        for (int j = 0; j < 8; j ++)
            c[i | j] += a[i] * ans[j];
    for (int i = 0; i < 8; i ++)
        ans[i] = c[i];
}
int main() {
    scanf("%d %d", &n, &m);
    if (!m) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ans[0] = 1;
    for (int i = 1; i <= n; i ++)
        if (!bz[i]) {
            d.clear();
            bz[i] = 1;
            dfs(i);
            if (d.size() == 1) {
                long long v[1 << 3] = {0};
                v[0] = 2;
                merge(v);
                continue;
            }
            long long v[1 << 3] = {0};
            v[2] = 1;
            for (int i = 0; i < d.size(); i ++) {
                edge[i] = 0;
                for (auto u:g[d[i]])
                    edge[i] |= (1ll << id[u]), v[2] &= (bz[u] != bz[d[i]]);
            }
            v[2] *= 2;
            int len1 = d.size() / 2, mask1 = (1 << len1) - 1, len2 = d.size() - len1, mask2 = (1 << len2) - 1;
            for (int i = 0; i <= mask2; i ++)
                f[i] = 0;
            for (int i = 0; i <= mask2; i ++) {
                long long v = 0;
                for (int j = len1; j < d.size(); j ++)
                    if ((i >> (j - len1)) & 1) {
                        v |= edge[j];
                    }
                bool sig = 1;
                for (int j = len1; j < d.size(); j ++)
                    if (((i >> (j - len1)) & 1) && ((v >> j) & 1))
                        sig = 0;
                f[i] = sig;
            }
            for (int i = 0; i < len2; i ++)
                for (int j = 0; j <= mask2; j ++)
                    if (j & (1 << i))
                        f[j] += f[j ^ (1 << i)];
            v[3] = 0;
            for (int i = 0; i <= mask1; i ++) {
                long long w = 0;
                for (int j = 0; j < len1; j ++)
                    if ((i >> j) & 1) {
                        w |= edge[j];
                    }
                bool sig = 1;
                for (int j = 0; j < len1; j ++)
                    if (((i >> j) & 1) && ((w >> j) & 1))
                        sig = 0;
                if (!sig)
                    continue;
                w >>= len1;
                w ^= mask2;
                v[3] += f[w];
            }
            v[3] -= v[2] + 1;
            v[6] = v[3];
            v[7] = 0;
            v[1] = 1;
            v[4] = 1;
            merge(v);
        }
    long long s = (1ll << n);
    for (int i = 0; i < 7; i ++)
        s -= ans[i];
    printf("%lld\n", s);
    return 0;
}