#include <bits/stdc++.h>
//#include <random>
//#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define cringe exit(0)
#define y1 Enkognit

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-10;
//mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, Z, a[300005];
string s1, s2;
int tt[1000001];

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

ll binpow(ll h, ll r)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h;
        h*=h;
        r /= 2;
    }
    return l;
}

pii d[1000001];

pii operator + (pii x,pii y)
{
    return mp(x.fi+y.fi,x.se+y.se);
}

void build(int h,int l,int r)
{
    tt[h]=0;
    if (l==r)
    {
        d[h]=mp(0, 0);
        if (s2[l]=='0') d[h].fi++; else d[h].se++;
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=d[h*2]+d[h*2+1];
}

void push(int h,int l,int r)
{
    if (tt[h]==-1)
    {
        int w=(l+r)/2;
        d[h*2].fi=w-l+1;
        d[h*2].se=0;
        d[h*2+1].fi=r-w;
        d[h*2+1].se=0;
        tt[h*2]=tt[h];
        tt[h*2+1]=tt[h];
        tt[h]=0;
    }
    if (tt[h]==1)
    {
        int w=(l+r)/2;
        d[h*2].se=w-l+1;
        d[h*2].fi=0;
        d[h*2+1].se=r-w;
        d[h*2+1].fi=0;
        tt[h*2]=tt[h];
        tt[h*2+1]=tt[h];
        tt[h]=0;
    }
}

void update(int h,int l,int r,int x,int y,int k)
{
    if (x>y) return;
    if (l==x && y==r)
    {
        if (k==-1) d[h].fi=r-l+1, d[h].se=0; else d[h].fi=0, d[h].se=r-l+1;
        tt[h]=k;
        return;
    }
    push(h,l,r);
    int w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),k);
    update(h*2+1,w+1,r,max(x,w+1),y,k);
    d[h]=d[h*2]+d[h*2+1];
}

pii get(int h,int l,int r,int x,int y)
{
    if (x>y) return mp(0, 0);
    if (l==x && y==r) return d[h];
    push(h,l,r);
    int w=(l+r)/2;
    return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
}

void solve()
{
    cin >> n >> k;
    cin >> s1;
    s1=' '+s1;
    cin >> s2;
    s2=' '+s2;
    vector<pll> v;
    for (int i = 1; i <= k; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x, y));
    }
    //reverse(all(v));
    build(1,1,n);
    for (int i = v.size()-1; i >-1; i--)
    {
        pii o=get(1,1,n,v[i].fi,v[i].se);
        //cout << " " << o.fi << " " << o.se << "\n";
        if (o.fi==o.se)
        {
            cout << "NO\n";
            return;
        }
        if (o.fi>o.se)
        {
            update(1,1,n,v[i].fi,v[i].se,-1);
        }else
        {
            update(1,1,n,v[i].fi,v[i].se,1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        pii u=get(1,1,n,i,i);
        if (u.fi^(s1[i]=='0'))
        {
            cout << "NO\n";
            return;;
        }
    }
    cout << "YES\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("stones.in","r",stdin);
    //freopen("stones.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
6 4 13
1 2
2 3
3 4
4 5
*/