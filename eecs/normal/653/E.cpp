#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, m, K, a[maxn], b[maxn], fa[maxn], nxt[maxn], ver[maxn];
bool flag, ban[maxn], has[maxn];
vector<int> V[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x ^ y) fa[x] = y, flag = 1;
}

int main() {
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        if (a[i] == 1 || b[i] == 1) {
            if (a[i] == 1) ban[b[i]] = 1;
            else ban[a[i]] = 1;
        } else {
            V[a[i]].push_back(b[i]), V[b[i]].push_back(a[i]);
        }
    }
    for (int i = 2; i <= n; i++) {
        sort(V[i].begin(), V[i].end());
    }
    iota(fa + 2, fa + n + 1, 2);
    while (1) {
        flag = 0;
        for (int i = n; i > 1; i--) {
            if (i == n || find(i) != find(i + 1)) nxt[i] = i;
            else nxt[i] = nxt[i + 1];
        }
        for (int i = 2; i <= n; i++) {
            ver[i] = 0;
            int j = 2;
            while (j <= n) {
                if (binary_search(V[i].begin(), V[i].end(), j)) { j++; continue; }
                if (find(i) == find(j)) j = nxt[j] + 1;
                else break;
            }
            if (j <= n) assert(find(i) != find(j)), ver[i] = j;
        }
        for (int i = 2; i <= n; i++) {
            if (ver[i]) unite(i, ver[i]);
        }
        if (!flag) break;
    }
    int sz = 0, sum = 0;
    for (int i = 2; i <= n; i++) {
        if (i == find(i)) sz++;
        if (!ban[i]) has[find(i)] = 1, sum++;
    }
    for (int i = 2; i <= n; i++) {
        if (i == find(i) && !has[i]) puts("impossible"), exit(0);
    }
    if (sz <= K && sum >= K) puts("possible");
    else puts("impossible");
    return 0;
}