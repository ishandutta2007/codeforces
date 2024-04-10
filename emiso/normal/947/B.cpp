#include <bits/stdc++.h>

#define MN 100100

using namespace std;
typedef long long ll;

ll n, ans, V[MN], T[MN];

inline ll my_rand() {
    return ((rand()<<16) ^ rand()) & 0x7fffffff;
}

struct node{
    ll key, sum;
    ll prior, size, lazy;
    node * l, * r;

    node(int key) :
        key(key),
        sum(key),
        prior(my_rand()),
        size(1),
        l(NULL),
        r(NULL),
        lazy(0) {}
};

typedef node* pnode;

ll get_size(pnode t) {
    return (t) ? t->size : 0;
}

void update_size(pnode t) {
    if(t) t->size = get_size(t->l) + 1 + get_size(t->r);
}

void push(pnode t) {
    if(t && t->lazy) {
        update_size(t);
        t->sum -= (t->lazy) * get_size(t);
        t->key -= t->lazy;
        if(t->l) t->l->lazy += t->lazy;
        if(t->r) t->r->lazy += t->lazy;
        t->lazy = 0;
    }
}

ll get_sum(pnode t) {
    if(t) {
        push(t);
        return t->sum;
    }
    else return 0;
}

ll update_sum(pnode t) {
    if(t) {
        push(t);
        t->sum = get_sum(t->l) + t->key + get_sum(t->r);
    }
    else return 0;
}

///Elements equal to key ==> LEFT TREE
void split(pnode t, pnode &l, pnode &r, ll key) {
    if(!t) {
      l = r = NULL;
      return;
    }
    push(t);

    if(t->key <= key) {
        split(t->r, t->r, r, key);
        l = t;
    }

    else {
        split(t->l, l, t->l, key);
        r = t;
    }

    update_size(t);
    update_sum(t);
}

///REMEMBER: (L->key) <= (R->key), for every(L, R) in (l, r)
void merge(pnode &t, pnode l, pnode r) {
    push(l);
    push(r);

    if(!l || !r) t = l?l:r;

    else if(l->prior > r->prior) {
        merge(l->r, l->r, r);
        t = l;
    }

    else {
        merge(r->l, l, r->l);
        t = r;
    }

    push(t);
    update_sum(t);
    update_size(t);
}

void add(pnode &t, ll key) {
    push(t);
    pnode toAdd = new node(key);
    pnode L, R;

    split(t, L, R, key);
    merge(L, L, toAdd);
    merge(t, L, R);
}

///Treap toString
void print(pnode t) {
    if(!t) return;

    print(t->l);
    printf("%lld ", t->key);
    print(t->r);
}

vector<ll> res;

int main() {
    scanf("%lld", &n);
    pnode root = NULL;

    for(int i=0; i<n; i++) {
        scanf("%lld", &V[i]);
    }

    for(int i=0; i<n; i++) {
        scanf("%lld", &T[i]);
    }

    //adiciona vi, corta <= ti, salva resultado, reduz em ti
    for(int i=0; i<n; i++) {
        add(root, V[i]);

        pnode L = NULL;
        split(root, L, root, T[i]);

        res.push_back(get_sum(L) + T[i] * get_size(root));

        if(root) root->lazy += T[i];
        push(root);
    }

    for(ll x : res) {
      printf("%lld ", x);
    }
    return 0;
}