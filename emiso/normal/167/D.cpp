#include <bits/stdc++.h>
#define MOD 1000000009

struct node{
    int key;
    int prior, size, metxe, used;
    node * l, * r;

    node(int key, int priori) :
        key(key),
        prior(priori),
        size(1),
        metxe(0),
        used(0),
        l(NULL),
        r(NULL) {}
};

typedef node* pnode;

void print(pnode t) {
    if(!t) return;

    print(t->l);
    printf("%d ", t->key);
    print(t->r);
}

int get_size(pnode t) {
    return (t) ? t->size : 0;
}

void update_size(pnode t) {
    if(t) t->size = get_size(t->l) + 1 + get_size(t->r);
}

int get_metxe(pnode t) {
    return (t) ? t->metxe : 0;
}

void update_metxe(pnode t) {
    if(!t) return;

    int met = get_metxe(t->l) + get_metxe(t->r);

    if(t->l && t->l->used == 0) {
        t->used = 1;
        met++;
    }

    else if(t->r && t->r->used == 0) {
        t->used = 1;
        met++;
    }

    else {
        t->used = 0;
    }

    //print(t); puts("");
    //printf("Update: %d\n", met);
    t->metxe = met;
}

void split(pnode t, pnode &l, pnode &r, int key) {
    if(!t)
        l = r = NULL;

    else if(t->key <= key) {
        split(t->r, t->r, r, key);
        l = t;
    }

    else {
        split(t->l, l, t->l, key);
        r = t;
    }

    update_size(t);
    update_metxe(t);
}

void merge(pnode &t, pnode l, pnode r) {
    if(!l || !r) t = l?l:r;

    else if(l->prior > r->prior) {
        merge(l->r, l->r, r);
        t = l;
    }

    else {
        merge(r->l, l, r->l);
        t = r;
    }

    update_size(t);
    update_metxe(t);
}

void add(pnode &t, int key, int prio) {
    pnode toAdd = new node(key, prio);
    pnode L, R;

    split(t, L, R, key);
    merge(L, L, toAdd);
    merge(t, L, R);
}


long long x[100100], y[100100];

int main() {
    int n, k, a, b, c, d, m, l, r;
    pnode root = NULL;

    scanf("%d %d", &n, &k);
    for(int i=0; i<k; i++) {
        scanf("%d %d", &x[i], &y[i]);
        add(root, x[i], y[i]);
    }

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &m);
    for(int i=k; i<n; i++) {
        x[i] = (a * x[i-1] + b) % MOD;
        y[i] = (c * y[i-1] + d) % MOD;
        add(root, x[i], y[i]);
    }

    for(int i=0; i<m; i++) {
        scanf("%d %d", &l, &r);

        pnode L, M, R;
        split(root, L, M, l - 1);
        split(M, M, R, r);

        //print(M); puts("");
        printf("%d\n", get_metxe(M));

        merge(M, M, R);
        merge(root, L, M);
    }

    return 0;
}

/*
6 6
0 0
5 11
20 263098
65 292514823
200 76958738
605 622120197
3 5 23917 11
*/