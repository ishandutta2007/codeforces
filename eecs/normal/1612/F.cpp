#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, q, f[maxn], g[maxn];
vector<int> V[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    bool flag = 0;
    if (n > m) swap(n, m), flag = 1;
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (flag) swap(x, y);
        V[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        sort(V[i].begin(), V[i].end());
    }
    memset(f, -1, sizeof(f)), f[1] = 1;
    for (int $ = 0; $ <= 60; $++) {
        if (f[n] == m) printf("%d\n", $), exit(0);
        memcpy(g, f, sizeof(g));
        for (int i = 1; i <= n; i++) if (~f[i]) {
            int k = i + f[i] + binary_search(V[i].begin(), V[i].end(), f[i]);
            g[min(n, k)] = max(g[min(n, k)], f[i]);
            g[i] = max(g[i], min(k, m));
        }
        swap(f, g);
    }
    for (int $ = 61; ; $++) {
        if (f[n] >= m) printf("%d\n", $), exit(0);
        f[n] = max(f[n], n + f[n] + binary_search(V[n].begin(), V[n].end(), f[n]));
    }
    return 0;
}