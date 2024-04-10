#include <bits/stdc++.h>
#define mid (l + r >> 1)
using namespace std;

const int maxn = 300010;
int n, m, tot, rt[maxn], num[maxn], x[maxn], y[maxn], pre[maxn];
pair<int, int> p[maxn];
map<pair<int, int>, int> mp;
struct node { int l, r, s; } t[maxn * 30];

void ins(int &k1, int k2, int l, int r, int p) {
    t[k1 = ++tot] = t[k2], t[k1].s++;
    if (l == r) return;
    if (mid >= p) ins(t[k1].l, t[k2].l, l, mid, p);
    else ins(t[k1].r, t[k2].r, mid + 1, r, p);
}

int query(int k, int l, int r, int ql, int qr) {
    if (!k || l >= ql && r <= qr) return t[k].s;
    int s = 0;
    if (mid >= ql) s += query(t[k].l, l, mid, ql, qr);
    if (mid < qr) s += query(t[k].r, mid + 1, r, ql, qr);
    return s;
}

pair<int, int> get(int i, int j) {
    int dx = x[j] - x[i];
    int dy = y[j] - y[i];
    int g = __gcd(dx, dy);
    if (g < 0) g *= -1;
    dx /= g, dy /= g;
    return {dx, dy};
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]), rt[i] = rt[i - 1];
        for (int j = 1; j <= num[i]; j++) {
            scanf("%d %d", &x[j], &y[j]);
            if (j == 1) continue;
            int id = num[i - 1] + j - 1;
            p[id] = get(j - 1, j);
            pre[id] = mp[p[id]];
            ins(rt[i], rt[i], 0, n, pre[id]);
        }
        int id = num[i - 1] + num[i];
        p[id] = get(num[i], 1);
        pre[id] = mp[p[id]];
        ins(rt[i], rt[i], 0, n, pre[id]);
        num[i] += num[i - 1];
        for (int j = num[i - 1] + 1; j <= num[i]; j++) {
            mp[p[j]] = i;
        }
    }
    scanf("%d", &m);
    for (int i = 1, l, r; i <= m; i++) {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(rt[r], 0, n, 0, l - 1) - num[l - 1]);
    }
    return 0;
}