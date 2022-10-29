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

const ll MOD = 1e9+7;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, a[300001], tt[300001], dp[300001];

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
    pll d[1000001];

    void build(int h,int l,int r)
    {
        if (l==r) {d[h]=mp(a[l],a[l]);return;}
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=mp(min(d[h*2].fi,d[h*2+1].fi),max(d[h*2].se,d[h*2+1].se));
    }

    void update(int h,int l,int r,int x,ll k)
    {
        if (l==r)
        {
            d[h]=mp(k,k);
            return;
        }
        int w=(l+r)/2;
        if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
        d[h]=mp(min(d[h*2].fi,d[h*2+1].fi),max(d[h*2].se,d[h*2+1].se));
    }

    pll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return mp(1e18,-1e18);
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        pll o1=get(h*2,l,w,x,min(y,w)), o2=get(h*2+1,w+1,r,max(x,w+1),y);
        return mp(min(o1.fi,o2.fi),max(o1.se,o2.se));
    }
};

segment_tree g, q;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    g.build(1,1,n);
    for (int i = 1; i <= n; i++) {dp[i]=1e18;q.update(1,0,n,i,1e18);}
    //cout << "----\n";
    for (int i = k; i <= n; i++)
    {
        ll l=0, r=max(i-k+1,0ll);
        while (l<r)
        {
            int w=(l+r)/2;
            pll o=g.get(1,1,n,w+1,i);
            //cout << l << " " << r << "\n";
            if (o.se-o.fi>m) l=w+1; else r=w;
        }
        if (l<i-k+1)
        {
            dp[i]=min(q.get(1,0,n,l,i-k).fi+1,dp[i]);
            //cout << l << " " << i-k << " " << q.get(1,0,n,l,i-k).fi << "\n";
            q.update(1,0,n,i,dp[i]);
        }
        //cout << i << " : " << dp[i] << "\n";
    }
    if (dp[n]>=1e18)cout << "-1\n"; else cout << dp[n] << "\n";
    return 0;
}