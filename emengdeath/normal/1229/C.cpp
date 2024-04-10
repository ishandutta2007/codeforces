#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n, m;
vector<int> g[N];
int in[N], out[N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int x ,y;
        scanf("%d %d", &x, &y);
        if (x< y) swap(x ,y);
        g[y].push_back(x);
        in[y] ++;
        out[x] ++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += 1ll * in[i] * out[i];
    scanf("%d", &m);
    printf("%lld\n", ans);
    while (m --) {
        int x;
        scanf("%d", &x);
        for (auto u:g[x])
        {
            g[u].push_back(x);
            ans -= out[x];
            ans -= in[u];
            ans += out[u] - 1;
            in[u] ++;
            out[u] --;
        }
        out[x] += in[x];
        in[x] = 0;
        g[x].clear();
        printf("%lld\n", ans);
    }
    return 0;
}