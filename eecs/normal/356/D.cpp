#include <bits/stdc++.h>
using namespace std;

const int maxn = 70010;
int n, s, a[maxn], id[maxn], mark[maxn];
bitset<maxn> cur, b[25010];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [&](int x, int y) { return a[x] > a[y]; });
    s -= a[id[1]];
    if (s < 0 || n == 1 && s) puts("-1"), exit(0);
    for (int i = 2, j; i <= n; i = j + 1) {
        j = min(n, i + 25000 - 1);
        cur.reset(), cur[0] = 1;
        b[j + 1 - i] = cur;
        for (int k = n; k >= i; k--) {
            cur = cur | (cur << a[id[k]]);
            if (k <= j + 1) b[k - i] = cur;
        }
        if (!cur[s]) puts("-1"), exit(0);
        for (int k = i; k <= j; k++) {
            if (!b[k - i + 1][s]) s -= a[id[k]], mark[k] = 1;
        }
    }
    for (int i = 2, lst = 1; i <= n; i++) if (!mark[i]) {
        G[id[lst]].push_back(id[i]), lst = i;
    }
    for (int i = 1; i <= n; i++) {
        int c = a[i];
        for (int j : G[i]) c -= a[j];
        printf("%d %d", c, G[i].size());
        for (int j : G[i]) printf(" %d", j);
        putchar('\n');
    }
    return 0;
}