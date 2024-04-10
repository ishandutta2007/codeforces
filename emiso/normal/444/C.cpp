#include <bits/stdc++.h>
#define MN 100010
using namespace std;
typedef long long ll;

struct st {
    ll tree[MN<<2], lazy[MN<<2];
    void push(int id, int l, int r) {
        if(!lazy[id]) return;
        tree[id] += lazy[id] * (r - l + 1);
        if(l != r) {
            lazy[id<<1] += lazy[id];
            lazy[id<<1|1] += lazy[id];
        }
        lazy[id] = 0;
    }
    void upd(int id, int l, int r, int lq, int rq, int delta) {
        push(id, l, r);
        if(rq < l || r < lq) return;
        if(lq <= l && r <= rq) {
            lazy[id] += delta;
            push(id, l, r);
        } else {
            int m = (l+r)>>1;
            upd(id<<1, l, m, lq, rq, delta);
            upd(id<<1|1, m+1, r, lq, rq, delta);
            tree[id] = tree[id<<1] + tree[id<<1|1];
        }
    }
    ll query(int id, int l, int r, int lq, int rq) {
        push(id, l, r);
        if(rq < l || r < lq) return 0;
        if(lq <= l && r <= rq) return tree[id];
        int m = (l+r)>>1;
        return query(id<<1, l, m, lq, rq)
                + query(id<<1|1, m+1, r, lq, rq);
    }
} tree;

int n, m, t, l, r, x;

#include <ext/rope>
using namespace __gnu_cxx;
struct seg { int l, r, x; };
rope<seg> seq;

void build() {
    for(int i = 1; i <= n; i++)
        seq.push_back(seg{i, i, i});
}

void put(int L, int R, int X) {
    int l = 0, r = seq.size()-1, m, ST;
    while(l < r) {
        m = (l+r)/2;
        if(seq[m].r >= L) r = m;
        else l = m + 1;
    }
    if(seq[l].l < L) {
        seg tmp = seq[l];
        seg tmp2 = seg{L, tmp.r, tmp.x};
        tmp.r = L-1;

        seq.erase(l, 1);
        seq.insert(l, tmp);
        l++;
        seq.insert(l, tmp2);
    }
    ST = l;

    for(; l < seq.size();) {
        seg tmp = seq[l];
        if(tmp.r > R) break;
        tree.upd(1, 1, n, tmp.l, tmp.r, abs(X - tmp.x));
        seq.erase(l, 1);
    }

    if(l < seq.size() && seq[l].r > R) {
        seg tmp = seq[l];
        tree.upd(1, 1, n, tmp.l, R, abs(X - tmp.x));
        tmp.l = R+1;

        seq.erase(l, 1);
        seq.insert(l, tmp);
    }

    seq.insert(ST, seg{L, R, X});
}

int main() {
    scanf("%d %d", &n, &m);
    build();
    while(m--) {
        scanf("%d %d %d", &t, &l, &r);
        if(t == 1) {
            scanf("%d", &x);
            put(l, r, x);
        } else {
            printf("%lld\n", tree.query(1, 1, n, l, r));
        }
    }
    return 0;
}