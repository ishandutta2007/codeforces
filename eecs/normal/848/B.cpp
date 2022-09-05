#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, w, h, g[maxn], p[maxn], t[maxn], r[maxn];
vector<int> X[maxn];
vector<pair<int, int>> Y[maxn];

int main() {
    scanf("%d %d %d", &n, &w, &h);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &g[i], &p[i], &t[i]);
        r[i] = p[i] - t[i] + 100000;
        if (g[i] == 1) {
            X[r[i]].push_back(p[i]);
            Y[r[i]].emplace_back(p[i], -h);
        } else {
            X[r[i]].push_back(-p[i]);
            Y[r[i]].emplace_back(w, -p[i]);
        }
    }
    for (int i = 0; i < maxn; i++) {
        sort(X[i].begin(), X[i].end());
        sort(Y[i].begin(), Y[i].end());
    }
    for (int i = 1; i <= n; i++) {
        int t = g[i] == 1 ? p[i] : -p[i];
        int j = lower_bound(X[r[i]].begin(), X[r[i]].end(), t) - X[r[i]].begin();
        printf("%d %d\n", Y[r[i]][j].first, -Y[r[i]][j].second);
    }
    return 0;
}