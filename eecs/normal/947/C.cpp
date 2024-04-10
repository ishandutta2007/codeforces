#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010, maxm = 10000000;
int n, tmp, tot = 1, a[maxn], p[maxn], sz[maxm], ed[maxm], ch[maxm][2];

void ins(int x) {
    int cur = 1;
    for (int i = 29; ~i; i--) {
        int c = x >> i & 1;
        if (!ch[cur][c]) ch[cur][c] = ++tot;
        sz[cur]++, cur = ch[cur][c];
    }
    sz[cur]++, ed[cur]++;
}

int query(int v, int x, int p) {
    int c = tmp >> p & 1, ans;
    if (sz[ch[v][c]]) {
        ans = query(ch[v][c], x, p - 1);
    } else if (sz[ch[v][c ^ 1]]) {
        ans = query(ch[v][c ^ 1], x | (1 << p), p - 1);
    } else {
        ed[v]--, ans = x;
    }
    sz[v] = sz[ch[v][0]] + sz[ch[v][1]] + ed[v];
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]), ins(p[i]);
    }
    for (int i = 1; i <= n; i++) {
        tmp = a[i], printf("%d ", query(1, 0, 29));
    }
    return 0;
}