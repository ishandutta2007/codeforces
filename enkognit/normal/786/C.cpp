#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, lst[300001], a[300001], dp[300001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

struct dsu
{
    ll d[200001];

    void make_set(int h)
    {
        d[h]=h;
    }

    ll find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        if (x<y) swap(x,y);
        d[x]=y;
    }
};

struct node
{
    node *l, *r;
    ll kl=0, f=0;
    node():l(nullptr),r(nullptr),kl(0),f(0){};
};

struct persistent_segment_tree
{
    vector<pair<node*,ll> > root;

    void build_new(int n)
    {
        root.pb(mp(new node(),n+1));
        build(root.back().fi,1,n);
    }

    void build(node* h,int l,int r)
    {
        if (l==r) return;
        int w=(l+r)/2;
        h->l=new node();
        h->r=new node();
        build(h->l,l,w);
        build(h->r,w+1,r);
    }

    node* update(node *h,int l,int r,int x,int k)
    {
        if (l==r)
        {
            node *u=new node();
            u->kl=k;
            u->f=k;
            return u;
        }
        int w=(l+r)/2;
        node *y=new node();
        if (x<=w)
        {
            y->r=h->r;
            y->l=update(h->l,l,w,x,k);
        }else
        {
            y->l=h->l;
            y->r=update(h->r,w+1,r,x,k);
        }
        y->kl=y->l->kl+y->r->kl;
        y->f=y->l->f;
        return y;
    }

    ll get(node *h,int l,int r,int o,int k=0)
    {
        if (l==r) return l;
        int w=(l+r)/2;
        //cout << " " << l << " " << r << " " << k << " " << h->l->kl << " " << h->r->f << " " << o << " " << h->r->kl <<  "\n";
        if (k+h->l->kl+h->r->f>o) return get(h->l,l,w,o,k); else return get(h->r,w+1,r,o,k+h->l->kl);
    }

    ll get_element(node *h,int l,int r,int x)
    {
        if (l==r) return h->kl;
        int w=(l+r)/2;
        if (x<=w) return get_element(h->l,l,w,x); else return get_element(h->r,w+1,r,x);
    }
};

persistent_segment_tree g;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    g.build_new(n);
    //cout << "-----\n";
    for (int i = n; i > 0; i--)
    {
        node *p=g.root.back().fi;
        if (lst[a[i]]!=0)
            p=g.update(g.root.back().fi, 1, n, lst[a[i]], 0);
        //cout << lst[a[i]] << "\n";
        g.root.pb(mp(g.update(p,1,n,i,1), i));
        //cout << i << ": ";for (int j = 1; j <= n; j++) cout << g.get_element(g.root.back().fi,1,n,j) << " ";
        //cout << "\n";
        lst[a[i]]=i;
    }
    //cout << "-----\n";
    vector<ll> v;
    for (int i = 1; i <= n; i++)
    {
        //cout << i << "\n";
        ll j=0, k=0;
        while (j<n)
        {
            //cout << " " << j << " " << k << " " << g.root[n-j].se << "\n";
            j=g.get(g.root[n-j].fi,1,n,i);
            k++;
        }
        v.pb(k);
    }
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}

/*
3
5
abcab
aabab
3
aaa
aab
2
de
cd
*/