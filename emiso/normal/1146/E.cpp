#include <bits/stdc++.h>

using namespace std;

#define MN 100010

int n, q, a[MN], tree[4*MN], lazy[4*MN], x;
char op;

void push(int id, int l, int r) {
    if(lazy[id]) {
        if(lazy[id] == 2 || lazy[id] == 3) {
            tree[id] = lazy[id];
            if(l != r) {
                lazy[id*2]   = lazy[id];
                lazy[id*2+1] = lazy[id];
            }
        } else if(lazy[id] == 1) {
            tree[id] ^= 1;
            if(l != r) {
                lazy[id*2]   ^= 1;
                lazy[id*2+1] ^= 1;
            }
        }
        lazy[id] = 0;
    }
}

void update(int id, int l, int r, int lq, int rq, int op) {
    push(id, l, r);
    if(lq > rq || r < lq || rq < l) return;
    if(lq <= l && r <= rq) {
        lazy[id] = op;
        push(id, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(id*2,   l,   m, lq, rq, op);
    update(id*2+1, m+1, r, lq, rq, op);
}

int query(int id, int l, int r, int pos) {
    push(id, l, r);
    if(l == r) return tree[id];
    int m = (l + r) / 2;
    if(pos <= m) return query(id*2, l, m, pos);
    return query(id*2+1, m+1, r, pos);
}

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n ; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < q; i++) {
        scanf(" %c %d", &op, &x);
        if(op == '<') {
            if(x > 0) {
                update(1, 1, 100000, x, 100000, 2);
                update(1, 1, 100000, 1, x-1, 1);
            } else {
                update(1, 1, 100000, abs(x)+1, 100000, 2);
            }
        } else if(op == '>') {
            if(x > 0) {
                update(1, 1, 100000, x+1, 100000, 3);
            } else {
                update(1, 1, 100000, 1, abs(x)-1, 1);
                update(1, 1, 100000, abs(x), 100000, 3);
            }
        } else assert(false);
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            printf("0 ");
            continue;
        }

        int x = query(1, 1, 100000, abs(a[i]));

        if(x == 2) printf("%d ", abs(a[i]));
        else if(x == 3) printf("%d ", -abs(a[i]));
        else if(x == 1) printf("%d ", -a[i]);
        else printf("%d ", a[i]);
    }
    return 0;
}