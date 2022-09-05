#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, ans, sum, all, w[maxn], c[maxn];
tuple<int, int, int> p[maxn];
vector<pair<int, int>> E;
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &get<0>(p[i]), &get<1>(p[i]));
        if (get<0>(p[i]) > get<1>(p[i])) swap(get<0>(p[i]), get<1>(p[i])), get<2>(p[i]) = 1;
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
        w[i] = get<2>(p[i]);
    }
    set<pair<int, int>> S;
    int mn = INT_MAX;
    vector<pair<int, int>> V;
    for (int i = 1; i <= n; i++) {
        if (mn < get<0>(p[i])) puts("-1"), exit(0);
        mn = min(mn, get<1>(p[i]));
        if (S.empty()) {
            S.emplace(get<1>(p[i]), i);
        } else {
            if (S.begin()->first > get<1>(p[i])) {
                S.emplace(get<1>(p[i]), i);
            } else {
                auto tmp = *S.begin();
                while (!S.empty() && S.begin()->first < get<1>(p[i])) {
                    E.emplace_back(S.begin()->second, i);
                    S.erase(S.begin());
                }
                S.insert(tmp);
            }
        }
    }
    function<void(int)> dfs = [&](int v) {
        ans += (w[v] ^ c[v]), all++;
        for (int u : G[v]) {
            if (!~c[u]) c[u] = c[v] ^ 1, dfs(u);
            else if (c[u] == c[v]) puts("-1"), exit(0);
        }
    };
    for (auto e : E) {
        int u = e.first, v = e.second;
        G[u].push_back(v), G[v].push_back(u);
    }
    memset(c, -1, sizeof(c));
    for (int i = 1; i <= n; i++) if (!~c[i]) {
        c[i] = ans = all = 0, dfs(i), sum += min(ans, all - ans);
    }
    V.clear();
    for (int i = 1; i <= n; i++) {
        if (!c[i]) V.emplace_back(get<0>(p[i]), get<1>(p[i]));
        else V.emplace_back(get<1>(p[i]), get<0>(p[i]));
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size() - 1; i++) {
        if (V[i].second < V[i + 1].second) puts("-1"), exit(0);
    }
    printf("%d\n", sum);
    return 0;
}