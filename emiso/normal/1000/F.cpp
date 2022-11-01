#include <bits/stdc++.h>

#define MN 500050

using namespace std;

int tree[4*MN], ans[MN], arr[MN], arr2[MN];

int merge(int t1, int t2) {
    if(arr2[t1] > arr2[t2]) return t1;
    return t2;
}

void update(int node, int l, int r, int x, int val) {
    assert(x != MN);
    if(x < l || r < x) return;
    if(l == r) {
        arr2[x] = val;
        tree[node] = x;
        return;
    }
    int m = (l + r) / 2;
    update(node*2, l, m, x, val);
    update(node*2+1, m+1, r, x, val);
    tree[node] = merge(tree[node*2], tree[node*2+1]);
}

int query(int node, int l, int r, int lq, int rq) {
    if(r < lq || rq < l) return 0;
    if(lq <= l && r <= rq) return tree[node];
    int m = (l + r) / 2;
    int q1 = query(node*2, l, m, lq, rq);
    int q2 = query(node*2+1, m+1, r, lq, rq);
    return merge(q1, q2);
}

vector<pair<int, int> > queries[MN];
int nxt[MN], lst[MN], fst[MN];

int main() {
    int n, q, l, r, a;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a); arr[i] = a;

        nxt[i] = MN;
        if(!fst[a]) fst[a] = i;
        if(lst[a]) nxt[lst[a]] = i;
        lst[a] = i;
    }

    for(int i = 1; i < MN; i++)
        if(fst[i])
            update(1, 1, MN, fst[i], nxt[fst[i]]);

    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        queries[l].emplace_back(r, i);
    }

    for(int i = 1; i <= n; i++) {
        for(pair<int, int> p : queries[i]) {
            a = query(1, 1, MN, i, p.first);
            ans[p.second] = (arr2[a] > p.first) ? arr[a] : 0;
        }

        a = nxt[i];
        if(a < MN) update(1, 1, MN, a, nxt[a]);
    }

    for(int i = 0; i < q; i++)
        printf("%d\n", ans[i]);

    return 0;
}