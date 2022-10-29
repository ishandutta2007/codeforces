#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e5;
int a[N], b[N], d[N];
long long all[N];
long long ans;
int n;
int du[N], ddu[N];
vector<int>g[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), all[i] = a[i];
    for (int i= 1; i <= n; i ++) {
        scanf("%d", &b[i]);
        if (b[i] != -1)
            du[b[i]] ++;
    }
    for (int i = 1; i <= n; i ++)
        if (!du[i])
            d[++d[0]] = i;
    for (int i = 1; i <= n; i ++) {
        if (all[d[i]] > 0) {
            if (b[d[i]] != -1) g[d[i]].push_back(b[d[i]]), ddu[b[d[i]]] ++, all[b[d[i]]] += all[d[i]];
        } else {
            if (b[d[i]] != -1)g[b[d[i]]].push_back(d[i]), ddu[d[i]] ++;
        }
        if (b[d[i]] != -1 && !(--du[b[d[i]]]))
            d[++d[0]] = b[d[i]];
    }
    d[0] = 0;
    for (int i = 1; i <= n; i ++) {
        all[i] = a[i];
        if (!ddu[i])
            d[++d[0]] = i;
    }
    for (int i = 1; i <= n; i ++) {
        ans += all[d[i]];
        if (b[d[i]]!=-1)
            all[b[d[i]]] += all[d[i]];
        for (auto u:g[d[i]]) {
            if (!(--ddu[u]))
                d[++d[0]] = u;
        }
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n;i ++)
        printf("%d%c", d[i], " \n"[i == n]);
    return 0;
}