#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e6  + 10;
int n, m;
bool bz[N];
vector<int>g[N];
int in[N], out[N], idl[N], idr[N];
int to[N];
int f[1<<20];
vector<int>l, r;
void dfs(int x, int from) {
    if (bz[x])return;
    bz[x] = 1;
    if (idr[x])to[from] |= (1 << (idr[x] - 1));
    for (auto u:g[x])
        dfs(u, from);
}
int count(int x) {
    int v = 0;
    while (x)
        v ++, x -= x & -x;
    return v;
}
int main() {
    scanf("%d %d",&n, &m);
    for (int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        in[y] ++;
        out[x] ++;
        g[x].push_back(y);
    }
    int sum = 0;
    int all = 0;
    for (int i = 1;i  <= n; i ++) {
        if (!in[i]) {
            sum ++;
            idl[i] = l.size();
            l.push_back(i);
        }
        if (!out[i]) {
            sum++;
            r.push_back(i);
            idr[i] = r.size();
            if (!in[i]) {
                all = 1;
            }
        }
    }
    if (all && sum > 2) {
        puts("NO");
        return 0;
    }
    if (all) {
        puts("YES");
        return 0;
    }
    for (auto u:l) {
        memset(bz, 0, sizeof(bz));
        dfs(u, idl[u]);
    }
    bool sig = 0;
    for (int i = 1; i < (1 << l.size()) - 1; i ++){
        for (int j = 0; j < l.size(); j ++)
            if ((i >> j) & 1)
                f[i]|= to[j];
        sig |= (count(f[i]) == count(i));
    }
    !sig?puts("YES"):puts("NO");
    return 0;
}