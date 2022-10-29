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

ll n, m, k, T, a[200005], an[200005], pr[51][100005], dp[51][100005];

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

char rev(char c)
{
    if (c=='R') return 'B'; else return 'R';
}

struct dsu
{
    ll d[100001];

    void make_sets(int h)
    {
        for (int i = 1; i <= h; i++) d[i]=i;
    }

    ll find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        d[x]=y;
    }
} g1, g2;

vector<pll> v;

ll gt(ll h)
{
    ll o=m;
    vector<ll> vv;
    //cout << h << " : ";
    for (int i = 0; i < n; i++)
    {
        ll p=v[i].fi;
        if (p%h>0) p=p-p%h+h;
        if (p>v[i].se) return 0;
        o-=p;
        vv.pb((v[i].se-p)/h);
        //cout << vv.back() << " ";
    }
    //cout << "\n";
    if (o<0) return 0;
    o=o/h;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= o; j++)
        {
            dp[i][j]=0;
            pr[i][j]=0;
        }

    dp[0][0]=1;

    for (int i = 0; i <= m/h; i++) pr[0][i]=1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= o; j++)
        {
            ll u=j-vv[i]-1;
            dp[i+1][j]=pr[i][j];
            if (u>=0) dp[i+1][j]=(dp[i+1][j]-pr[i][u]+MOD)%MOD;
            pr[i+1][j]=((j>0?pr[i+1][j-1]:0)+dp[i+1][j])%MOD;
        }
    }
    //cout << pr[n][o] << " " << o << "\n";
    //cout << " " << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << "\n";
    //cout << "\n";
    return pr[n][o];
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x, y));
    }
    for (int i = m; i > 0; i--)
    {
        an[i]=gt(i);
        for (int j = i*2; j <= m; j+=i)
            an[i]=(an[i]-an[j]+MOD)%MOD;
        //cout << i << " " << an[i] << "\n";
    }
    cout << an[1] << "\n";
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