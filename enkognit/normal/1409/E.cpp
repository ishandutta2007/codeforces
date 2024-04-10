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

ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, T, a[200001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
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
    ll d[1000001];
    ll tt[1000001];
    bool leaf[1000001];

    void push(int h)
    {
        if (tt[h] && !leaf[h])
        {
            d[h*2]+=tt[h];
            d[h*2+1]+=tt[h];
            tt[h*2]+=tt[h];
            tt[h*2+1]+=tt[h];
            tt[h]=0;
        }
    }

    void build(int h,int l,int r)
    {
        d[h]=0;tt[h]=0;leaf[h]=0;
        if (l==r) {leaf[h]=1;return;}
        int w=(l+r)/2;
        build(h*2, l, w);
        build(h*2+1, w+1, r);
        d[h]=max(d[h*2], d[h*2+1]);
    }

    void update(int h,int l,int r,int x,int y,int k)
    {
        if (x>y) return;
        push(h);
        if (l==x && y==r)
        {
            d[h]+=k;
            tt[h]+=k;
            return;
        }
        int w=(l+r)/2;
        update(h*2,l,w,x,min(y,w),k);
        update(h*2+1,w+1,r,max(x,w+1),y,k);
        d[h]=max(d[h*2],d[h*2+1]);
    }

    ll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return 0;
        push(h);
        if (l==x && y==r)
        {
            //cout << l << " " << r << " " << d[h] << " " << tt[h] << "\n";
            return d[h];
        }
        int w=(l+r)/2;
        return max(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
    }
};

segment_tree g;

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll x;
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
    }
    ll l=1;
    g.build(1,1,n);
    for (int i = 1; i <= n; i++)
    {
        while (a[l]+k<a[i]) l++;
        g.update(1,1,n,i,i,i-l+1);
    }
    //cout << "1\n";
    ll r=1;
    l=1; ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        while (r<n && a[r+1]-k<=a[i]) r++;
        while (a[l]+k<a[i]) l++;
        //cout << "--" << r << " " << g.get(1,1,n,n,n) << "\n";
        g.update(1,1,n,i+1,r,-1);
        //cout << i << " : " << i-l+1 << " " << g.get(1,1,n,i+1,n) << "\n";
        ans=max(ans, g.get(1,1,n,i+1,n)+i-l+1);
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}