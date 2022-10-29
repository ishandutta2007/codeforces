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

const ll MOD=1e9+7;

ll n, m, k, T, TT, b[4000005];
string s[2005];
bool tt[2005][2005];
queue<pll> q;

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

void add(int x,int y)
{
    if (x<1 || x>n || y<1 || y>m || tt[x][y] || s[x][y]=='0') return;
    T++;
    tt[x][y]=1;
    q.push(mp(x, y));
}

void solve()
{
    cin >> n >> m;
    ll ans=1;
    bool ttt=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i]=' '+s[i];
        for (int j = 1; j <= m; j++)
        {
            tt[i][j]=0;
            ttt|=(s[i][j]=='0');
        }
    }

    b[0]=1;
    for (int i = 1; i <= n*m; i++)
    {
        b[i]=b[i-1]*2%MOD;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!tt[i][j] && s[i][j]=='#')
            {
                T=0;
                add(i, j);
                while (!q.empty())
                {
                    ll x=q.front().fi, y=q.front().se;
                    q.pop();
                    add(x, y+1);
                    add(x, y-1);
                    add(x+1, y);
                    add(x-1, y);
                }
                ans=(ans*b[T])%MOD;
            }
    ttt=!ttt;
    cout << ans-ttt << "\n";
}

int main(int argc, char **argv) {
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