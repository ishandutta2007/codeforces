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

ll n, m, k, T, a[200005], b[200005];

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

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i%2==0) a[i]=-a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        a[i]+=a[i-1];
    }
    ll ans=0;
    for (int i = 0; i < n; i+=2)
    {
        ll e=1e18;
        //cout << i << "\n";
        for (int j = i+2; j <= n; j+=2)
        {
            e=min(e, a[j-1]);
            if (e<a[i]) break;
            ll pr=a[j-1]-a[i];
            ll x=min(e-a[i], a[i+1]-a[i]), y=abs(a[j]-a[j-1]);
            ll o=a[j-1]-a[i]-x;
            //cout << i << " " << j << " " << e << " - " << x << " " << y << " " << o << " " << max(min(x, y-o)+1,0ll) << "\n";
            ans+=max(min(x, y-o)+1-(j==i+2),0ll);
            e=min(e, a[j]);
        }
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