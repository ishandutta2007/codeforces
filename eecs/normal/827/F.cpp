#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> T;
const int maxn = 1000010;
int n, m, cur[maxn];
vector<T> G[maxn];
priority_queue<T, vector<T>, greater<T>> Q;

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v, l, r;
        scanf("%d %d %d %d", &u, &v, &l, &r), r--;
        if (l < r || l & 1) {
            G[u + n].emplace_back(l + !(l & 1), r - !(r & 1), v);
            G[v + n].emplace_back(l + !(l & 1), r - !(r & 1), u);
        }
        if (l < r || !(l & 1)) {
            G[u].emplace_back(l + (l & 1), r - (r & 1), v + n);
            G[v].emplace_back(l + (l & 1), r - (r & 1), u + n);
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        sort(G[i].begin(), G[i].end());
    }
    Q.emplace(0, 0, 1);
    while (!Q.empty()) {
        auto p = Q.top(); Q.pop();
        if (get<2>(p) == n || get<2>(p) == 2 * n) {
            printf("%d\n", get<0>(p)), exit(0);
        }
        for (int v = get<2>(p), &i = cur[v]; i < G[v].size(); i++) {
            auto q = G[v][i];
            if (get<0>(q) > get<1>(p)) break;
            if (get<1>(q) < get<0>(p)) continue;
            Q.emplace(max(get<0>(p), get<0>(q)) + 1, get<1>(q) + 1, get<2>(q));
        }
    }
    puts("-1");
    return 0;
}