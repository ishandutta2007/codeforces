#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-12;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, kol=0, q, sz=0, a[2000001];

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
    ll mn, mx, sm;
    ll k;
    node():mn(0),mx(0),sm(0),k(0){};
    node(int u):mn(u),mx(u),k(-1),sm(u){};
};

struct segment_tree
{
    node d[1000001];

    segment_tree(){};

    void push(int &h,int &l,int &r)
    {
        if (d[h].k!=-1)
        {
            d[h*2].k=d[h].k;
            d[h*2+1].k=d[h].k;
            d[h*2].mn=d[h].k;
            d[h*2+1].mn=d[h].k;
            d[h*2].mx=d[h].k;
            d[h*2+1].mx=d[h].k;
            int w=(l+r)/2;
            d[h*2].sm=(w-l+1)*d[h].k;
            d[h*2+1].sm=(r-w)*d[h].k;
            d[h].k=-1;
        }
    }

    void upd(int &h)
    {
        d[h].sm=d[h*2].sm+d[h*2+1].sm;
        d[h].mn=min(d[h*2].mn,d[h*2+1].mn);
        d[h].mx=max(d[h*2].mx,d[h*2+1].mx);
    }

    void build(int h,int l,int r)
    {
        if (l==r)
        {
            d[h]=node(a[l]);
            return;
        }
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        upd(h);
        d[h].k=-1;
    }

    void update_1(int h,int l,int r,int x,int y,int k)
    {
        //cout << l << " " << r << " " << x << " " << y << " " << k << " " << d[h].mx << " " << d[h].mn << "\n";
        if (x>y || d[h].mx<k) return;
        push(h,l,r);
        if (l==x && y==r && d[h].mn==d[h].mx)
        {
            d[h].sm=(r-l+1)*(d[h].mx%k);
            d[h].k=d[h].mx%k;
            d[h].mn=(d[h].mx%k);
            d[h].mx=(d[h].mx%k);
            return;
        }
        int w=(l+r)/2;
        update_1(h*2,l,w,x,min(y,w),k);
        update_1(h*2+1,w+1,r,max(w+1,x),y,k);
        upd(h);
    }

    void update_2(int h,int l,int r,int x,int k)
    {
        push(h,l,r);
        if (l==r)
        {
            d[h].sm=k;
            d[h].mn=k;
            d[h].mx=k;
            return;
        }
        int w=(l+r)/2;
        if (x<=w) update_2(h*2,l,w,x,k); else update_2(h*2+1,w+1,r,x,k);
        upd(h);
    }

    ll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return 0;
        if (l==x && y==r) return d[h].sm;
        push(h,l,r);
        int w=(l+r)/2;
        return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
    }
};

segment_tree g;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    g.build(1,1,n);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t==1)
        {
            ll l, r;
            cin >> l >> r;
            cout << g.get(1,1,n,l,r) << "\n";
        }else
        if (t==2)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            g.update_1(1,1,n,l,r,x);
        }else
        if (t==3)
        {
            ll k, x;
            cin >> k >> x;
            g.update_2(1,1,n,k,x);
        }
    }
    return 0;
}

/*
8 2
2 2 2 2 2 2 2 2
1 2

*/