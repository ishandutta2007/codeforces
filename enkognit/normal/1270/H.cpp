#include <bits/stdc++.h>
#include <random>
#include <ctime>
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
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, ans, Z=1e6+1, TT, a[1000005], kl[1000005];

ll binpow(ll h, ll r, ll md=MOD)
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

pair<pair<int,bool>, int> d[5000000];
int tt[5000000];

void push(int h)
{
    if (tt[h])
    {
        tt[h*2]+=tt[h];
        tt[h*2+1]+=tt[h];
        d[h*2].fi.fi+=tt[h];
        d[h*2+1].fi.fi+=tt[h];
        tt[h]=0;
    }
}
void build(int h,int l,int r)
{
    if (l==r)
    {
        d[h].se=1;
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h].se=d[h*2].se+d[h*2+1].se;
}


void upd(int h,int l,int r,int x,int k)
{
    if (l==r)
    {
        d[h].fi.se=k;
        return;
    }
    push(h);
    int w=(l+r)/2;
    if (x<=w) upd(h*2,l,w,x,k); else upd(h*2+1,w+1,r,x,k);
    if (d[h*2].fi.se>d[h*2+1].fi.se) d[h]=d[h*2]; else
    if (d[h*2].fi.se<d[h*2+1].fi.se) d[h]=d[h*2+1]; else
    if (d[h*2].fi.fi<d[h*2+1].fi.fi) d[h]=d[h*2]; else
    if (d[h*2].fi.fi>d[h*2+1].fi.fi) d[h]=d[h*2+1]; else
        d[h]=mp(d[h*2].fi, d[h*2].se+d[h*2+1].se);
    //cout << " " << l << " " << r << " " << k << " " << d[h].fi.fi << " " << d[h].fi.se << " " << d[h].se << "\n";
}

void update(int h,int l,int r,int x,int y,int k)
{
    if (x>y) return;
    push(h);
    if (l==x && y==r)
    {
        d[h].fi.fi+=k;
        tt[h]+=k;
        return;
    }
    int w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),k);
    update(h*2+1,w+1,r,max(x,w+1),y,k);
    if (d[h*2].fi.se>d[h*2+1].fi.se) d[h]=d[h*2]; else
    if (d[h*2].fi.se<d[h*2+1].fi.se) d[h]=d[h*2+1]; else
    if (d[h*2].fi.fi<d[h*2+1].fi.fi) d[h]=d[h*2]; else
    if (d[h*2].fi.fi>d[h*2+1].fi.fi) d[h]=d[h*2+1]; else
        d[h]=mp(d[h*2].fi, d[h*2].se+d[h*2+1].se);
}

pair<pair<int, bool>, int> get(int h,int l,int r,int x,int y)
{
    if (x>y) return mp(mp(0,0), 0);
    if (l==x && y==r) return d[h];
    push(h);
    int w=(l+r)/2;
    auto o1=get(h*2,l,w,x,min(y,w)), o2=get(h*2+1,w+1,r,max(x,w+1),y);
    if (o1.fi.se>o2.fi.se) return o1; else
    if (o1.fi.se<o2.fi.se) return o2; else
    if (o1.fi.fi<o2.fi.fi) return o1; else
    if (o1.fi.fi>o2.fi.fi) return o2; else
        return mp(o1.fi, o1.se+o2.se);
}

void solve()
{
    ll q;
    cin >> n >> q;
    a[0]=1e6+1;
    build(1,0,Z);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        kl[a[i]]++;
        upd(1,0,Z,a[i],1);
        update(1,0,Z,min(a[i],a[i-1]),max(a[i],a[i-1])-1,1);
    }
    vector<ll> an;
    update(1,0,Z,0,a[n]-1,1);
    for (int i = 1; i <= q; i++)
    {
        ll x, y;
        cin >> x >> y;
        update(1,0,Z,min(a[x],a[x-1]),max(a[x],a[x-1])-1,-1);
        update(1,0,Z,min(a[x],a[x+1]),max(a[x],a[x+1])-1,-1);
        kl[a[x]]--;
        if (kl[a[x]]==0) upd(1,0,Z,a[x],0);
        a[x]=y;
        kl[a[x]]++;
        if (kl[a[x]]==1) upd(1,0,Z,a[x],1);
        update(1,0,Z,min(a[x],a[x-1]),max(a[x],a[x-1])-1,1);
        update(1,0,Z,min(a[x],a[x+1]),max(a[x],a[x+1])-1,1);
        pair<pair<int,bool>, int> o=get(1,0,Z,0,Z);
        //cout << " " << o.fi.fi << " " << o.fi.se << " " << o.se << "\n";
        if (o.fi.se!=1 || o.fi.fi!=1)
        {
            cout << i << " " << o.fi.fi << " " << o.fi.se << " " << o.se << "\n";
            exit(0);
        }else an.pb(o.se);
    }
    for (int i = 0; i < an.size(); i++) cout << an[i] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
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
4 4
4 7
5 8
6 4
9 6
1 9 11 8 4
1 3 7 8 2
1 3 6 8 1
1 13 6 3 11


4 8
4 7
5 8
6 4
9 6
1 9 11 8 4
1 3 7 8 2
1 3 6 8 1
1 13 6 3 11
2 6 4 5 8
2 6 6 7 7
2 7 5 9 11
2 5 3 6 6
*/