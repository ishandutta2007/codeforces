#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;
const int N = 1e6 + 10;
vector<int>g[N];
int n, q;
int f[N], fa[N];
bool bz[N];
void dfs(int x, int mn) {
    f[x] = mn;
    for (auto u:g[x])
        if (u!=fa[x]) {
            fa[u] = x;
            dfs(u, min(mn, u));
        }
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i= 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    q --;
    int sig, x;
    scanf("%d %d", &sig, &x);
    x = x % n + 1;
    dfs(x, x);
    bz[x] = 1;
    int globalmn = x;
    int lastans = 0;
    while (q --) {
        scanf("%d %d", &sig, &x);
        x = (x + lastans) % n + 1;
        if (sig == 1) {
            while (!bz[x]){
                globalmn = min(globalmn, x);
                bz[x] = 1;
                x = fa[x];
            }
        } else
            printf("%d\n", lastans = min(f[x], globalmn));
    }
    return 0;
}