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

ll n, m, k, a[10001], b[10001];

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

ll aa(ll x,ll y)
{
    return k*((x*x%m*y)%m)%m;
}

void solve()
{
    cin >> n >> m;
    ll mx=-1e18;
    string s;
    cin >> s;
    s=' '+s;
    //ll k=0;
    for (int i = 1; i <= n; i++)
    {
        //k+=(s[i]=='1');
        if (s[i]=='1') mx=i;
        b[i]=i-mx;
    }
    mx=1e18;
    for (int i = n; i > 0; i--)
    {
        if (s[i]=='1') mx=i;
        b[i]=min(mx-i, b[i]);
    }

    for (int i = 1; i <= n; i++)
        if (b[i]<=m && !(i>1 && i<n && b[i-1]==b[i+1] && s[i]=='0')) cout << "1"; else cout << "0";
    cout << "\n";
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