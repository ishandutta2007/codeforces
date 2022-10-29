#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#include "testlib.h"
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

ll MOD=998244353;
const ld E=1e-10;

ll n, m, k, T, pr[500001];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

ll gcd(ll x,ll y)
{
    while (x && y)
    {
        if (x<y) swap(x, y);
        x%=y;
    }
    return x+y;
}

ll d[2000001];

void push(int h)
{
    if (d[h])
    {
        d[h*2]=(d[h*2]+d[h])%MOD;
        d[h*2+1]=(d[h*2+1]+d[h])%MOD;
        d[h]=0;
    }
}

void update(int h,int l,int r,int x,int y,int k)
{
    if (x>y) return;
    if (l==x && y==r)
    {
        //cout << l << " " << r << " " << k << "\n";
        d[h]=(d[h]+k)%MOD;
        return;
    }
    push(h);
    int w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),k);
    update(h*2+1,w+1,r,max(x,w+1),y,k);
}

ll get(int h,int l,int r,int x)
{
    if (l==r)
    {
        return d[h];
    }
    push(h);
    int w=(l+r)/2;
    if (x<=w) return get(h*2,l,w,x); else return get(h*2+1,w+1,r,x);
}

void solve()
{
    cin >> n;
    vector<ll> v;
    vector<ll> zz, qq;
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        ans=x+1;
        v.pb(x);
        zz.pb(z);
        qq.pb((x-y)%MOD);
        ll o=lower_bound(all(v), y)-v.begin();
        pr[i]=o;
    }
    for (int i = n-1; i > -1; i--)
    {
        if (zz[i]==1)
            update(1,0,n-1,i,i,1);
        ll o=get(1,0,n-1,i);
        ans=(ans+qq[i]*o)%MOD;
        //cout << i << " : " << o << " " << qq[i] << "\n";
        update(1,0,n-1,pr[i],i-1,o);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}