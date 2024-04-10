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

ll n, m, k, T, ans[500005];
vector<ll> c[500005];

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

pll dfs(int h,int p=-1)
{
    ll z=0;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            pll u=dfs(c[h][i], h);
            if (!u.fi) return mp(0, 0);
            z+=u.se;
        }
    //cout << h << " " << z << "\n";
    if (z%T==0) return mp(1, 1); else
    if ((z+1)%T==0) return mp(1, 0); else return mp(0, 0);
}

void solve()
{
    cin >> n;
    ll x=n-1, p=sqrt(x);
    vector<ll> v;
    for (int i = 1; i <= n; i++) ans[i]=0, c[i].clear();
    for (int i = 1; i <= p; i++)
        if (x%i==0)
        {
            v.pb(i);
            if (x/i!=i) v.pb(x/i);
        }

    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    ans[1]=binpow(2,n-1,MOD);
    for (int i = 1; i < v.size(); i++)
    {
        T=v[i];
        pll o=dfs(1);
        if (o.fi && o.se) ans[v[i]]=1;
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = i*2; j <= n; j+=i)
            ans[i]-=ans[j];
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}