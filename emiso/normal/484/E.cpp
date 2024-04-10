#include <bits/stdc++.h>
#define MN 100100

using namespace std;

struct no {
    int best, left, right;
    no(): best(0), left(0), right(0) {}
    no(int b, int l, int r) : best(b), left(l), right(r) {}
} tree[32 * MN];

vector<no> logs;
int root[4*MN], L[32 * MN], R[32 * MN], count_, Size;

no merge(no l, no r, int x, int y) {
    no ret(0, 0, 0);
    ret.best = max(l.best, r.best);
    ret.best = max(ret.best, l.right + r.left);

    int m = (x + y) / 2;

    ret.left = l.left;
    if(l.left == m - x + 1) ret.left = l.left + r.left;

    ret.right = r.right;
    if(r.right == y - m) ret.right = r.right + l.right;

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
        tree[idx] = no(1, 1, 1);
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
    if(fn < l || r < st) return no(0, 0, 0);
    if(st <= l && r <= fn) return tree[id];

    int m = (l + r)/2;

    no l_ = query(L[id], l, m, st, fn);
    no r_ = query(R[id],m+1,r, st, fn);

    no ret = merge(l_, r_, l, r);
    return ret;
}

void novaArvore(int x) {
    Size++;
    root[Size] = insert(root[Size-1], 0, MN, x);
}

vector<pair<int, int> > tabuas;
bool cmp(pair<int,int> a, pair<int, int> b) {
    return a.first > b.first;
}

int n, h, l_, r_, w, m;

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d",&h);
        tabuas.push_back({h, i});
    } sort(tabuas.begin(), tabuas.end(), cmp);

    count_ = 1;
    build(0, 1, MN);
    root[0] = 0;

    for(int i=1;i<=n;i++) {
        root[i] = insert(root[i-1], 1, MN, tabuas[i-1].second);
    }

    scanf("%d", &m);
    for(int i=0;i<m;i++) {
        scanf("%d %d %d", &l_, &r_, &w);

        int lb = 1, rb = n;
        while(lb < rb) {
            int md = (lb + rb)/2;
            no p = query(root[md], 1, MN, l_, r_);

            if(query(root[md], 1, MN, l_, r_).best >= w) rb = md;
            else lb = md + 1;
        }
        printf("%d\n", tabuas[lb-1].first);
    }

    return 0;
}