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

ll n, m, k, T, kol[10001], a[200005][20], dp[(1<<18)];

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
    string s;
    cin >> n >> k;
    cin >> s;
    s=' '+s;
    ll l=0, r=n;
    while (l<r)
    {
        ll w=(l+r+1)/2;
        ll kl=0;
        //cout << w << "\n";
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= n+1; j++) a[j][i]=n+1;
        }
        for (int i = 0; i < k; i++) kol[i]=0;
        for (int i = 1; i <= w; i++)
            if (s[i]!='?') kol[s[i]-'a']++; else kl++;

        for (int i = 1; i <= n-w+1; i++)
        {
            ll p=-1, o=0;
            for (int j = 0; j < k; j++)
                if (kol[j]>0) p=j, o++;
            if (i+w<=n)
            {
                if (s[i]=='?') kl--; else
                    kol[s[i]-'a']--;
                if (s[i+w]=='?') kl++; else
                    kol[s[i+w]-'a']++;
            }
            if (o>1) continue;
            a[i][p+1]=i;
            //cout << " " << p+1 << " " << i << "\n";
        }

        //cout << "----\n";

        for (int i = 0; i <= k; i++)
        {
            ll mn=n+1;
            for (int j = n+1; j > -1; j--)
            {
                mn=min(mn, (ll)a[j][i]);
                a[j][i]=mn;
            }
        }

        dp[0]=0;
        for (int i = 1; i < (1<<k); i++)
            dp[i]=n+1;

        //cout << "----\n";

        for (int i = 0; i < (1<<k)-1; i++)
            if (dp[i]<n+1)
            {
                //cout << i << " " << dp[i] << "\n";
                for (int j = 0; j < k; j++)
                    if ((i&(1<<j))==0)
                    {
                        //cout << " + " << j << " " << a[dp[i]+1][0] << " " << a[dp[i]+1][j+1] << "\n";
                        dp[i|(1<<j)]=min(dp[i|(1<<j)], min(a[dp[i]+1][0], a[dp[i]+1][j+1])+w-1);
                    }

            }
        if (dp[(1<<k)-1]<n+1) l=w; else r=w-1;
    }
    cout << l << "\n";
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