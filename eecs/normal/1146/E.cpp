#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, q, a[maxn], t[maxn << 2][2], lim[maxn], ans[maxn];
char op[maxn][2];
pair<int, int> p[maxn];

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void upd1(int k, int l, int r, int p, int v) {
    if (l == r) { t[k][0] = v; return; }
    mid >= p ? upd1(ls, l, mid, p, v) : upd1(rs, mid + 1, r, p, v);
    t[k][0] = t[rs][t[ls][0]], t[k][1] = t[rs][t[ls][1]];
}

void upd2(int k, int l, int r, int p, int v) {
    if (l == r) { t[k][1] = v; return; }
    mid >= p ? upd2(ls, l, mid, p, v) : upd2(rs, mid + 1, r, p, v);
    t[k][0] = t[rs][t[ls][0]], t[k][1] = t[rs][t[ls][1]];
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].first), p[i].second = i;
    }
    vector<pair<int, int>> V1, V2;
    for (int i = 1; i <= q; i++) {
        scanf("%s %d", op[i], &lim[i]);
        if (op[i][0] == '<') V1.emplace_back(lim[i], i);
        else V2.emplace_back(lim[i], i);
    }
    sort(p + 1, p + n + 1);
    sort(V1.begin(), V1.end()), sort(V2.begin(), V2.end());
    for (auto p : V1) {
        upd1(1, 1, q, p.second, 1);
        upd2(1, 1, q, p.second, 1);
    }
    int p0 = -1, p1 = -1, p2 = V1.size(), p3 = V2.size();
    for (int $ = 1; $ <= n; $++) {
        int x = p[$].first, i = p[$].second;
        while (p0 + 1 < V1.size() && !(x < V1[p0 + 1].first)) upd1(1, 1, q, V1[++p0].second, 0);
        while (p1 + 1 < V2.size() && x > V2[p1 + 1].first) upd1(1, 1, q, V2[++p1].second, 1);
        x *= -1;
        while (p2 && x < V1[p2 - 1].first) upd2(1, 1, q, V1[--p2].second, 0);
        while (p3 && !(x > V2[p3 - 1].first)) upd2(1, 1, q, V2[--p3].second, 1);
        ans[i] = t[1][0] ? x : -x;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}