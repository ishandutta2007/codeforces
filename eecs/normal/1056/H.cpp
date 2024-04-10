#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010, SZ = 400;
int T, n, q, pos[maxn];
vector<int> V[maxn];
vector<pair<int, int>> cand[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            cand[i].clear();
        }
        bool flag = 1;
        for (int i = 1, k; i <= q; i++) {
            scanf("%d", &k), V[i].clear();
            while (k--) {
                int x; scanf("%d", &x);
                V[i].push_back(x);
            }
            if (V[i].size() > SZ) continue;
            for (int j = 0; j < V[i].size(); j++) {
                for (int k = j + 1; k < V[i].size(); k++) {
                    cand[V[i][j]].emplace_back(V[i][k], V[i][j + 1]);
                }
            }
        }
        for (int i = 1; i <= q && flag; i++) if (V[i].size() > SZ) {
            memset(pos, -1, sizeof(pos));
            for (int j = 0; j < V[i].size(); j++) pos[V[i][j]] = j;
            for (int j = 1; j <= q; j++) if (i ^ j) {
                for (int k = V[j].size() - 1, l = -1; ~k; k--) if (~pos[V[j][k]]) {
                    if (l > pos[V[j][k]] && k < V[j].size() - 1) flag &= V[i]
                        [pos[V[j][k]] + 1] == V[j][k + 1];
                    l = max(l, pos[V[j][k]]);
                }
            }
        }
        memset(pos, 0, sizeof(pos));
        for (int i = 1; i <= n && flag; i++) {
            for (auto p : cand[i]) {
                if (pos[p.first] && pos[p.first] ^ p.second) flag = 0;
                pos[p.first] = p.second;
            }
            for (auto p : cand[i]) pos[p.first] = 0;
        }
        puts(flag ? "Robot" : "Human");
    }
    return 0;
}