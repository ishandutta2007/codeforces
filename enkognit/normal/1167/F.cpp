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

struct segment_tree
{
    ll d[5000001];
    ll tt[5000001];
    bool leaf[5000001];

    void push(int h,int l,int r)
    {
        if (!leaf[h] && tt[h])
        {
            tt[h*2]+=tt[h];
            tt[h*2+1]+=tt[h];
            int w=(l+r)/2;
            d[h*2]+=tt[h]*(w-l+1);
            d[h*2+1]+=tt[h]*(r-w);
            tt[h]=0;
        }
    }

    void build(int h,int l,int r)
    {
        if (l==r) {leaf[h]=1;d[h]=0;return;}
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=0;
    }

    void update(int h,int l,int r,int x,int y,int k)
    {
        push(h,l,r);
        if (x>y) return;
        if (l==x && y==r)
        {
            d[h]+=(r-l+1)*k;
            tt[h]+=k;
            return;
        }
        int w=(l+r)/2;
        update(h*2,l,w,x,min(y,w),k);
        update(h*2+1,w+1,r,max(x,w+1),y,k);
        d[h]=d[h*2]+d[h*2+1];
    }

    ll get(int h,int l,int r,int x,int y)
    {
        push(h,l,r);
        if (x>y) return 0;
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
    }
};

segment_tree pr, sf;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.pb(mp(a[i],i));
    }
    sort(all(v));
    sf.build(1,1,n);
    pr.build(1,1,n);
    ll ans=0;
    for (int it = 0; it < v.size(); it++)
    {
        ll i=v[it].se, u=ans;
        //cout << i << " :\n " << v[it].fi << " " << n-i+1 << "\n";
        ll p1=sf.get(1,1,n,1,i)-i*sf.get(1,1,n,i,i), p2=pr.get(1,1,n,i,n)-(n-i+1)*pr.get(1,1,n,i,i);
        //cout << " " << p1 << " " << p2 << "\n";
        p1%=MOD;
        p2%=MOD;
        ans+=(n-i+1)*i%MOD*v[it].fi%MOD;
        ans=(ans+v[it].fi*(p1*(n-i+1)%MOD+p2*(i)%MOD)%MOD)%MOD;
        //cout << " " << ans-u << "\n";
        pr.update(1,1,n,i,n,1);
        sf.update(1,1,n,1,i,1);
    }
    cout << ans << "\n";
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