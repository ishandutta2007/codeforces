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
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, T, kl1, kl2, f;

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

bool operator < (pii x,pii y)
{
    return (x.fi<y.fi || x.fi==y.fi && x.se<y.se);
}

bool operator <= (pii x,pii y)
{
    return (x.fi<y.fi || x.fi==y.fi && x.se<=y.se);
}

struct node
{
    node *l, *r;
    pii x;
    int y;
    ll sm;
    int kl, cnt, kol;
    node():x(mp(0, 0)),y(rnd()%MOD),l(nullptr),r(nullptr),sm(0),kl(0),kol(0),cnt(0){};
    node(pii x):x(x),y(rnd()%MOD),l(nullptr),r(nullptr),sm(x.fi),kl(x.se),kol(1),cnt(1){};
};

void upd(node *h)
{
    if (!h) return;
    h->sm=(h->l?h->l->sm:0)+h->x.fi+(h->r?h->r->sm:0);
    h->kl=(h->l?h->l->kl:0)+h->x.se+(h->r?h->r->kl:0);
    h->kol=(h->l?h->l->kol:0)+1+(h->r?h->r->kol:0);
    h->cnt=(h->l?h->l->kol:0)+1;
}

node* merge(node *l,node *r)
{
    if (!l) return r;
    if (!r) return l;
    if (l->y>r->y)
    {
        l->r=merge(l->r,r);
        upd(l);
        return l;
    }else
    {
        r->l=merge(l,r->l);
        upd(r);
        return r;
    }
}

pair<node*,node*> split(node *h,pii x)
{
    if (!h) return mp(nullptr,nullptr);
    if (h->x<=x)
    {
        auto tt=split(h->r,x);
        h->r=tt.fi;
        upd(h);
        return mp(h, tt.se);
    }else
    {
        auto tt=split(h->l,x);
        h->l=tt.se;
        upd(h);
        return mp(tt.fi, h);
    }
}

pair<node*, node*> split_2(node* h,int x)
{
    if (!h) return mp(nullptr,nullptr);
    if (h->cnt<=x)
    {
        auto tt=split_2(h->r,x-h->cnt);
        h->r=tt.fi;
        upd(h);
        return mp(h, tt.se);
    }else
    {
        auto tt=split_2(h->l,x);
        h->l=tt.se;
        upd(h);
        return mp(tt.fi, h);
    }
}

node* root;

void solve()
{
    ll q;
    cin >> q;
    ll kl0=0, kl1=0, sum=0;
    multiset<int> s1;
    while (q--)
    {
        ll t, d;
        cin >> t >> d;
        sum+=d;
        if (t==0)
        {
            if (d>0)
            {
                kl0++;
                auto tt=split(root, mp(d, 0));
                root=merge(merge(tt.fi, new node(mp(d, 0))), tt.se);
            }else
            {
                kl0--;
                d=-d;
                auto tt=split(root,mp(d, 0));
                auto ww=split(tt.fi,mp(d-1, 1));
                root=merge(merge(ww.fi, merge(ww.se->l,ww.se->r)), tt.se);
            }
        }else
        {
            if (d>0)
            {
                kl1++;
                s1.insert(d);
                auto tt=split(root, mp(d, 1));
                root=merge(merge(tt.fi, new node(mp(d, 1))), tt.se);
            }else
            {
                kl1--;
                d=-d;
                s1.erase(s1.find(d));
                auto tt=split(root,mp(d, 1));
                auto ww=split(tt.fi,mp(d, 0));
                root=merge(merge(ww.fi, merge(ww.se->l,ww.se->r)), tt.se);
            }
        }
        if (kl0==0)
        {
            if (kl1==0)
            {
                cout << "0\n";
            }else
            {
                cout << sum*2-(*s1.begin()) << "\n";
            }
        }else
        if (kl1==0)
        {
            cout << sum << "\n";
        }else
        {
            auto u=split_2(root, kl0);
            if (u.se->kl==kl1)
            {
                root=merge(u.fi,u.se);
                auto o=split_2(root, kl0-1);
                cout << o.se->sm+sum-(*s1.begin()) << "\n";
                root=merge(o.fi,o.se);
            }else
            {
                cout << sum+u.se->sm << "\n";
                root=merge(u.fi, u.se);
            }
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
01000000
10100000
31100000
00020000
00000000
00000000
00000000
00000000

01100000
10100000
01100000
00100000
00100000
00100000
13112101
00011111
*/