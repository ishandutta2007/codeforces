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

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k;

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

vector<ll> q[2][400001];

struct segment_tree
{
    ll d[2000001];
    bool leaf[2000001];
    ll tt[2000001];

    void build(int h,int l,int r)
    {
        d[h]=0;
        tt[h]=0;
        if (l==r) {leaf[h]=1;return;}
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
    }

    void push(int h)
    {
        if (!leaf[h] && tt[h])
        {
            d[h*2]+=tt[h];
            d[h*2+1]+=tt[h];
            tt[h*2]+=tt[h];
            tt[h*2+1]+=tt[h];
            tt[h]=0;
        }
    }

    void update(int h,int l,int r,int x,int y)
    {
        if (x>y) return;
        push(h);
        if (l==x && y==r)
        {
            tt[h]++;
            d[h]++;
            return;
        }
        int w=(l+r)/2;
        update(h*2,l,w,x,min(y,w));
        update(h*2+1,w+1,r,max(x,w+1),y);
        d[h]=max(d[h*2],d[h*2+1]);
    }

    void update2(int h,int l,int r,int x,int k)
    {
        push(h);
        if (l==r)
        {
            d[h]=k;
            return;
        }
        int w=(l+r)/2;
        if (x<=w) update2(h*2,l,w,x,k); else update2(h*2+1,w+1,r,x,k);
        d[h]=max(d[h*2],d[h*2+1]);
    }

    /*void get(int h,int l,int r,int x)
    {
        if (l==r) return d[h];
        int w=(l+r)/2;
        if (x<=w) return get(h*2,l,w,x); else return get(h*2+1,w+1,r,x);
    }*/
};

segment_tree g[2];

void solve()
{
    cin >> n;
    vector<ll> v, vv;
    vector<pair<pll, ll> > c;
    for (int i = 1; i <= n; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        v.pb(x);
        v.pb(y);
        c.pb(mp(mp(x,y), h));
    }
    sort(all(v));
    for (int i = 0; i < v.size(); i++)
        if (vv.size()==0 || vv.back()<v[i]) vv.pb(v[i]);
    for (int i = 0; i < c.size(); i++)
    {
        ll l=c[i].fi.fi, r=c[i].fi.se;
        c[i].fi.fi=upper_bound(all(vv), l)-vv.begin();
        c[i].fi.se=upper_bound(all(vv), r)-vv.begin();
        c[i].se--;
        q[c[i].se][c[i].fi.se].pb(c[i].fi.fi);
    }
    ll o=v.size();
    g[0].build(1,0,o);
    g[1].build(1,0,o);
    ll ans=0;
    for (int i = 1; i <= o; i++)
    {
        for (int j = 0; j < q[0][i].size(); j++)
        {
            g[1].update(1,0,o,0,q[0][i][j]-1);
        }
        for (int j = 0; j < q[1][i].size(); j++)
        {
            g[0].update(1,0,o,0,q[1][i][j]-1);
        }
        ans=max(ans, max(g[0].d[1], g[1].d[1]));
        g[0].update2(1,0,o,i,g[1].d[1]);
        g[1].update2(1,0,o,i,g[0].d[1]);
        /*cout << i << " : ";
        cout << " 0 : ";
        for (int j = 0; j <= i; j++) cout << g[0].get(1,0,o,j) << " ";
        cout << "\n";
        cout << " 0 : ";
        for (int j = 0; j <= i; j++) cout << g[0].get(1,0,o,j) << " ";
        cout << "\n";*/
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
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
a-b=k
a+b=m
a=(m+k)/2;
b=(m-k)/2;
*/