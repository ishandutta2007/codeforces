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

char rev(char c)
{
    if (c=='R') return 'B'; else return 'R';
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (a[1]==1)
    {
        cout << n+1 << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n";
        return;
    }
    if (a[n]==0)
    {
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << n+1;
        cout << "\n";
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i]==0 && a[i+1]==1)
        {
            for (int j = 1; j <= i; j++)
                cout << j << " ";
            cout << n+1 << " ";
            for (int j = i+1; j <= n; j++)
                cout << j << " ";
            cout << "\n";
            return;
        }
    }
    cout << "-1\n";
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