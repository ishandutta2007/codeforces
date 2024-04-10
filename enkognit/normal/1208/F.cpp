#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

ll n, m, i, j, w, y, a[1000001];
pll dp[6000001];
vector <pll> v, ans;

pll desu(pll x,pll y)
{
    if (x.se>=y.fi) return x; else
    if (y.se>=x.fi) return y; else
    return mp(max(x.fi,y.fi),min(x.fi,y.fi));
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i <= (1<<21); i++) dp[i]=mp(-1,-1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[a[i]]=desu(dp[a[i]],mp(i,-1));
    }


    for (int j = 0; j < 21; j++)
        for (int i = 0; i < 2e6+1; i++)
            if ((i&(1<<j))==0)
            {
                ll p=i|(1<<j);
                dp[i]=desu(dp[i],dp[p]);
            }
    ll ans=0;
    for (int i = 0; i < n-2; i++)
    {
        ll res=0, mask=0;
        for (ll j = 20; j+1; j--)
        {
            if ((a[i]&(1<<j))==(1<<j)) res|=(1<<j);else
            {
                mask|=(1<<j);
                if (dp[mask].se>i) res|=(1<<j); else mask^=(1<<j);
            }
        }
        ans=max(res,ans);
    }
    cout << ans;
    return 0;
}