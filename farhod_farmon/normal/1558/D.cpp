#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int Q = 400200;
const int mod = 998244353;

int pw(int x, int n)
{
        int res = 1;
        for(; n > 0; n >>= 1){
                if(n & 1){
                        res = 1ll * res * x % mod;
                }
                x = 1ll * x * x % mod;
        }
        return res;
}

int fac[Q], inv[Q];

void make()
{
        fac[0] = 1;
        for(int i = 1; i < Q; i++) fac[i] = fac[i - 1] * 1ll * i % mod;
        inv[Q - 1] = pw(fac[Q - 1], mod - 2);
        for(int i = Q - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}

int C(int n, int k)
{
        if(k < 0 || k > n) return 0;
        return 1ll * fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void add(int &x, int y)
{
        x += y;
        if(x >= mod) x -= mod;
}

void sub(int &x, int y)
{
        x -= y;
        if(x < 0) x += mod;
}
struct treap
{
        treap *l, *r;
        int x, y, delta;
        treap(int _x)
        {
                l = r = NULL;
                x = _x;
                y = rng();
                delta = 0;
        }
};
typedef treap* tree;

tree root;

void push(tree v)
{
        if(v == NULL || v->delta == 0)
        {
                return;
        }
        if(v->l != NULL)
        {
                v->l->x += v->delta;
                v->l->delta += v->delta;
        }
        if(v->r != NULL)
        {
                v->r->x += v->delta;
                v->r->delta += v->delta;
        }
        v->delta = 0;
}

void split(tree v, tree &l, tree &r, int x)
{
        if(v == NULL)
        {
                l = r = NULL;
                return;
        }
        push(v);
        if(v->x <= x)
        {
                split(v->r, v->r, r, x);
                l = v;
        }
        else
        {
                split(v->l, l, v->l, x);
                r = v;
        }
}

tree merg(tree l, tree r)
{
        if(l == NULL || r == NULL)
        {
                return l == NULL ? r : l;
        }
        push(l);
        push(r);
        if(l->y > r->y)
        {
                l->r = merg(l->r, r);
                return l;
        }
        else
        {
                r->l = merg(l, r->l);
                return r;
        }
}

void prnt(tree v)
{
        if(v == NULL)
        {
                return;
        }
        prnt(v->l);
        cout << v->x << " ";
        prnt(v->r);
}

int n, m;
int X[N];
int id[N];
int b[N];
int t[N];

void solve()
{
        root = NULL;

        cin >> n >> m;
        int res = 2 * n - 1 - m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                y -= 1;
                tree a, b, c;
                split(root, a, c, y);
                split(a, a, b, y - 1);
                if(c != NULL){
                        c->delta += 1;
                        c->x += 1;
                }
                if(b != NULL){
                        res += 1;
                }
                b = new treap(y + 1);
                root = merg(a, merg(b, c));
                //prnt(root);
                //cout << "\n";
        }

        cout << C(res, n) << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        make();

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}