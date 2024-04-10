#include <bits/stdc++.h>

using namespace std;

inline int my_rand() {
    return ((rand()<<16) ^ rand()) & 0x7fffffff;
}

struct node{
    int key;
    int prior, size;
    bool rev;
    node * l, * r;

    node(int key) :
        key(key),
        prior(my_rand()),
        size(1),
        l(NULL),
        r(NULL),
        rev(false) {}
};

typedef node* pnode;

int get_size(pnode t) {
    return (t) ? t->size : 0;
}

void update_size(pnode t) {
    if(t) t->size = get_size(t->l) + 1 + get_size(t->r);
}

void push(pnode t) {
    if(t && t->rev) {
        t->rev = false;
        swap(t->l, t->r);
        if(t->l) t->l->rev ^= true;
        if(t->r) t->r->rev ^= true;
    }
}

void split(pnode t, pnode &l, pnode &r, int key, int add = 0) {
    if(!t) {
        l = r = NULL;
        return;
    }
    push(t);
    int cur_key = add + get_size(t->l);

    if(key >= cur_key)
        split(t->r,t->r,r,key,cur_key + 1), l = t;

    else
        split(t->l,l,t->l,key, add), r = t;

    update_size(t);
}

void merge(pnode &t, pnode l, pnode r) {
    push(l);
    push(r);

    if(!l || !r) t = l?l:r;
    else if(l->prior > r->prior)
        merge(l->r,l->r,r), t = l;

    else
        merge(r->l,l,r->l), t = r;

    update_size(t);
}

void reverse(pnode t, int l, int r) {
    push(t);

    pnode t1, t2, t3;
    split(t, t2, t3, r);
    split(t2, t1, t2, l-1);

    push(t2);
    t2->rev ^= true;

    merge(t, t1, t2);
    merge(t, t, t3);
}

void print(pnode t) {
    if(!t) return;
    push(t);

    print(t->l);
    printf("%d ",t->key);
    print(t->r);
}

int n, q, m, T, lq, rq, z;

int main() {
    scanf("%d %d %d", &n, &q, &m);
    pnode root = NULL;

    for(int i=0; i<n; i++) {
        scanf("%d", &z);
        merge(root, root, new node(z));
    }

    for(int i=0; i<q; i++) {
        scanf("%d %d %d", &T, &lq, &rq);
        lq--; rq--;

        if(T == 1) {
                pnode L, M, M2, R;
                L = M = M2 = R = NULL;

                split(root, L, R, rq);
                split(L, L, M2, rq - 1);
                split(L, L, M, lq - 1);

                merge(M, M2, M);
                merge(L, L, M);
                merge(root, L, R);
        }
        else {
            reverse(root, lq, rq);
        }

        //print(root); puts("");
    }

    for(int i=0; i<m; i++) {
        scanf("%d", &z); z--;

        pnode L, M, R;
        L = M = R = NULL;

        split(root, L, R, z);
        split(L, L, M, z - 1);

        print(M);

        merge(L, L, M);
        merge(root, L, R);
    } puts("");

    return 0;
}