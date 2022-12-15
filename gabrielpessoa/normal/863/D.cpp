#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+5;

typedef struct item * pitem;

mt19937_64 llrand(random_device{}());

struct item {
    int prior, value, cnt;
    bool rev;
    pitem l, r;
    item(int v) {
        value = v;
        cnt = 1;
        prior = llrand();
        rev = 0;
        l = 0;
        r = 0;
    }
};

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
    if(it) it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push(pitem it) {
    if(it && it->rev) {
        it->rev = false;
        swap(it->l, it->r);
        if(it->l) it->l->rev ^= 1;
        if(it->r) it->r->rev ^= 1;
    }
}

void merge(pitem &t, pitem l, pitem r) {
    push(l); push(r);
    if(!l || !r) t = l ? l : r;
    else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    upd_cnt(t);
}

void split(pitem t, pitem &l, pitem &r, int key, int add = 0) {
    if(!t) return void( l = r = 0);
    push(t);
    int cur_key = add + cnt(t->l);
    if(key <= cur_key) split(t->l, l, t->l, key, add), r = t;
    else split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
    upd_cnt(t);
}

void reverse(pitem t, int l, int r) {
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r-l+1);
    t2->rev ^= 1;
    merge(t, t1, t2);
    merge(t, t, t3);
}

void shift(pitem t, int l, int r, int k = 1) {
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r-l+1);
    pitem t4, t5;
    split(t2, t4, t5, r-l+1-k);
    merge(t2, t5, t4);
    merge(t, t1, t2);
    merge(t, t, t3);
}

int getValue(pitem t, int v) {
    pitem t1, t2, t3;
    split(t, t1, t2, v);
    split(t2, t2, t3, 1);
    int ans = t2->value;
    merge(t, t1, t2);
    merge(t, t, t3);
    return ans;
}

int t[ms], l[ms], r[ms];
int a[ms], b[ms];

main() {
    cin.tie(0); ios::sync_with_stdio(0);
    srand (time(NULL));
    int n, q, m;
    cin >> n >> q >> m;
    pitem tree = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        merge(tree, tree, new item(a[i]));
    }
    for(int i = 0; i < q; i++) {
        cin >> t[i] >> l[i] >> r[i];
        l[i]--; r[i]--;
        if(t[i] == 1) shift(tree, l[i], r[i]);
        else reverse(tree, l[i], r[i]);
    }
    while(m--) {
        int b;
        cin >> b;
        b--;
        cout << getValue(tree, b) << ' ';
    }
    cout << endl;
}