#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
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

const ll MOD = 1e9+7;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, TT, T, P, SZ, mx=0, ans, kl, a[1000001];
vector<ll> v;
bool tt[1000001];

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

struct node
{
    node *l, *r;
    ll x, y, kl, sum, mx;
    node(ll x,ll y):x(x),y(y),kl(1),sum(x),mx(x),l(nullptr),r(nullptr){};
};

struct DD
{
    node *root;

    pair<pll,ll> get(node* h)
    {
        return (h!=nullptr?mp(mp(h->sum,h->kl),h->mx):mp(mp(0ll,0ll),0ll));
    }

    void upd(node* h)
    {
        pair<pll,ll> o1=get(h->l), o2=get(h->r);
        h->sum=h->x+o1.fi.fi+o2.fi.fi;
        h->kl=1+o1.fi.se+o2.fi.se;
        h->mx=max(h->x,max(o1.se,o2.se));
    }

    node* merg(node* L, node* R)
    {
        if (L == nullptr) return R;
        if (R == nullptr) return L;
        if (L->y > R->y)
        {
            L->r = merg(L->r, R);
            upd(L);
            return L;
        }
        else
        {
            R->l = merg(L, R->l);
            upd(R);
            return R;
        }
    }

    pair<node*, node*> split(node* h, ll x)
    {
        if (h == nullptr) return mp(nullptr, nullptr);
        if (h->x > x)
        {
            //cout << "l\n";
            pair<node*, node*> q = split(h->l, x);
            h->l = q.second;
            upd(h);
            return mp(q.first, h);
        }
        else
        {
            //cout << "r\n";
            pair<node*, node*> q = split(h->r, x);
            h->r = q.fi;
            upd(h);
            return mp(h, q.se);
        }
    }

    void insrt(ll x)
    {
        ll o=rnd()%MOD;
        node* q = new node(x, o);
        auto w = split(root, x);
        root = merg(w.fi, merg(q, w.se));
        upd(root);
    }

    void erase(ll x)
    {
        auto q = split(root, x);
        auto w = split(q.fi, x - 1);
        w.se = merg(w.se->l, w.se->r);
        q.fi = merg(w.fi, w.se);
        root = merg(q.fi, q.se);
    }

    pair<pll,ll> get_sum(ll x)
    {
        auto q=split(root,x);
        pair<pll,ll> p=get(q.fi);
        root=merg(q.fi,q.se);
        return p;
    }
};

DD g;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //for (ll i = 1; i <= 60; i++) pr[i]=pr[i-1]+(1ll<<(i-1));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g.insrt(a[i]);
    }
    cout.precision(5);
    for (int i = 0; i < m; i++)
    {
        ll t;
        cin >> t;
        if (t==1)
        {
            ll x, y;
            cin >> x >> y;
            g.erase(a[x]);
            a[x]=y;
            g.insrt(a[x]);
        }else
        {
            ll x;
            cin >> x;
            ll l=0, r=1e9;
            while (l<r)
            {
                ll w=(l+r+1)/2;
                auto p=g.get_sum(w);
                if ((ld)(p.fi.fi+x)/(ld)p.fi.se<p.se) r=w-1; else l=w;
            }
            auto p=g.get_sum(l);
            cout <<fixed<< (ld)(p.fi.fi+x)/(ld)p.fi.se << "\n";
        }
    }
    return 0;
}
/*
2
3 2
10
01
01
DL
RU
UU
2 4
1111
0101
RDRD
UUUU
*/