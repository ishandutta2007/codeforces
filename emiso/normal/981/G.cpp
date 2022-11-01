#include <bits/stdc++.h>
using namespace std;

struct segment_tree {
    #define MN 200020
    #define MOD 998244353
    vector<int> tree, lazy_add, lazy_mul;
    int n;

    segment_tree(int N) {
        n = N;
        tree.resize(4*n);
        lazy_add.resize(4*n);
        lazy_mul.resize(4*n, 1);
    }
    segment_tree(int N, vector<int> &arr) {n = N; tree = arr; build(1, 1, n);}

    void build(int id, int l, int r) {assert(false);}

    void push(int id, int l, int r) {
        if(lazy_add[id] == 0 && lazy_mul[id] == 1) return;

        tree[id] = (1LL * tree[id] * lazy_mul[id]) % MOD;
        tree[id] = (tree[id] + 1LL*lazy_add[id]*(r - l + 1)) % MOD;

        if(l != r) {
            lazy_add[id<<1] = (1LL*lazy_add[id<<1]*lazy_mul[id] + lazy_add[id]) % MOD;
            lazy_add[id<<1|1] = (1LL*lazy_add[id<<1|1]*lazy_mul[id] + lazy_add[id]) % MOD;
            lazy_mul[id<<1] = 1LL * lazy_mul[id<<1] * lazy_mul[id] % MOD;
            lazy_mul[id<<1|1] = 1LL * lazy_mul[id<<1|1] * lazy_mul[id] % MOD;
        }
        lazy_add[id] = 0;
        lazy_mul[id] = 1;
    }

    void update1(int id, int l, int r, int lq, int rq) {
        push(id, l, r);
        if(l > rq || r < lq) return;
        if(lq <= l && r <= rq) {
            lazy_add[id]++;
            push(id, l, r);
        } else {
            int m = (l + r)>>1;
            update1(id<<1, l, m, lq, rq);
            update1(id<<1|1, m+1, r, lq, rq);
            tree[id] = tree[id<<1] + tree[id<<1|1];
            if(tree[id] >= MOD) tree[id] -= MOD;
        }
    }

    void update2(int id, int l, int r, int lq, int rq) {
        push(id, l, r);
        if(l > rq || r < lq) return;
        if(lq <= l && r <= rq) {
            lazy_mul[id] = 2;
            push(id, l, r);
        } else {
            int m = (l + r)>>1;
            update2(id<<1, l, m, lq, rq);
            update2(id<<1|1, m+1, r, lq, rq);
            tree[id] = tree[id<<1] + tree[id<<1|1];
            if(tree[id] >= MOD) tree[id] -= MOD;
        }
    }

    int query(int id, int l, int r, int lq, int rq) {
        push(id, l, r);
        if(l > rq || r < lq) return 0;
        if(lq <= l && r <= rq) return tree[id];

        int m = (l + r)>>1;
        int ret = query(id<<1, l, m, lq, rq)
                    + query(id<<1|1, m+1, r, lq, rq);
        if(ret >= MOD) ret -= MOD;
        return ret;
    }

    void update1(int lq, int rq) {update1(1, 1, n, lq, rq);}
    void update2(int lq, int rq) {update2(1, 1, n, lq, rq);}
    int query(int lq, int rq) {return query(1, 1, n, lq, rq);}
};
segment_tree *st;

struct property_tree {
    property_tree *l, *r;
    int L, R;
    bool has_property;

    property_tree(int LB, int RB) {
        l = r = NULL;
        L = LB; R = RB;
        has_property = false;
    }

    void update(int lb, int rb) {
        if(has_property) st->update2(max(L, lb), min(R, rb));
        else if(!(lb <= L && R <= rb) || l || r) {
            int M = (L+R)>>1;

            if(M >= lb) {
                if(!l) l = new property_tree(L, M);
                l->update(lb, rb);
            } if(M < rb) {
                if(!r) r = new property_tree(M+1, R);
                r->update(lb, rb);
            }

            if(l && r && l->has_property && r->has_property) {
                has_property = true;
                delete l; delete r;
                l = r = NULL;
            }
        } else {
            has_property = true;
            st->update1(L, R);
        }
    }

    ~property_tree() {
        delete l;
        delete r;
    }
};
property_tree *pt[200020];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    st = new segment_tree(n);
    for(int i = 1; i <= n; i++) {
        pt[i] = new property_tree(1, n);
    }

    while(q--) {
        int t, l, r, x;
        scanf("%d %d %d", &t, &l, &r);
        if(t == 1) {
            scanf("%d", &x);
            pt[x]->update(l, r);
        } else {
            printf("%d\n", st->query(l, r));
        }
    }
    return 0;
}