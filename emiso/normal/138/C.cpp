#include <bits/stdc++.h>

using namespace std;

struct event { /// t: 0-abre 1-mushroom 2-fecha
    int x, t, value, id;

    event(int x, int t, int value, int id) : x(x), t(t), value(value), id(id) {}

    bool operator < (const event &o) const {
        if(x != o.x) return x < o.x;
        return t < o.t;
    }
};

vector<event> ev;
int n, m;

#define MN 1000100

template<typename T>
struct segtree {
    T tree[4*MN];

    segtree() {
        fill(tree, tree + 4*MN, 1);
    }

    T identity() {
        return 1;
    }

    T merge(T a, T b) {
        return a * b;
    }

    void update(int id, int l, int r, int lq, int rq, T val) {
        if(r < lq || rq < l) return;
        if(lq <= l && r <= rq) {
            tree[id] = val;
            return;
        }
        int m = (l + r) / 2;
        update(id*2,   l,   m, lq, rq, val);
        update(id*2+1, m+1, r, lq, rq, val);
        tree[id] = merge(tree[id*2], tree[id*2+1]);
    }
};


int main() {
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        int a, h, l, r;
        scanf("%d %d %d %d", &a, &h, &l, &r);
        ev.emplace_back(a-h, 0, 100-l, 2*i);
        ev.emplace_back(a-1, 2, 100, 2*i);
        ev.emplace_back(a+1, 0, 100-r, 2*i+1);
        ev.emplace_back(a+h, 2, 100, 2*i+1);
    }

    for(int i = 0; i < m; i++) {
        int b, z;
        scanf("%d %d", &b, &z);
        ev.emplace_back(b, 1, z, -1);
    }

    sort(ev.begin(), ev.end());

    segtree<double> chance;
    double tot = 0;
    int zeroes = 0;

    for(event e : ev) {
        if(e.t == 1) tot += chance.tree[1] * e.value;
        if(e.t == 0) chance.update(1, 1, 2*n+2, e.id, e.id, e.value / 100.0);
        if(e.t == 2) chance.update(1, 1, 2*n+2, e.id, e.id, e.value / 100.0);
    }

    printf("%.9f\n", tot);
    return 0;
}