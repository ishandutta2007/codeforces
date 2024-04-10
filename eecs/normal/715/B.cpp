#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 10010;
int n, m, L, s, t, u[maxn], v[maxn], w[maxn], pre[maxn];
ll d[maxn];
vector<tuple<int, int, int>> G[maxn];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;

int main() {
    scanf("%d %d %d %d %d", &n, &m, &L, &s, &t);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    auto dijkstra = [&]() {
        fill(d, d + n, LLONG_MAX);
        Q.emplace(d[s] = 0, s);
        while (!Q.empty()) {
            auto p = Q.top(); Q.pop();
            if (p.first ^ d[p.second]) continue;
            for (auto e : G[p.second]) {
                if (d[get<0>(e)] > p.first + get<1>(e)) {
                    Q.emplace(d[get<0>(e)] = p.first + get<1>(e), get<0>(e));
                    pre[get<0>(e)] = get<2>(e);
                }
            }
        }
        return d[t];
    };
    auto chk = [&](int x) {
        for (int i = 0; i < n; i++) {
            G[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int t = w[i] ? w[i] : x;
            G[u[i]].emplace_back(v[i], t, i);
            G[v[i]].emplace_back(u[i], t, i);
        }
        return dijkstra();
    };
    auto print = [&]() {
        puts("YES");
        for (int i = 1; i <= m; i++) {
            printf("%d %d %d\n", u[i], v[i], w[i]);
        }
    };
    int l = 1, r = 1e9, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) >= L ? r = (ans = mid) - 1 : l = mid + 1;
    }
    if (!~ans) puts("NO"), exit(0);
    chk(ans);
    vector<int> id;
    for (int i = 1; i <= m; i++) {
        if (!w[i]) id.push_back(i), w[i] = ans;
    }
    if (chk(0) == L) print(), exit(0);
    if (ans == 1) puts("NO"), exit(0);
    l = 0, r = (int)id.size() - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        for (int i = 0; i <= mid; i++) w[id[i]]--;
        auto v = chk(0);
        if (v == L) print(), exit(0);
        else if (v < L) r = mid - 1;
        else l = mid + 1;
        for (int i = 0; i <= mid; i++) w[id[i]]++;
    }
    puts("NO");
    return 0;
}