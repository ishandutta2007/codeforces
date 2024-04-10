#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int n, m, cnt[maxn][2], vis[maxn];
int ans[2], tmp[2], f[maxn][2][2][2];
vector<tuple<int, int, int>> G[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, k, a, b; i <= n; i++) {
        scanf("%d %d", &k, &a);
        if (k == 1) {
            cnt[abs(a)][a > 0] ^= 1;
        } else {
            scanf("%d", &b);
            int p1 = 0, p2 = 0;
            if (a < 0) a *= -1, p1 = 1;
            if (b < 0) b *= -1, p2 = 1;
            G[a].emplace_back(b, p1, p2), G[b].emplace_back(a, p2, p1);
        }
    }
    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;
        bool flag = 0;
        for (auto e : G[v]) if (!vis[get<0>(e)]) {
            dfs(get<0>(e)), flag = 1;
            for (int x : {0, 1}) for (int y : {0, 1}) for (int z : {0, 1}) {
                for (int i : {0, 1}) red(f[v][x][y][z ^ ((x ^ get<1>(e)) | (i ^
                    get<2>(e))) ^ cnt[v][x]] += f[get<0>(e)][i][y][z] - P);
            }
        }
        if (!flag) f[v][0][0][cnt[v][0]] = f[v][1][1][cnt[v][1]] = 1;
    };
    ans[0] = 1;
    for (int i = 1; i <= m; i++) if (!vis[i] && G[i].size() <= 1) {
        dfs(i);
        memcpy(tmp, ans, sizeof(tmp)), ans[0] = ans[1] = 0;
        for (int x : {0, 1}) for (int y : {0, 1}) for (int z : {0, 1}) {
            for (int j : {0, 1}) red(ans[j ^ z] += 1LL * tmp[j] * f[i][x][y][z] % P - P);
        }
    }
    for (int i = 1; i <= m; i++) if (!vis[i]) {
        dfs(i);
        memcpy(tmp, ans, sizeof(tmp)), ans[0] = ans[1] = 0;
        int p = get<1>(G[i][1]), q = get<2>(G[i][1]);
        for (int x : {0, 1}) for (int y : {0, 1}) for (int z : {0, 1}) {
            for (int j : {0, 1}) red(ans[j ^ z ^ ((x ^ p) | (y ^ q))] += 1LL * tmp[j]
                * f[i][x][y][z] % P - P);
        }
    }
    printf("%d\n", ans[1]);
    return 0;
}