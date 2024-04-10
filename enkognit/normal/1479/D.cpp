#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=10228228228228697ll;

ll n, m, k, q, T, a[300005], b[300005], bn[300005][20], in[300005], out[300005];
vector<ll> c[300005];

struct node
{
    node *l, *r;
    ll x;
    node():l(nullptr),r(nullptr),x(0){};
};

node* root[300005];

void build(node *h,int l,int r)
{
    //cout << l << " " << r << "\n";
    if (l==r) return;
    int w=(l+r)/2;
    h->l=new node();
    h->r=new node();
    build(h->l,l,w);
    build(h->r,w+1,r);
}

node* update(node *h,int l,int r,int x)
{
    if (l==r)
    {
        auto u=new node();
        u->x=h->x^b[x];
        return u;
    }
    int w=(l+r)/2;
    auto u=new node();
    if (x<=w)
    {
        u->r=h->r;
        u->l=update(h->l,l,w,x);
    }else
    {
        u->l=h->l;
        u->r=update(h->r,w+1,r,x);
    }
    u->x=u->l->x^u->r->x;
    return u;
}

void dfs(int h,int p=0)
{
    bn[h][0]=p;
    in[h]=++T;
    for (int i = 1; i < 20; i++)
        bn[h][i]=bn[bn[h][i-1]][i-1];
    root[h]=update(root[p],1,n,a[h]);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p) dfs(c[h][i], h);
    out[h]=++T;
}

ll get(node *a,node *b,node *c,node *d,int l,int r)
{
    if (!(a->x^b->x^c->x^d->x))
    {
        /*cout << "  " << l << " " << r << "  -1\n";
        cout << "   " << a->x << "\n";
        cout << "   " << b->x << "\n";
        cout << "   " << c->x << "\n";
        cout << "   " << d->x << "\n";*/
        return -1;
    }
    if (l==r) return l;
    int w=(l+r)/2;
    if (a->l->x^b->l->x^c->l->x^d->l->x)
    {
        ll o=get(a->l,b->l,c->l,d->l,l,w);
        if (o==-1) o=get(a->r,b->r,c->r,d->r,w+1,r);
        //cout << "  " << l << " " << r << " " << o << "\n";
        return o;
    }else
    {
        ll o=get(a->r,b->r,c->r,d->r,w+1,r);
        //cout << "  " << l << " " << r << " " << o << "\n";
        return o;
    }
}

ll _get(node *a,node *b,node *c,node *d,int l,int r,int x,int y)
{
    if (l==x && y==r)
    {
        return get(a,b,c,d,l,r);
        //cout << " " << l << " " << r << " " << x << " " << y << " " << o << "\n";
    }
    int w=(l+r)/2;
    ll o;
    if (x>w) o=_get(a->r,b->r,c->r,d->r,w+1,r,x,y); else
    if (y<=w) o=_get(a->l,b->l,c->l,d->l,l,w,x,y); else
    {
        o=_get(a->l,b->l,c->l,d->l,l,w,x,w);
        if (o==-1) o=_get(a->r,b->r,c->r,d->r,w+1,r,w+1,y);
    }
    //cout << " " << l << " " << r << " " << x << " " << y << " " << o << "\n";
    return o;
}

bool is_ancestor(int x,int y)
{
    return in[x]<=in[y] && out[x]>=out[y];
}

ll lca(int x,int y)
{
    if (is_ancestor(x,y)) return x;
    if (is_ancestor(y,x)) return y;
    for (int i = 19; i > -1; i--) if (!is_ancestor(bn[x][i], y)) x=bn[x][i];
    return bn[x][0];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll k=0;
    for (int i = 1; i <= n; i++) b[i]=rnd();
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    out[0]=1e9;
    root[0]=new node();
    build(root[0],1,n);
    //cout << "---\n";
    dfs(1);
    while (q--)
    {
        ll x, y, l, r;
        cin >> x >> y >> l >> r;
        ll p1=lca(x,y), p2=bn[p1][0];
        //cout << "---- " << x << " " << y << " " << p1 << " " << p2 << "\n";
        cout << _get(root[x],root[y],root[p1],root[p2],1,n,l,r) << "\n";
    }
    return 0;
}
/*

10
4 1 7 6 5 5 4 2 3 1
*/