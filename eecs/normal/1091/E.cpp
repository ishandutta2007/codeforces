#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 500010;
int n, a[maxn], b[maxn];
ll pre[maxn], coef[maxn], c1[maxn], c2[maxn];
vector<int> ans;
struct node { ll mn, tag; } t[maxn << 2];

void add(ll *c, int p, int v) {
    for (p++; p <= n + 1; p += p & -p) c[p] += v;
}

ll sum(ll *c, int p) {
    ll s = 0;
    for (p++; p; p -= p & -p) s += c[p];
    return s;
}

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void pushdown(int k) {
    t[ls].mn += t[k].tag, t[ls].tag += t[k].tag;
    t[rs].mn += t[k].tag, t[rs].tag += t[k].tag, t[k].tag = 0;
}

void build(int k, int l, int r) {
    if (l == r) { t[k].mn = 1LL * l * (l - 1) + coef[l] - pre[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k].mn = min(t[ls].mn, t[rs].mn);
}

void add(int k, int l, int r, int ql, int qr, ll v) {
    if (l >= ql && r <= qr) { t[k].mn += v, t[k].tag += v; return; }
    if (t[k].tag) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    t[k].mn = min(t[ls].mn, t[rs].mn);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, greater<int>());
    copy(a + 1, a + n + 1, b + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = n; i; i--) {
        add(c1, a[i], 1);
        add(c2, a[i], a[i]);
        coef[i - 1] = sum(c2, i - 1) + (i - 1) * (n - i + 1 - sum(c1, i - 1));
    }
    build(1, 1, n);
    if (t[1].mn >= 0 && pre[n] % 2 == 0) ans.push_back(0);
    for (int i = 1; i <= n && b[i]; i++) {
        int l = 1;
        for (int j = 19; ~j; j--) {
            if (l + (1 << j) <= n && a[l + (1 << j)] > b[i]) l += 1 << j;
        }
        if (a[l] > b[i]) l++;
        assert(a[l] == b[i]);
        int r = n, p;
        while (l <= r) {
            if (b[i] == a[mid]) l = (p = mid) + 1;
            else r = mid - 1;
        }
        add(1, 1, n, p, n, 1);
        if (a[p] < p) add(1, 1, n, a[p], p - 1, -1);
        a[p]--;
        if (t[1].mn >= 0 && pre[n] % 2 == i % 2) ans.push_back(i);
    }
    if (ans.empty()) puts("-1");
    else for (int x : ans) printf("%d ", x);
    return 0;
}