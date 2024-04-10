#include <bits/stdc++.h>

#define MN 201000
#define w1 while(1)

using namespace std;
typedef long long ll;

struct no {
    int sum;
    no(): sum(0) {}
    no(int v) : sum(v) {}
} tree[32 * MN];

vector<no> logs;
int root[32*MN], L[32 * MN], R[32 * MN], count_, Size;

no merge(no l, no r, int x, int y) {
    no ret(0);
    ret.sum = l.sum + r.sum;
    return ret;
}

void build(int id, int l, int r) {
    tree[id] = no();
    if(l >= r) return;

    int m = (l + r) / 2;
    L[id] = count_++;
    R[id] = count_++;

    build(L[id], l, m);
    build(R[id], m+1, r);
}

int insert(int id, int l, int r, int w) {
    int idx = count_++;

    if(l == r) {
        tree[idx] = no(1);
    }
    if(l >= r) return idx;

    L[idx] = L[id];
    R[idx] = R[id];

    int m = (l + r)/2;
    if(w <= m)
        L[idx] = insert(L[idx], l, m, w);
    else
        R[idx] = insert(R[idx], m+1, r, w);

    tree[idx] = merge(tree[L[idx]], tree[R[idx]], l, r);
    return idx;
}

no query(int id, int l, int r, int st, int fn) {
    if(fn < l || r < st) return no(0);
    if(st <= l && r <= fn) return tree[id];

    int m = (l + r)/2;

    no l_ = query(L[id], l, m, st, fn);
    no r_ = query(R[id],m+1,r, st, fn);

    no ret = merge(l_, r_, l, r);
    return ret;
}

int q, pos, l, d, r, u;
ll ans, n;

int main() {
    scanf("%lld %d", &n, &q);

    count_ = 1;
    build(0, 1, MN);
    root[0] = 0;

    for(int i=1; i<=n; i++) {
        scanf("%d",&pos);
        root[i] = insert(root[i-1], 1, MN, pos);
    }

    for(int i=0; i<q; i++) {
        scanf("%d %d %d %d", &l, &d, &r, &u);

        ll q1 = query(root[l-1], 1, MN, 0, d-1).sum;
        ll q2 = query(root[l-1], 1, MN, d, u).sum;
        ll q3 = query(root[l-1], 1, MN, u+1, n).sum;
        ll q4 = query(root[r], 1, MN, u+1, n).sum - q3;
        ll q8 = query(root[r], 1, MN, 0, d-1).sum - q1;
        ll q9 = query(root[r], 1, MN, d, u).sum - q2;
        ll q5 = query(root[n], 1, MN, u+1, n).sum - q4 - q3;
        ll q7 = query(root[n], 1, MN, 0, d-1).sum - q8 - q1;
        ll q6 = query(root[n], 1, MN, d, u).sum - q9 - q2;

        ll ans = q1 * (q4 + q5 + q6 + q9);
        ans += q2 * (q4 + q5 + q6 + q7 + q8 + q9);
        ans += q3 * (q6 + q7 + q8 + q9);
        ans += q4 * (q6 + q7 + q8 + q9);
        ans += q8 * (q5 + q6 + q9);
        ans += (q9 * (q9-1) / 2);
        ans += q9 * (q5 + q6 + q7);

        printf("%lld\n", ans);
    }
    return 0;
}