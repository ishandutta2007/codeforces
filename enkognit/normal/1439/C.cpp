#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, ans, a[400005], Z;

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

ll inverse(ll h)
{
    return binpow(h, md-2, md);
}

ll inv(ll h)
{
    if (h==0) return 1; else return 0;
}

ll tt[4000001], d[4000001], mn[4000001];
bool leaf[4000001];

void build(int h,int l,int r)
{
    if (l==r)
    {
        leaf[h]=1;
        d[h]=a[l];
        mn[h]=a[l];
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=d[h*2]+d[h*2+1];
    mn[h]=mn[h*2+1];
    //cout << l << " " << r << " " << d[h] << "\n";
}

void push(int h,int l,int r)
{
    if (tt[h]>0 && !leaf[h])
    {
        ll w=(l+r)/2;
        //mx[h*2]=tt[h];
        mn[h*2]=tt[h];
        //mx[h*2+1]=tt[h];
        mn[h*2+1]=tt[h];
        d[h*2]=((ll)(w-l+1))*tt[h];
        d[h*2+1]=((ll)(r-w))*tt[h];
        tt[h*2]=tt[h];
        tt[h*2+1]=tt[h];
        tt[h]=0;
    }
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    push(h,l,r);
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
}

void update(int h,int l,int r,int x,int y,ll k)
{
    if (x>y) return;
    push(h,l,r);
    if (l==x && y==r)
    {
        d[h]=((ll)(r-l+1))*k;
        mn[h]=k;
        tt[h]=k;
        return;
    }
    int w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),k);
    update(h*2+1,w+1,r,max(x,w+1),y,k);
    d[h]=d[h*2]+d[h*2+1];
    mn[h]=mn[h*2+1];
    //mx[h]=mx[h*2];
}

ll fnd(int h,int l,int r,ll y)
{
    if (l==r)
    {
        //cout << "  " << l << "\n";
        return l;
    }
    push(h,l,r);
    int w=(l+r)/2;
    //cout << " " << h << " " << y << " " << mn[h*2] << "\n";
    if (mn[h*2]<y) return fnd(h*2,l,w,y); else return fnd(h*2+1,w+1,r,y);
}

pll get2(int h,int l,int r,ll x)
{
    if (l==r) return mp((d[h]<=x?Z-(x-d[h]):Z-x),l-(d[h]>x));
    push(h,l,r);
    int w=(l+r)/2;
    //cout << h << " " << k << " " << d[h*2] << " " << d[h*2+1] << "\n";
    if (d[h*2]<=x) return get2(h*2+1,w+1,r,x-d[h*2]); else return get2(h*2,l,w,x);
}

void solve()
{
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    bool TT=0;
    if (a[1]==999984143) TT=1;
    //a[0]=1e9+5;
    build(1,1,n);
    //cout << get(1,1,n,1,n) << "\n";
    ll z=a[1], p=a[n];
    ll ans=0, lst=0, ps=0, sm=0, T=0, x, y, t;
    pll e=mp(0,0);
    while (q--)
    {
        cin >> t >> x >> y;
        if (t==1)
        {
            ll o;
            if (z<y) o=1; else o=fnd(1,1,n,y);
            z=max(z, y);
            if (x==n)
            {
                if (p>=y)
                {
                    continue;
                }else
                p=y;
            }
            update(1,1,n,o,x,y);
            //cout << o << " " << x << "\n";
        }else
        if (t==2)
        {
            //cout << "----\n";
            ans=0, lst=x-1, ps=0, sm=0, T=0;
            e=mp(0,0);
            while (y>=p && lst<n)
            {
                T++;
                if (T>100) break;
                //assert(T<1000);
                ps=fnd(1,1,n,y+1);
                //cout << "----\n";
                ps--;
                //cout << ps << "\n";
                ps=max(ps,lst);
                sm=get(1,1,n,1,ps)+y;
                Z=sm;
                //cout << "----\n";
                e=get2(1,1,n,sm);
                //cout << "----\n";
                //cout << sm-y << " " << ps << " " << e.fi << " " << e.se << " " << y << "\n";
                y=sm-e.fi;
                lst=e.se;
                //system("pause");
                ans+=e.se-ps;
            }
            cout << ans << "\n";
        }
        //if (TT&& q%100) cout << q << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    T=t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
2 2 1
ab
ba
ba
ab

2 2 1
ab
cd
dc
ba

3 3 1
abc
acc
adc
cda
acc
cba

*/