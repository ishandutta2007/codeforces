#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[200100];
int n, m, cc=1, op, x, val;
int tree[200100];
int a[200100];
int level[200100];
int left[200100], right[200100];
//int pre[200100];

int dfs(int v, int p, int d) {
    left[v] = cc;
    right[v] = cc++;
    level[v] = d;

    for (int i = 0; i < g[v].size(); i++) {
        if (g[v][i] == p) continue;
        right[v] = max(right[v], dfs(g[v][i], v, d+1));
    }

    return right[v];
}

int read(int x) {
    int s = 0;
    while (x > 0) {
        s += tree[x];
        x -= x&-x;
    }
    return s;
}

void update(int x, int delta) {
    if (x == 0) return;
    while (x <= n) {
        tree[x] += delta;
        x += x&-x;
    }
}

void insert(int x, int val) {
    if (level[x]&1) val = -val;
    update(left[x], val);
    update(right[x]+1, -val);
}

int query(int x) {
    int v = read(left[x]);
    if (level[x] & 1) v = -v;
    return v;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n-1; i++) {
        int aa,bb;
        scanf("%d %d", &aa, &bb);
        aa--; bb--;
        g[aa].push_back(bb);
        g[bb].push_back(aa);
    }

    dfs(0, -1, 0);

    for (int i = 0; i < m; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d", &x, &val); x--;
            insert(x, val);
        }
        else {
            scanf("%d", &x); x--;
            printf("%d\n", query(x) + a[x]);
        }
    }
}