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

ll n, m, k, T, a[200005], b[200005], d[200005][20];

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
    }

    for (int i = n-1; i > 0; i--)
    {
        d[i][0]=abs(a[i]-a[i+1]);
        for (int j = 1; j < 20; j++)
        {
            if (i+(1<<j)-1<=n)
                d[i][j]=gcd(d[i][j-1],d[i+(1<<(j-1))][j-1]);
            else
                break;
        }
    }

    ll ans=1;

    for (int i = 1; i < n; i++)
    {
        ll o=0, x=i;
        //cout << i << ":\n";
        for (int j = 19; j > -1 && x<n; j--)
            if (x+(1<<j)<=n)
            {
                ll k=gcd(o,d[x][j]);
                //cout << " " << x << " " << j << " " << d[x][j] << " " << k << "\n";
                if (k!=1) o=k, x+=(1<<j);
            }
        //cout << " ! "<< x-i+1 << " " << x << "\n";
        ans=max(ans, x-i+1);
    }
    cout << ans << "\n";

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