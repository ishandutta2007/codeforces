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

ll n, m, k, K=310, T, kl1, kl2, f, a[100005], b[100005];

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

struct otrezok
{
    ll l, r, sm;
    bool good;

    void build()
    {
        for (int i = l; i <= r; i++)
        {
            if (a[i]<l) b[i]=i; else b[i]=b[a[i]];
        }
    }

    void make_all()
    {
        good=1;
        for (int i = l; i <= r; i++)
        {
            if (max(a[i]-sm,1ll)<l) b[i]=i; else
                good=0, b[i]=b[max(a[i]-sm,1ll)];
        }
    }

    void update(int L,int R,int x)
    {
        if (L==l && R==r && good)
        {
            sm+=x;
            return;
        }
        for (int i = L; i <= R; i++)
        {
            a[i]=max(a[i]-x, 1ll);
        }
        make_all();
    }

    otrezok():l(0),r(0),sm(0),good(0){};
};


otrezok c[400];

void update(int l,int r,int x)
{
    if ((l-1)/K==(r-1)/K)
    {
        c[(l-1)/K+1].update(l,r,x);
        return;
    }
    c[(l-1)/K+1].update(l,c[(l-1)/K+1].r,x);
    c[(r-1)/K+1].update(c[(r-1)/K+1].l,r,x);
    for (int i = (l-1)/K+2; i < (r-1)/K+1; i++)
        c[i].update(c[i].l,c[i].r,x);
}

ll get(int x,int y)
{
    while ((x-1)/K!=(y-1)/K || ((x-1)/K==(y-1)/K && b[x]!=b[y]))
    {
        //cout << x << " " << b[x] << " " << a[x] << " " << c[(x-1)/K+1].sm << " " << y << "\n";
        //assert(x>0 && y>0);
        if (x<y) swap(x, y);
        x=b[x];
        x=(int)max(a[x]-c[(x-1)/K+1].sm, 1ll);
    }
    while (x!=y)
    {
        //assert(x>0 && y>0);
        if (x<y) swap(x, y);
        x=max(a[x]-c[(x-1)/K+1].sm, 1ll);
    }
    return x;
}

void solve()
{
    ll q;
    cin >> n >> q;
    a[1]=1;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1, j = 1; i <= n; i+=K, j++)
    {
        c[j].l=(j-1)*K+1;
        c[j].r=min(j*K, n);
        c[j].sm=0;
        c[j].good=0;
        c[j].build();
    }

    while (q--)
    {
        ll t;
        cin >> t;
        if (t==1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            update(l,r,x);
        }else
        {
            ll l, r;
            cin >> l >> r;
            cout << get(l, r) << "\n";
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