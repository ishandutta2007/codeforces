#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
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

const ll MOD=998244353;

ll n, m, k, T, mx, X, q, ps[200005], a[200005], fact[200005], infact[200005];

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

bool is(int x,int y)
{
    if (ps[x]>ps[y]) swap(x, y);
    if (x==n-1) return 1;
    if (y==n-1) return 0; else
        return (ps[x+1]<=ps[y+1]);

}

ll C(ll n,ll k)
{
    if (n<k) return 0;
    return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ps[a[i]]=i;
    }
    ll u=0;
    for (int i = 1; i < n; i++)
    {
        if (is(a[i], a[i+1])) u++;
    }
    //cout << u << "\n";
    ll ans=0;
    for (int i = 0; i <= u; i++)
    {
        ans=(ans+C(u,i)*C(k,n-i)%MOD)%MOD;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //cin >> t;
    fact[0]=1;
    infact[0]=1;
    for (int i = 1; i <= 2e5; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i], MOD-2, MOD);
    }
    ll t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
6
1 2 3 4 5 6
1 2
3 1
3 4
3 5
3 6
5
1 2 5
1 4 3
1 6 6
2 1 3
1 2 5
*/


/*
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
*/