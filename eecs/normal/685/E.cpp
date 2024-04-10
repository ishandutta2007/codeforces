#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010, maxm = 200010;
int n, m, q, u[maxm], v[maxm], t[maxn][maxn];
bool ans[maxm];
vector<tuple<int, int, int, int>> Q[maxm];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }
    for (int i = 1, l, r, s, t; i <= q; i++) {
        scanf("%d %d %d %d", &l, &r, &s, &t);
        Q[l].emplace_back(s, t, r, i);
    }
    memset(t, 0x3f, sizeof(t));
    for (int i = m; i; i--) {
        t[u[i]][v[i]] = t[v[i]][u[i]] = i;
        for (int j = 1; j <= n; j++) {
            t[u[i]][j] = t[v[i]][j] = min(t[u[i]][j], t[v[i]][j]);
        }
        for (auto p : Q[i]) {
            ans[get<3>(p)] = t[get<0>(p)][get<1>(p)] <= get<2>(p);
        }
    }
    for (int i = 1; i <= q; i++) {
        puts(ans[i] ? "Yes" : "No");
    }
    return 0;
}