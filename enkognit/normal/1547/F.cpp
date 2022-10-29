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

ll MOD=1e9+7;
const ld E=1e-10;

ll n, m, k, T, a[200001], bn[200001][20];

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
    ll z=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        bn[i][0]=a[i];
        z=gcd(z, a[i]);
    }
    for (int i = 1; i < 20; i++)
    {
        for (int j = 0; j < n; j++)
            bn[j][i]=gcd(bn[j][i-1],bn[(j+(1<<(i-1)))%n][i-1]);
    }
    ll mx=0;
    //cout << z << " " << bn[n-1][18] << "\n";
    for (int i = 0; i < n; i++)
    {
        ll o=0, zz=a[i], x=(i+1)%n;
        //cout << i << "\n";
        for (int j = 19; j > -1; j--)
        {
            ll p=gcd(zz, bn[x][j]);
            //cout << o << " " << p << " " << zz  << bn[x][j] << " " <<  x << " " <<j << "\n";
            if (p>z)
            {
                o+=(1<<j);
                zz=p;
                x=(x+(1<<(j)))%n;
            }
        }
        //cout << i << " " << mx << "\n";
        mx=max(mx, o+1-(z==a[i]));
    }
    cout << mx << "\n";
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