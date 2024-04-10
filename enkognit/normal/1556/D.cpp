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

ll n, m, k, T, a[200005], b[4][4], c[4][4];

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

ll get_i(int x,int y)
{
    cout << "or " << x << " " << y << "\n";
    ll p;
    cin >> p;
    fflush(stdout);
    return p;
}

ll get_a(int x,int y)
{
    cout << "and " << x << " " << y << "\n";
    ll p;
    cin >> p;
    fflush(stdout);
    return p;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) a[i]=0;

    for (int i = 1; i <= 3; i++)
        for (int j = i+1; j <= 3; j++)
            if (i!=j)
                b[i][j]=get_i(i, j), c[i][j]=get_a(i, j);

    a[1]=((b[1][2]+c[1][2])+b[1][3]-b[2][3]+c[1][3]-c[2][3])/2;
    a[2]=b[1][2]-a[1]+c[1][2];
    a[3]=b[1][3]-a[1]+c[1][3];
    for (int i = 4; i <= n; i++)
    {
        ll o1=get_i(1,i), o2=get_a(1,i);
        a[i]=o1+o2-a[1];
    }
    //for (int i = 1; i <= n; i++) cout << a[i] << "\n";
    sort(a+1,a+n+1);
    cout << "finish " << a[k] << "\n";
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}