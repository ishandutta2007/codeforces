#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int pw(int x, int n)
{
        int res = 1;
        while(n > 0){
                if(n & 1) res = 1ll * res * x % mod;
                x = 1ll * x * x % mod;
                n /= 2;
        }
        return res;
}

int add(int x, int y) {
        x += y;
        if(x >= mod) x -= mod;
        return x;
}

struct node
{
        int c;
        int L, R;
        int res;
};

int p[N];

node comb(node x, node y)
{
        node res;
        res.res = add(x.res * 1ll * p[y.c] % mod, y.res * 1ll * p[x.c] % mod);
        res.L = add(x.L, 1ll * y.L * p[x.c] % mod);
        res.R = add(y.R, 1ll * x.R * p[y.c] % mod);
        res.c = x.c + y.c;
        res.res = add(res.res, 1ll * x.L * y.R % mod);
        return res;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int my_rand()
{
        return rng();
        //return (rand() << 10) ^ (rand());
}

struct treap
{
        treap *l, *r;
        int x, y;
        node A;
        treap(int _x)
        {
                l = r = NULL;
                x = _x;
                y = my_rand();

                A.c = 1;
                A.L = A.R = x;
                A.res = 0;
        }
};

typedef treap* tree;

tree root = NULL;

void upd(tree x)
{
        x->A.c = 1;
        x->A.L = x->A.R = x->x;
        x->A.res = 0;
        if(x->l != NULL) x->A = comb(x->l->A, x->A);
        if(x->r != NULL) x->A = comb(x->A, x->r->A);
}

void split(tree v, tree &l, tree &r, int x)
{
        if(v == NULL) {
                l = r = NULL;
                return;
        } else if(v->x < x) {
                split(v->r, v->r, r, x);
                l = v; upd(l);
        } else {
                split(v->l, l, v->l, x);
                r = v; upd(r);
        }
}

tree merg(tree l, tree r)
{
        if(l == NULL) return r;
        if(r == NULL) return l;
        if(l->y > r->y) {
                l->r = merg(l->r, r);
                upd(l);
                return l;
        } else {
                r->l = merg(l, r->l);
                upd(r);
                return r;
        }
}

int n;
int a[N];
int b[N];

void fix(tree x)
{
        if(x->l && x->r){
                if(x->l->y > x->y && x->l->y >= x->r->y){
                        swap(x->y, x->l->y);
                        fix(x->l);
                } else if(x->r->y > x->y){
                        swap(x->y, x->r->y);
                        fix(x->r);
                }
        } else if(x->l && x->l->y > x->y){
                swap(x->y, x->l->y);
                fix(x->l);
        } else if(x->r && x->r->y > x->y){
                swap(x->y, x->r->y);
                fix(x->r);
        }
}

tree make(int l, int r)
{
        if(l > r) return NULL;
        if(l == r) return new treap(a[l]);
        int m = (l + r) / 2;
        tree res = new treap(a[m]);

        res->l = make(l, m - 1);
        res->r = make(m + 1, r);
        upd(res);
        int need = 0;
        if(res->l) need = res->l->y;
        if(res->r) need = max(need, res->r->y);
        fix(res);
        return res;
}

void cler(tree r)
{
        if(r == NULL) return;
        cler(r->l); cler(r->r);
        delete(r);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        p[0] = 1;
        for(int i = 1; i < N; i++) p[i] = add(p[i - 1], p[i - 1]);

        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
                scanf("%d", a + i);
                b[i] = a[i];
        }
        sort(a + 1, a + n + 1);
        root = make(1, n);

        int inv = pw(p[n], mod - 2);
        printf("%d\n", root->A.res * 1ll * inv % mod);

        int q;
        tree A, B, C;
        scanf("%d", &q);
        for(int i = 1; i <= q; i++){
                int x, y;
                scanf("%d%d", &x, &y);
                split(root, A, B, b[x]);
                split(B, B, C, b[x] + 1);
                B = merg(B->l, B->r);
                root = merg(merg(A, B), C);

                b[x] = y;
                split(root, A, B, b[x]);
                root = merg(merg(A, new treap(b[x])), B);

                printf("%d\n", root->A.res * 1ll * inv % mod);

        }
}