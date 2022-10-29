#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
const long long inf = 1e18;
int n;
int h[N], t[N];
vector<int> g[N];
long long f[N][2];
void upd(int x, long long all, int*cnt) {
    if (x == 1) f[x][0] = min(f[x][0], 1ll * max(cnt[0], cnt[1]) * t[x] + all);
    else {
        f[x][0] = min(f[x][0], 1ll * max(cnt[0], cnt[1] + 1) * t[x] + all);
        f[x][1] = min(f[x][1], 1ll * max(cnt[0] + 1, cnt[1]) * t[x] + all);
    }
}
void dfs(int x, int fa) {
    for (int i = 0; i < g[x].size(); i ++)
        if (g[x][i] == fa) {
            swap(g[x][i], g[x][g[x].size() - 1]);
            g[x].pop_back();
            break;
        }
    int cnt[2] = {0, 0};
    long long all = 0;
    f[x][0] = f[x][1] = inf;
    vector<long long> tmp;
    for (auto u:g[x]) {
        dfs(u, x);
        if (h[u] > h[x]) {
            cnt[0] ++;
            all += f[u][0];
        } else {
            if (h[u] < h[x]) {
                cnt[1]++;
                all += f[u][1];
            } else {
                cnt[0]++;
                all += f[u][0];
                tmp.push_back(f[u][1] - f[u][0]);
            }
        }
    }
    sort(tmp.begin(), tmp.end());
    upd(x, all, cnt);
    for (auto u:tmp) {
        cnt[0] --;
        cnt[1] ++;
        all += u;
        upd(x, all, cnt);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &t[i]);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &h[i]);
    for (int i = 1; i < n ; i ++) {
        int x ,y;
        scanf("%d %d", &x ,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    printf("%lld\n", f[1][0]);
    return 0;
}