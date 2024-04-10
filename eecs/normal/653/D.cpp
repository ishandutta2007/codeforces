#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 55;
int n, m, x, cnt, u[510], v[510], w[510], head[maxn], lev[maxn], cur[maxn];
struct edge { int to, nxt; ll cap; } e[1010];

void add(int u, int v, ll cap) {
    e[cnt] = (edge){v, head[u], cap}, head[u] = cnt++;
    e[cnt] = (edge){u, head[v], 0}, head[v] = cnt++;
}

bool bfs(int s, int t) {
    fill(lev + 1, lev + n + 1, 0);
    queue<int> Q; Q.push(s), lev[s] = 1;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = head[v]; ~i; i = e[i].nxt) {
            if (e[i].cap && !lev[e[i].to]) {
                Q.push(e[i].to), lev[e[i].to] = lev[v] + 1;
            }
        }
    }
    return lev[t];
}

ll dfs(int v, int t, ll f) {
    if (v == t) return f;
    ll inc = 0;
    for (int &i = cur[v]; ~i; i = e[i].nxt) {
        if (e[i].cap && lev[e[i].to] == lev[v] + 1) {
            ll d = dfs(e[i].to, t, min(e[i].cap, f - inc));
            e[i].cap -= d, e[i ^ 1].cap += d, inc += d;
            if (inc == f) break;
        }
    }
    return inc;
}

int main() {
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    auto chk = [&](long double w) {
        cnt = 0, memset(head, -1, sizeof(head));
        for (int i = 1; i <= m; i++) {
            add(u[i], v[i], min((ll)x, (ll)floor(::w[i] / w)));
        }
        int f = 0;
        while (bfs(1, n) && f < x) {
            memcpy(cur, head, sizeof(cur));
            f += dfs(1, n, x - f);
        }
        return f >= x;
    };
    double st = clock();
    long double l = 0, r = 1e7;
    while ((clock() - st) / CLOCKS_PER_SEC < 1.5) {
        long double mid = (l + r) / 2;
        chk(mid) ? l = mid : r = mid;
    }
    cout << setprecision(9) << fixed << l * x << endl;
    return 0;
}