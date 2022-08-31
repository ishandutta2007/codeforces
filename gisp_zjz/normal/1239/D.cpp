#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 7;

int n, m;
vector<int> e[maxn];
bool vis[maxn];

int sz;
int mark[maxn];
bool clean[maxn];

int rev(int x) {
    if (x > n) return x - n;
    else return x + n;
}

bool ok(int u) {
    if (vis[u]) return true;
    if (vis[rev(u)]) return false;

    vis[u] = true;
    mark[sz++] = u;

    for (auto &v : e[u])
        if (!ok(v)) return false;
    return true;
}

bool work(int flag) {
    for (int i = 1; i <= n; i++) vis[i] = vis[i + n] = false;

    for (int i = 1; i <= n; i++) {
        if (vis[i] || vis[ rev(i) ]) continue;
        int T = i;
        if (i == 1) {
            if (flag) T = i;
            else T = i + n;
        }
        else {
            if (flag) T = i + n;
            else T = i;
        }

        sz = 0;
        if (!ok(T)) {
            for (int i = 0; i < sz; i++) vis[ mark[i] ] = false;
            sz = 0;
            if (!ok(rev(T))) {
                return false;
            }
        }
    }

    int p = 0;
    for (int i = 1; i <= n; i++)
        if (vis[i]) p++;

    if (p == 0 || p == n) return false;
    return true;
}

void output() {
    int p = 0;
    for (int i = 1; i <= n; i++)
        if (vis[i]) p++;
    printf("Yes\n");
    printf("%d %d\n", p, n - p);
    for (int i = 1; i <= n; i++)
        if (vis[i]) printf("%d ", i);
    puts("");
    for (int i = 1; i <= n; i++)
        if (!vis[i]) printf("%d ", i);
    puts("");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= 2*n; i++) vector<int>().swap(e[i]);
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u != v) {
                e[u].push_back(v);
                e[v + n].push_back(u + n);
            }
        }
        if (work(0)) {
            output();
            continue;
        }
        if (work(1)) {
            output();
            continue;
        }
        printf("No\n");
    }

    return 0;
}