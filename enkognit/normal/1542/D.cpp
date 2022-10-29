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

const ll MOD=998244353;

ll n, m, k, ans, a[505], dp1[505][505], dp2[505][505];

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
    vector<ll> v;
    v.pb(-1);
    for (int i = 1; i <= n; i++)
    {
        char c;
        ll x;
        cin >> c;
        if (c=='+')
        {
            cin >> x;
            v.pb(x);
        }else
        {
            v.pb(-1);
        }
    }
    for (int it = 1; it <= n; it++)
        if (v[it]>0)
        {
            for (int i = 1; i < it; i++)
                for (int j = 0; j < it; j++)
                    dp1[i][j]=0;
            dp1[0][0]=1;
            for (int i = 0; i < it-1; i++)
                if (v[i+1]==-1)
                {
                    for (int j = 0; j <= i; j++)
                    {
                        dp1[i+1][max(j-1, 0)]=(dp1[i+1][max(j-1, 0)]+dp1[i][j])%MOD;
                        dp1[i+1][j]=(dp1[i+1][j]+dp1[i][j])%MOD;
                    }
                }else
                {
                    for (int j = 0; j <= i; j++)
                    {
                        dp1[i+1][j+(v[i+1]<=v[it])]=(dp1[i+1][j+(v[i+1]<=v[it])]+dp1[i][j])%MOD;
                        dp1[i+1][j]=(dp1[i+1][j]+dp1[i][j])%MOD;
                    }
                }

            for (int i = it; i <= n; i++)
                for (int j = 0; j <= i; j++)
                    dp2[i][j]=0;

            for (int j = 0; j <= it; j++)
                dp2[it][j]=dp1[it-1][j];

            for (int i = it; i < n; i++)
                if (v[i+1]==-1)
                {
                    for (int j = 0; j <= i; j++)
                    {
                        if (j) dp2[i+1][j-1]=(dp2[i+1][j-1]+dp2[i][j])%MOD;
                        dp2[i+1][j]=(dp2[i+1][j]+dp2[i][j])%MOD;
                    }
                }else
                {
                    for (int j = 0; j <= i; j++)
                    {
                        dp2[i+1][j+(v[i+1]<v[it])]=(dp2[i+1][j+(v[i+1]<v[it])]+dp2[i][j])%MOD;
                        dp2[i+1][j]=(dp2[i+1][j]+dp2[i][j])%MOD;
                    }
                }


            for (int i = 0; i <= n; i++)
                ans=(ans+dp2[n][i]*v[it])%MOD;
        }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin>> t;
    while (t--)
    {
        solve();
    }
    return 0;
}