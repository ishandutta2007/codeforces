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

ll n, m, k, T, TT, dist[1001], fr[1001];
ll a[1001][1001];
bool tt[1001];

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
    cin >> n >> k;
    queue<ll> q;
    q.push(0);
    tt[0]=1;
    while (!q.empty())
    {
        ll x=q.front();
        //cout << x << " : ";
        //for (int i = 1; i <= n; i++) cout << a[x][i];
        //cout << "\n";
        q.pop();
        for (int j = max(0ll, (x+k-n)); j <= min(x, k); j++)
        {
            if (x+k-j>n) continue;
            ll to=x+k-2*j;
            if (tt[to]) continue;
            //cout << x << " -> " << to << " " << j << "\n";
            ll p1=j, p2=k-j;
            for (int i = 1; i <= n; i++)
                if (a[x][i]==1)
                {
                    if (p1) p1--, a[to][i]=0; else a[to][i]=1;
                }else
                {
                    if (p2) p2--, a[to][i]=1; else a[to][i]=0;
                }
            tt[to]=1;
            dist[to]=dist[x];
            fr[to]=x;
            q.push(to);
        }
    }
    if (!tt[n])
    {
        cout << "-1\n";
        return;
    }
    ll x=n, ans=0;
    while (x)
    {
        ll y=fr[x];
        cout << "? ";
        for (int i = 1; i <= n; i++)
            if (a[y][i]!=a[x][i])
            {
                cout << i << " ";
            }
        cout << "\n";
        ll p;
        cin >> p;
        fflush(stdout);
        ans^=p;
        x=y;
    }
    cout << "! " << ans << "\n";
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
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