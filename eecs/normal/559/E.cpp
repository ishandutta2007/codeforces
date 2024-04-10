#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;
int n, tot, f[maxn][maxn][maxn], id[maxn][maxn], mx[maxn][maxn];
int L[maxn], R[maxn], M[maxn], g[110][110][maxn], h[110][110][maxn];
pair<int, int> p[maxn];
vector<int> V;

void chk_min(int &x, int y) {
    if (x > y) x = y;
}

void chk_max(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    scanf("%d", &n);
    V = {-1000000000, 1000000000};
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
        V.push_back(p[i].first);
        V.push_back(p[i].first - p[i].second);
        V.push_back(p[i].first + p[i].second);
    }
    sort(V.begin(), V.end());
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
        L[i] = lower_bound(V.begin(), V.end(), p[i].first - p[i].second) - V.begin();
        M[i] = lower_bound(V.begin(), V.end(), p[i].first) - V.begin();
        R[i] = lower_bound(V.begin(), V.end(), p[i].first + p[i].second) - V.begin();
        mx[i][i] = i;
        for (int j = i + 1; j <= n; j++) {
            mx[i][j] = mx[i][j - 1];
            if (p[j].second > p[mx[i][j]].second) mx[i][j] = j;
        }
    }
    memset(g, -0x3f, sizeof(g));
    memset(h, 0x3f, sizeof(h));
    for (int i = 1; i <= n; i++) {
        g[i][i][L[i]] = M[i];
        for (int j = i; j > 1; j--) {
            for (int k = 0; k < V.size(); k++) if (g[i][j][k] >= 0) {
                chk_max(g[i][j - 1][min(k, L[j - 1])], g[i][j][k]);
                chk_max(g[i][j - 1][k], max(g[i][j][k], R[j - 1]));
            }
        }
        h[i][i][R[i]] = M[i];
        for (int j = i; j < n; j++) {
            for (int k = 0; k < V.size(); k++) if (h[i][j][k] < V.size()) {
                chk_min(h[i][j + 1][max(k, R[j + 1])], h[i][j][k]);
                chk_min(h[i][j + 1][k], min(h[i][j][k], L[j + 1]));
            }
        }
    }
    function<int(int, int, int, int)> solve = [&](int l, int r, int lb, int rb) {
        if (l > r || lb > rb) return 0;
        if (!id[l][r]) id[l][r] = ++tot;
        int k = id[l][r], pos = mx[l][r];
        if (~f[k][lb][rb]) return f[k][lb][rb];
        f[k][lb][rb] = 0;
        for (int i = pos; i >= l && M[i] >= L[pos]; i--) {
            for (int t = 0; t < V.size(); t++) if (g[pos][i][t] >= 0) {
                chk_max(f[k][lb][rb], solve(l, i - 1, lb, min(rb, t)) +
                    solve(pos + 1, r, max(lb, g[pos][i][t]), rb) +
                    max(0, V[min(rb, g[pos][i][t])] - V[max(lb, t)]));
            }
        }
        for (int i = pos; i <= r && M[i] <= R[pos]; i++) {
            for (int t = 0; t < V.size(); t++) if (h[pos][i][t] < V.size()) {
                chk_max(f[k][lb][rb], solve(l, pos - 1, lb, min(rb, h[pos][i][t])) +
                    solve(i + 1, r, max(lb, t), rb) +
                    max(0, V[min(rb, t)] - V[max(lb, h[pos][i][t])]));
            }
        }
        return f[k][lb][rb];
    };
    memset(f, -1, sizeof(f));
    printf("%d\n", solve(1, n, 0, V.size() - 1));
    return 0;
}