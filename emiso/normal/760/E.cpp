#include <bits/stdc++.h>

#define MN 201000

using namespace std;

int n, x[MN];
int tree[4 * MN], lazy[4 * MN];

void dolazy(int node, int a, int b) {
    if(lazy[node] == 0) return;

    if(a == b) {
        tree[node] += lazy[node];
        lazy[node] = 0;
        return;
    }

    tree[node] = tree[node] + lazy[node];
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
    lazy[node] = 0;
}

void update(int node, int a, int b, int x, int y, int val) {
    dolazy(node, a, b);

    if(x > b || y < a) return;
    if(x <= a && b <= y) {
        lazy[node] += val;
        dolazy(node, a, b);
        return;
    }
    dolazy(node, a, b);

    int m = (a + b)/2;
    update(node*2, a, m, x, y, val);
    update(node*2+1, m+1, b, x, y, val);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

int q1(int node, int a, int b) {
    dolazy(node, a, b);
    return tree[node];
}

int query(int node, int a, int b) {
    dolazy(node, a, b);
    if(q1(node, a, b) <= 0) return -1;

    if(a == b) return a;
    int m = (a + b)/2;

    if(q1(node*2+1, m+1, b) > 0)
        return query(node*2+1, m+1, b);
    if(q1(node*2, a, m) > 0)
        return query(node*2, a, m);
    return -1;
}

int main() {
    scanf("%d", &n);
    int p, t;

    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &p, &t);
        if(t) scanf("%d", &x[p]);

        update(1, 1, n, 1, p, t ? 1 : -1);
        int resp = query(1, 1, n);
        if(resp <= 0) printf("-1\n");
        else printf("%d\n", x[resp]);
    }

    return 0;
}