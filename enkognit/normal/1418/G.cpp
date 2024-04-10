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

ll n, m, a[500005];

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
    if (x==0 || y==0) return x+y;
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

vector<int> v[500001];

pll d[4000001];
ll tt[4000001];
bool leaf[4000001];

void build(int h,int l,int r)
{
    if (l==r)
    {
        d[h]=mp(n,1);
        leaf[h]=1;
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=mp(n,r-l+1);
}

void push(int h)
{
    if (tt[h] && !leaf[h])
    {
        d[h*2].fi+=tt[h];
        d[h*2+1].fi+=tt[h];
        tt[h*2]+=tt[h];
        tt[h*2+1]+=tt[h];
        tt[h]=0;
    }
}

void update(int h,int l,int r,int x,int y,int k)
{
    push(h);
    if (x>y) return;
    if (l==x && y==r)
    {
        tt[h]+=k;
        d[h].fi+=k;
        return;
    }
    int w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),k);
    update(h*2+1,w+1,r,max(x,w+1),y,k);
    if (d[h*2].fi>d[h*2+1].fi) d[h]=d[h*2]; else
    if (d[h*2].fi<d[h*2+1].fi) d[h]=d[h*2+1]; else
        d[h]=mp(d[h*2].fi,d[h*2].se+d[h*2+1].se);
}

pll get(int h,int l,int r,int x,int y)
{
    push(h);
    if (x>y) return mp(0,0);
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    pll o1=get(h*2,l,w,x,min(y,w)), o2=get(h*2+1,w+1,r,max(x,w+1),y);
    if (o1.fi>o2.fi) return o1; else
    if (o1.fi<o2.fi) return o2; else return mp(o1.fi, o1.se+o2.se);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1,1,n);
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        v[a[i]].pb(i);
        if (v[a[i]].size()==1) update(1,1,n,1,i,-1);else
        if (v[a[i]].size()==2) update(1,1,n,v[a[i]][v[a[i]].size()-2]+1,i,-1); else
        if (v[a[i]].size()==3)
        {
            update(1,1,n,1,v[a[i]][0],1);
            update(1,1,n,v[a[i]][v[a[i]].size()-2]+1,i,-1);
        }else
        {
            ll o=0;
            if (v[a[i]].size()>4) o=v[a[i]][v[a[i]].size()-5];
            update(1,1,n,o+1,v[a[i]][v[a[i]].size()-4],-1);
            update(1,1,n,v[a[i]][v[a[i]].size()-4]+1,v[a[i]][v[a[i]].size()-3],1);
            update(1,1,n,v[a[i]][v[a[i]].size()-2]+1,i,-1);
        }
        pll u=get(1,1,n,1,i);ll p=ans;
        if (u.fi==n) ans+=u.se;
        //cout << ans-p << "\n";
        //for (int j = 1; j <= i; j++) cout << get(1,1,n,j,j).fi << " ";
        //cout << "\n";
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
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
*/