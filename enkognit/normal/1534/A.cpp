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

ll n, m, k, T, TT;
pll b[2];

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

char c[3];

void solve()
{
    cin >> n >> m;
    b[0]=mp(0, 0);
    b[1]=mp(0, 0);
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        s=' '+s;
        for (int j = 1; j <= m; j++)
            if (s[j]!='.')
            {
                ll o=0;
                if (s[j]=='R') o=1;
                if ((i+j)%2) b[o].se=1; else b[o].fi=1;
            }
    }
    if (b[0].fi==1 && b[1].fi==1 || b[0].se==1 && b[1].se==1 || b[0].fi && b[0].se || b[1].fi && b[1].se)
    {
        cout << "NO\n";
        return;
    }
    if (b[0].fi) c[0]='W', c[1]='R'; else
    if (b[0].se) c[1]='W', c[0]='R'; else
    if (b[1].fi) c[0]='R', c[1]='W'; else
    if (b[1].se) c[1]='R', c[0]='W'; else
    c[1]='R', c[0]='W';
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << c[(i+j)%2];
        }
        cout << "\n";
    }
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