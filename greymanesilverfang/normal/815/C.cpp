#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 5e3 + 5;
const long long INF = 1e15;

int par[MAX_N];
long long c[MAX_N], d[MAX_N];
vector <long long> g[MAX_N], f[MAX_N];

int main() {
    int n; long long b; scanf("%d%I64d", &n, &b);
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d%I64d", &c[i], &d[i]);
        f[i].push_back(0); g[i].push_back(0);
        if (i > 1) scanf("%d", &par[i]);
    }
    for (int i = n; i >= 1; --i) {
        g[i].push_back(INF);
        for (int j = g[i].size() - 1; j > 0; --j)
            g[i][j] = min(g[i][j], g[i][j - 1] + c[i]);
        f[i].push_back(INF);
        for (int j = f[i].size() - 1; j > 0; --j)
            f[i][j] = min(g[i][j], f[i][j - 1] + c[i] - d[i]);
        if (i > 1) {
            for (int j = 1; j < f[i].size(); ++j) {
                g[par[i]].push_back(INF);
                f[par[i]].push_back(INF);
            }
            for (int j = f[par[i]].size() - 1; j > 0; --j)
                for (int k = min((int)(f[par[i]].size() - f[i].size()), j), l = j - k; k >= 0 && l < f[i].size(); --k, ++l) {
                    g[par[i]][j] = min(g[par[i]][j], g[par[i]][k] + g[i][l]);
                    f[par[i]][j] = min(f[par[i]][j], f[par[i]][k] + f[i][l]);
                }
            g[i].clear();
            f[i].clear();
        } else printf("%d\n", upper_bound(f[i].begin(), f[i].end(), b) - f[i].begin() - 1);
    }
    return 0;
}