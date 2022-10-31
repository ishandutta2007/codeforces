#include <stdio.h>
#include <stdlib.h>


inline int grand() {
    return ((rand()<<16) ^ rand()) & 0x7fffffff;
}

struct node {
    int key, prior, size;
    node * l, * r;
    node(int key) : key(key), prior(grand()), size(1), l(NULL), r(NULL){}
};

typedef node* pnode;

int sz (pnode t) {
    return (t)?t->size:0;
}

void upd_sz(pnode t) {
    if(t) t->size = 1 + sz(t->l) + sz(t->r);
}

void split(pnode t, pnode &l, pnode &r, int key) {
    if(!t)
        l = r = NULL;

    else if(t->key < key)
        split(t->r,t->r,r,key), l = t;

    else
        split(t->l,l,t->l,key), r = t;

    upd_sz(t);
}

void merge(pnode &t, pnode l, pnode r) {
    if(!l || !r) t = l?l:r;

    else if(l->prior > r->prior)
        merge(l->r,l->r,r), t = l;

    else
        merge(r->l,l,r->l), t = r;

    upd_sz(t);
}

void insert(pnode &t, pnode it) {
    if(!t) t = it;

    else if(t->prior > it->prior)
        insert(t->key >= it->key ? t->l : t->r, it);

    else
        split(t,it->l,it->r,it->key), t = it;

    upd_sz(t);
}

void erase(pnode &t, int key) {
    if(!t) return;

    if(t->key == key)
        merge(t,t->l,t->r);

    else
        erase(t->key >= key ? t->l : t->r, key);

    upd_sz(t);
}

void print(pnode t) {
    if(!t) return;

    print(t->l);
    printf("%d ",t->key);
    print(t->r);
}

int query(int k, int pot, pnode tree, int add = 0) {
    if(!tree) return -1;
    if(sz(tree) == 1 || pot < 0) return tree->key;

    int ans = -1;
    pnode l = NULL;
    pnode r = NULL;

    split(tree,l,r,(1LL<<pot) + add);

    if(!(k & (1LL<<pot))) {
        if(r) ans = query(k,pot-1,r, add + (1LL<<pot));
        else ans = query(k,pot-1,l, add);
    }
    else {
        if(l) ans = query(k,pot-1,l, add);
        else ans = query(k,pot-1,r, add + (1LL<<pot));
    }

    merge(tree,l,r);
    return ans;
}

int main() {

    int n,k,q;
    char t;
    pnode root = NULL;
    pnode ini = new node(0);
    insert(root,ini);

    scanf("%d",&q);
    while(q--) {
        scanf(" %c %d",&t,&k);
        if(t == '+') {
            pnode no = new node(k);
            insert(root,no);
        }

        else if(t == '-') {
            erase(root,k);
        }

        else if(t == '?') {
            printf("%d\n",k ^ query(k, 30, root));
        }
        else puts("error");
    }
    return 0;
}