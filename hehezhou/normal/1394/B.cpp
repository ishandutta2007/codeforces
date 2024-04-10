#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int fac[15];
int ans[3700000];
vector < pair < int, int > > e[200010];
vector < pair < int, int > > qwq[200010];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    fac[0] = 1;
    for (int i = 1; i <= k + 1; i++) fac[i] = i * fac[i - 1];
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({w, v});
    }
    for (int i = 1; i <= n; i++) {
        sort(e[i].begin(), e[i].end());
        for (int j = 0; j < e[i].size(); j++) {
            qwq[e[i][j].second].push_back({e[i].size(), j + 1});
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(qwq[i].begin(), qwq[i].end());
        for (int j = 1; j < qwq[i].size(); j++) if (qwq[i][j] == qwq[i][j - 1]) ans[qwq[i][j].second * fac[qwq[i][j].first]] = 1;
        int cnt = unique(qwq[i].begin(), qwq[i].end()) - qwq[i].begin();
        for (int j = 0; j < cnt; j++)
            for (int k = j + 1; k < cnt; k++) {
                if (qwq[i][j].first == qwq[i][k].first) continue;
                ans[qwq[i][j].second * fac[qwq[i][j].first] + qwq[i][k].second * fac[qwq[i][k].first]] = 1;
            }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < fac[k + 1]; j++) {
            if (j / fac[i] % (i + 1) == 0) {
                for (int q = 1; q <= i; q++) ans[j + q * fac[i]] |= ans[j];
            }
        }
    }
    int res = 0;
    for (int i = 0; i < fac[k + 1]; i++) {
        int qwq = 1;
        for (int j = 1; j <= k; j++) if (i / fac[j] % (j + 1) == 0) qwq = 0;
        if (qwq == 1 && ans[i] == 0) res++;
    }
    printf("%d\n", res);
}