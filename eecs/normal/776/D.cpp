#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, r[maxn], fa[maxn];
vector<int> id[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    fa[find(x)] = find(y);
}

bool test(int x, int y) {
    return find(x) == find(y);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &r[i]);
    }
    for (int i = 1, x; i <= m; i++) {
        scanf("%d", &x);
        while (x--) {
            int j; scanf("%d", &j);
            id[j].push_back(i);
        }
    }
    iota(fa + 1, fa + 2 * m + 1, 1);
    for (int i = 1; i <= n; i++) {
        if (!r[i]) {
            if (test(id[i][0], id[i][1])) puts("NO"), exit(0);
            unite(id[i][0], id[i][1] + m), unite(id[i][0] + m, id[i][1]);
        } else {
            if (test(id[i][0], id[i][1] + m)) puts("NO"), exit(0);
            unite(id[i][0], id[i][1]), unite(id[i][0] + m, id[i][1] + m);
        }
    }
    puts("YES");
    return 0;
}