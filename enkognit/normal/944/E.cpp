#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, T, sm, a[200005], kl[200005], dp[200005], pr[1000001], sf[1000001];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

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

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        kl[x]++;
        kl[y+1]--;
    }

    for (int i = 1; i <= m; i++)
    {
        a[i]=a[i-1]+kl[i];
    }

    ll len=0;

    for (int i = 1; i <= m; i++)
    {
        ll l=0, r=len;
        while (l<r)
        {
            int w=(l+r+1)/2;
            if (dp[w]<=a[i]) l=w; else r=w-1;
        }
        dp[l+1]=a[i];
        if (l+1>len) len++;
        pr[i]=len;
        //cout << i << " " << pr[i] << "\n";
    }

    len=0;

    for (int i = m; i > 0; i--)
    {
        ll l=0, r=len;
        while (l<r)
        {
            int w=(l+r+1)/2;
            if (dp[w]<=a[i]) l=w; else r=w-1;
        }
        dp[l+1]=a[i];
        if (l+1>len) len++;
        sf[i]=len;
    }
    ll ans=0;
    for (int i = 1; i <= m; i++)
    {
        ans=max(ans, max(pr[i]+sf[i+1], pr[i-1]+sf[i]));
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
12 19

8104756243030 6378153829074 7864481946698 7989644292977 6203792744877 7139461054198 7417193946416 6746398916257 7921954925499 8164742799871 6117430537523 7832265773212

2 7832265773212

1 8085437996816

2 7139461054198

1 6093518998518

2 7864481946698

2 7417193946416

2 6203792744877

2 6746398916257

1 7739700243907

2 7739700243907

1 7086445635445

1 6598712266235

2 6598712266235

1 6669032332134

2 7921954925499

1 6390459948701

2 7989644292977

2 8164742799871

1 5687905455139

*/