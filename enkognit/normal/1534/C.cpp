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

ll n, m, k, T, TT, a[1000001], b[1000001];

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

ll d[1000001];

void make_sets(int h)
{
    for (int i = 1; i <= h; i++) d[i]=i;
}

ll find_set(int h)
{
    if (h==d[h]) return h; else return d[h]=find_set(d[h]);
}

bool unite_sets(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if (x!=y)
    {
        d[x]=y;
        return 1;
    }
    return 0;
}

void solve()
{
    cin >> n;
    make_sets(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    bool tt=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (a[i]==b[i])
        {
            tt=1;
        }
    }
    if (tt)
    {
        cout << "0\n";
        return;
    }
    ll kl=n;
    for (int i = 1; i <= n; i++)
    {
        kl-=unite_sets(a[i], b[i]);
    }
    cout << binpow(2, kl, MOD) << "\n";
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