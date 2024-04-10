#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, rt, tot;
mt19937 rnd(time(0));

struct node {
    int ls, rs, key, val, tag, sz;
    void inc(int v) { val += v, tag += v; }
} t[maxn << 1];

int new_node(int v) {
    t[++tot] = (node){0, 0, (int)rnd(), v, 0, 1};
    return tot;
}

void maintain(int k) {
    t[k].sz = t[t[k].ls].sz + t[t[k].rs].sz + 1;
}

void pushdown(int k) {
    if (!t[k].tag) return;
    t[t[k].ls].inc(t[k].tag);
    t[t[k].rs].inc(t[k].tag), t[k].tag = 0;
}

int merge(int k1, int k2) {
    if (!k1 || !k2) return k1 | k2;
    pushdown(k1), pushdown(k2);
    if (t[k1].key > t[k2].key) {
        t[k1].rs = merge(t[k1].rs, k2);
        maintain(k1); return k1;
    }
    t[k2].ls = merge(k1, t[k2].ls);
    maintain(k2); return k2;
}

void split(int k, int v, int &l, int &r) {
    if (!k) { l = r = 0; return; }
    pushdown(k);
    if (t[k].val <= v) l = k, split(t[k].rs, v, t[k].rs, r);
    else r = k, split(t[k].ls, v, l, t[k].ls);
    maintain(k);
}

int main() {
    scanf("%d", &n);
    auto del = [&](int v) {
        int k1, k2, k3;
        split(rt, v, k1, k2);
        int k = k2;
        while (t[k].ls) pushdown(k), k = t[k].ls;
        split(k2, t[k].val, k3, k2);
        rt = merge(k1, k2);
    };
    auto add = [&](int l, int r) {
        int k1, k2, k3;
        split(rt, r, k1, k2);
        split(k1, l - 1, k1, k3);
        t[k3].inc(1), rt = merge(merge(k1, k3), k2);
    };
    auto ins = [&](int v) {
        int k1, k2, k3;
        split(rt, v, k1, k2);
        split(k1, v - 1, k1, k3);
        if (!k3) k3 = new_node(v);
        rt = merge(merge(k1, k3), k2);
    };
    while (n--) {
        int l, r;
        scanf("%d %d", &l, &r);
        del(r - 1), add(l, r - 1), ins(l);
    }
    printf("%d\n", t[rt].sz);
    return 0;
}