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
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, T, ans=0, a[1001], b[1001];
vector<ll> c[1001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h;
        h *= h;
        //h %= md;
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

struct segment_tree_1
{
    pii d[2000001];
    bool tt[2000001];
    bool leaf[2000001];
    int sz;

    void build(int h,int l,int r)
    {
        if (l==r)
        {
            d[h]=mp(0,0);
            leaf[h]=1;
        }
    }

    void build(int h)
    {
        sz=h;
        build(1,0,sz);
    }

    void update(int h,int l,int r,int x,int k)
    {
        push(h);
        if (l==r)
        {
            d[h].fi+=k;
            d[h].se+=k;
            return;
        }
        int w=(l+r)/2;
        if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
        d[h].fi=max(d[h*2].fi,d[h*2+1].fi);
        d[h].se=min(d[h*2].se,d[h*2+1].se);
    }

    void update(int x,int k)
    {
        update(1,0,sz,x,k);
    }

    inline void push(int h)
    {
        if (tt[h])
        {
            if (!leaf[h])
            {
                tt[h*2]^=tt[h];
                swap(d[h*2].fi,d[h*2].se);
                tt[h*2+1]^=tt[h];
                swap(d[h*2+1].fi,d[h*2+1].se);
            }
            tt[h]=0;
        }
    }

    void rev(int h,int l,int r,int x,int y)
    {
        if (x>y) return;
        if (l==x && y==r)
        {
            swap(d[h].fi,d[h].se);
            tt[h]=1;
            return;
        }
        int w=(l+r)/2;
        rev(h*2,l,w,x,min(y,w));
        rev(h*2+1,w+1,r,max(x,w+1),y);
        d[h].fi=max(d[h*2].fi,d[h*2+1].fi);
        d[h].se=max(d[h*2].se,d[h*2+1].se);
    }

    void rev(int x,int y)
    {
        rev(1,0,sz,x,y);
    }
};

//segment_tree_1 g;

bool comp(int x,int y)
{
    if (a[x]==a[y]) return x<y; else return a[x]<a[y];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        //c[i]=i;
        b[i]=i;
    }
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            if (a[i]>a[j])
            {
                c[i].pb(j);
            }
    sort(b+1,b+n+1,comp);
    for (int i = 1; i <= n; i++) a[b[i]]=i;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        sort(all(c[i]),comp);
        reverse(all(c[i]));
        for (int j = 0; j < c[i].size(); j++)
        {
            swap(a[i],a[c[i][j]]);
            v.pb(mp(i,c[i][j]));
        }
    }
    cout << v.size() << "\n";
    for (int i = 0 ;i < v.size(); i++) cout << v[i].fi << " " << v[i].se << "\n";
    return 0;
}

/*
3
4 2
1 1
1 0
3 2
2 2

3 1
1 1
1 0
3 2

3 2
1 1
1 0
3 2
*/