#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int f[N][2];
pair<int, int> a[N][2], b[N][2];
int ssz[N];
int n;
vector<int> g[N];
int ans = 0;
void dfs(int x, int fa) {
    for (auto u:g[x])
        if (u != fa) {
            ssz[x] ++;
            dfs(u, x);
            if (a[x][0] < pair<int, int>{f[u][0], u})
                a[x][1] = a[x][0], a[x][0] = pair<int, int>{f[u][0], u};
            else
                if (a[x][1] < pair<int, int>{f[u][0], u})
                    a[x][1] = pair<int, int>{f[u][0], u};

            if (b[x][0] < pair<int, int>{f[u][1], u})
                b[x][1] = b[x][0], b[x][0] = pair<int, int>{f[u][1], u};
            else
                if (b[x][1] < pair<int, int>{f[u][1], u})
                    b[x][1] = pair<int, int>{f[u][1], u};
        }
    f[x][1] = 1 + a[x][0].first;
    if (!ssz[x])
        f[x][0] = 0;
    else
        f[x][0] = max(a[x][0].first, b[x][0].first) + ssz[x] - 1;
    ans = max(ans, max(f[x][1], f[x][0]));
}
void dfs1(int x, int fa, int A, int B) {
    int sz = ssz[x] - (x == 1);
    ans = max(ans, max(A + max(f[x][1], f[x][0]), B + f[x][0]));
    for (auto u:g[x])
        if (u != fa) {
            int AA = max(A, B), BB = A + 1;
            if (a[x][0].second != u)
                AA = max(AA, a[x][0].first), BB = max(BB, a[x][0].first + 1);
            else
                AA = max(AA, a[x][1].first), BB = max(BB, a[x][1].first + 1);
            if (b[x][0].second != u)
                AA = max(AA, b[x][0].first);
            else
                AA = max(AA, b[x][1].first);

            dfs1(u, x, AA + sz - 1, BB);
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    dfs1(1, 0, 0, 0);
    printf("%d\n", ans);
    return 0;
}