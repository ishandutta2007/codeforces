#include <bits/stdc++.h>
using namespace std;

const int maxn = 410;
int n, m, d[maxn][maxn], cnt[maxn];
double prob[maxn], all[maxn];
vector<int> G[maxn], V[maxn];
bool mark[maxn];

int main() {
    scanf("%d %d", &n, &m);
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        G[a].push_back(b), G[b].push_back(a);
        d[a][b] = d[b][a] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            V[j].clear();
        }
        for (int j = 1; j <= n; j++) {
            V[d[i][j]].push_back(j);
        }
        double sum = 0;
        for (int k = 0; k <= n; k++) if (!V[k].empty()) {
            memset(prob, 0, sizeof(prob));
            memset(mark, 0, sizeof(mark));
            for (int u : V[k]) for (int v : G[u]) {
                mark[v] = 1, prob[v] += 1.0 / G[u].size();
            }
            vector<int> cand;
            for (int j = 1; j <= n; j++) {
                if (mark[j]) cand.push_back(j);
            }
            double tmp = 0;
            for (int j = 1; j <= n; j++) {
                double foo = 0;
                for (int l : cand) if (prob[l] > all[d[j][l]]) {
                    foo += prob[l] - all[d[j][l]], all[d[j][l]] = prob[l];
                }
                tmp = max(tmp, foo);
                for (int l : cand) all[d[j][l]] = 0;
            }
            sum += max(tmp, 1.0);
        }
        ans = max(ans, sum / n);
    }
    printf("%.10f\n", ans);
    return 0;
}