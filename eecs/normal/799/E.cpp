#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, K, A, B, tot, c[maxn], x[maxn], y[maxn];
long long pre1[maxn], pre2[maxn], pre[maxn];
bool mark[maxn], has[maxn];
struct node { int l, r, cnt; long long s; } t[maxn * 35];

#define mid ((l + r) >> 1)
void ins(int &k, int l, int r, int p) {
    if (!k) k = ++tot;
    t[k].cnt++, t[k].s += p;
    if (l == r) return;
    mid >= p ? ins(t[k].l, l, mid, p) : ins(t[k].r, mid + 1, r, p);
}

long long query(int k, int l, int r, int p) {
    if (l == r) return 1LL * p * l;
    if (t[t[k].l].cnt >= p) return query(t[k].l, l, mid, p);
    return t[t[k].l].s + query(t[k].r, mid + 1, r, p - t[t[k].l].cnt);
}

int main() {
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    scanf("%d", &A);
    for (int i = 1; i <= A; i++) {
        scanf("%d", &x[i]), mark[x[i]] = has[x[i]] = 1;
    }
    scanf("%d", &B);
    vector<int> V, V1, V2;
    for (int i = 1; i <= B; i++) {
        scanf("%d", &y[i]), has[y[i]] = 1;
        if (mark[y[i]]) V.push_back(y[i]), mark[y[i]] = 0;
        else V2.push_back(y[i]);
    }
    for (int i = 1; i <= A; i++) {
        if (mark[x[i]]) V1.push_back(x[i]);
    }
    sort(V.begin(), V.end(), [&](int i, int j) { return c[i] < c[j]; });
    sort(V1.begin(), V1.end(), [&](int i, int j) { return c[i] < c[j]; });
    sort(V2.begin(), V2.end(), [&](int i, int j) { return c[i] < c[j]; });
    for (int i = 0; i < V.size(); i++) {
        pre[i + 1] = pre[i] + c[V[i]];
    }
    for (int i = 0; i < V1.size(); i++) {
        pre1[i + 1] = pre1[i] + c[V1[i]];
    }
    for (int i = 0; i < V2.size(); i++) {
        pre2[i + 1] = pre2[i] + c[V2[i]];
    }
    long long ans = LLONG_MAX;
    int rt = 0;
    for (int i = 1; i <= n; i++) {
        if (!has[i]) ins(rt, 1, 1e9, c[i]);
    }
    for (int i = 0, j1 = (int)V1.size() - 1, j2 = (int)V2.size() - 1; i <= V.size(); i++) {
        int t = max(0, K - i);
        if (t > V1.size() || t > V2.size()) continue;
        long long s = pre[i] + pre1[t] + pre2[t];
        int rem = m - i - 2 * t;
        if (rem < 0) continue;
        while (j1 >= t) ins(rt, 1, 1e9, c[V1[j1--]]);
        while (j2 >= t) ins(rt, 1, 1e9, c[V2[j2--]]);
        ans = min(ans, s + query(rt, 1, 1e9, rem));
    }
    printf("%lld\n", ans == LLONG_MAX ? -1 : ans);
    return 0;
}