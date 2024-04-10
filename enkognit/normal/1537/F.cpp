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

const ll MOD=1e9+7;

ll n, m, k, a[1000000];
vector<ll> c[200005];

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

ll cl[200005];
bool T;

void dfs(int h,int k)
{
    cl[h]=k;
    for (int i = 0; i < c[h].size(); i++)
        if (cl[c[h][i]]==0)
        {
            dfs(c[h][i], k%2+1);
        }else
        {
            if (cl[c[h][i]]==cl[h])
                T=1;
        }
}

void solve()
{
    cin >> n >> m;
    T=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cl[i]=0;
        c[i].clear();
    }
    ll sm=0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a[i]=x-a[i];
        sm+=a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    if (sm%2)
    {
        cout << "NO\n";
        return;
    }
    dfs(1, 1);
    if (T) cout << "YES\n"; else
    {
        ll sm1=0, sm2=0;
        for (int i = 1; i <= n; i++)
            if (cl[i]==1) sm1+=a[i]; else sm2+=a[i];
        if (sm1==sm2) cout << "YES\n"; else cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin>> t;
    while (t--)
    {
        solve();
    }
    return 0;
}