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

const ll MOD=1e9+7;

ll n, m, k, a[500001];

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

void solve()
{
    cin >> n;
    vector<ll> v1, v0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if (x%2)
        {
            v1.pb(x);
        }else v0.pb(x);
    }
    for (int i = 0; i < v0.size(); i++)
    {
        a[i+1]=v0[i];
    }
    for (int i = 0; i < v1.size(); i++)
    {
        a[v0.size()+i+1]=v1[i];
    }
    ll ans=0;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            ans+=(__gcd(a[i], 2*a[j])>1);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //cin >> t;
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
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