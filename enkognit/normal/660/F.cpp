#include <bits/stdc++.h>
#include <random>
#include <ctime>
#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 998244353;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, q, ans, mx, o, a[1000001];

ll binpow(ll h, ll r, ll md=MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    //cout << l << "\n";
    return l;
}

struct node
{
    node *l, *r;
    pll f;
    node():f(mp(0, 0)),l(nullptr),r(nullptr){};
};

ll yy(ll h,pll x)
{
    return x.fi*h+x.se;
}

struct Li_Chao_Tree
{
    node *root;

    void build(node *h,int l,int r)
    {
        if (r-l==1) return;
        int w=(l+r)/2;
        h->l=new node();
        h->r=new node();
        build(h->l,l,w);
        build(h->r,w,r);
    }

    void update(node *h,int l,int r,pll x)
    {
        int w=(l+r)/2;
        bool tt=(yy(l, x)>yy(l, h->f));
        bool t=(yy(w, x)>yy(w, h->f));
        if (t) swap(h->f, x), tt=!tt;
        if (r-l==1) return;
        if (tt) update(h->l,l,w,x); else update(h->r,w,r,x);
    }

    ll get(node *h,int l,int r,int x)
    {
        if (r-l==1) return yy(x, h->f);
        int w=(l+r)/2;
        if (x<w) return max(get(h->l,l,w,x), yy(x, h->f)); else return max(get(h->r,w,r,x), yy(x, h->f));
    }
};

Li_Chao_Tree g;

void solve()
{
    cin >> n;
    g.root=new node();
    g.build(g.root, 0, n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll sm=0, pr=0, ans=0;
    for (int i = n; i > 0; i--)
    {
        pr+=a[i];
        sm+=pr;
        //cout << sm << " " << g.get(g.root, 0, n+1, n-i) << "\n";
        ans=max(ans, sm+g.get(g.root, 0, n+1, n-i));
        g.update(g.root, 0, n+1, mp(-pr, -sm+pr*(n-i)));
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("document.in","r",stdin);
    //freopen("document.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    /*fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 300000; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i],MOD-2);
    }*/
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
1

3

0 1 1

1 3

3 2


*/