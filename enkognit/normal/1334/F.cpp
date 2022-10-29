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

const ll MOD = 998244353;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, T, Q, a[1000001], b[1000001], p[1000001];
vector<ll> v;
ll tt[1000001];

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

struct segment_tree
{
    ll d[10000001], sz;
    bool leaf[10000001];

    void build(int h,int l,int r)
    {
        if (l==r)
        {
            leaf[h]=1;
            d[h]=1e18;
            return;
        }
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=0;
    }

    void build(int h)
    {
        sz=h;
        build(1,0,h);
    }

    void push(int h)
    {
        if (d[h] && !leaf[h])
        {
            d[h*2]+=d[h];
            d[h*2+1]+=d[h];
            d[h]=0;
        }
    }

    void update(int h,int l,int r,int x,int y,ll k)
    {
        push(h);
        if (x>y) return;
        if (l==x && y==r)
        {
            d[h]+=k;
            return;
        }
        int w=(l+r)/2;
        update(h*2,l,w,x,min(y,w),k);
        update(h*2+1,w+1,r,max(x,w+1),y,k);
    }

    void update(int x,int y,ll k)
    {
        update(1,0,sz,x,y,k);
    }

    ll get(int h,int l,int r,int x)
    {
        push(h);
        if (l==r) return d[h];
        int w=(l+r)/2;
        if (x<=w) return get(h*2,l,w,x); else return get(h*2+1,w+1,r,x);
    }

    ll get(int x)
    {
        return get(1,0,sz,x);
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
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        tt[b[i]]=i;
    }
    ll k=0;
    g.build(m);
    g.update(0,0,-1e18);
    for (int i = 1; i <= n; i++)
    {
        if (p[i]<0)
        {
            g.update(0,k,p[i]);
        }else
        {
            ll l=0, r=k;
            while (l<r)
            {
                int w=(l+r+1)/2;
                if (b[w]<a[i]) l=w; else r=w-1;
            }
            g.update(0,l,p[i]);
        }
        if (tt[a[i]] && k+1>=tt[a[i]])
        {
            k=max(k,tt[a[i]]);
            ll x=g.get(tt[a[i]]-1)-p[i], y=g.get(tt[a[i]]);
            //cout << i << " : " << x << " " << y << "\n";
            if (x<y) g.update(tt[a[i]],tt[a[i]],x-y);
        }
    }
    if (k<m) cout << "NO\n"; else
    {
        cout << "YES\n";
        cout << g.get(m) << "\n";
    }
    return 0;
}
/*

ghlaz
azjgh

*/