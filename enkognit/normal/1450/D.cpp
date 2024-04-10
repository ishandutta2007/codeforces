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

ll n, m, k, T, a[300001], kl[300001];
vector<ll> v[300001];
ll c[300001];

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

pll d[1200001];

void build(int h,int l,int r)
{
    if (l==r)
    {
        d[h]=mp(0,n+1);
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=mp(0,n+1);
}

void update(int h,int l,int r,int x)
{
    if (l==r)
    {
        d[h]=mp(x,x);
        return;
    }
    int w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x); else update(h*2+1,w+1,r,x);
    d[h].fi=max(d[h*2].fi,d[h*2+1].fi);
    d[h].se=min(d[h*2].se,d[h*2+1].se);
}

ll get_max(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h].fi;
    int w=(l+r)/2;
    return max(get_max(h*2,l,w,x,min(y,w)), get_max(h*2+1,w+1,r,max(x,w+1),y));
}

ll get_min(int h,int l,int r,int x,int y)
{
    if (x>y) return n+1;
    if (l==x && y==r) return d[h].se;
    int w=(l+r)/2;
    return min(get_min(h*2,l,w,x,min(y,w)), get_min(h*2+1,w+1,r,max(x,w+1),y));
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) v[i].clear(), kl[i]=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[a[i]].pb(i);
    }
    build(1,0,n+1);
    for (int i = 1; i <= n; i++)
    {
        ll l=0;
        for (int j = 0; j < v[i].size(); j++)
        {
            ll o1=get_max(1,0,n+1,0,v[i][j]), o2=get_min(1,0,n+1,v[i][j],n+1);
            l=max(l, o2-o1-1);
        }
        kl[l+1]++;
        kl[max(n-i+2, l+1)]--;
        for (int j = 0; j < v[i].size(); j++)
            update(1,0,n+1,v[i][j]);
    }
    ll o=0;
    for (int i = 1; i <= n; i++)
    {
        o+=kl[i];
        if (o==0) cout << "1"; else cout << "0";
    }
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
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
9 0
1 1
3 1
5 1
5 2
3 2
3 3
2 3
2 2
1 2
*/