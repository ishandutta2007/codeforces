#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
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

ll n, m, k, sz, fact[200005], infact[200005], dp[200050], pr[200050];
ll a[200005];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

void solve()
{
    string s;
    ll k;
    cin >> s >> k;
    ll ans=0;
    for (int i = 0; i < s.size(); i++)
    {
        ll p=s[i]-'0';
        //cout << p+k << " " << dp[k+p] << "\n";
        ans=(ans+dp[k+p])%MOD;
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
    dp[0]=1;
    pr[0]=1;
    for (int i = 1; i <= 2e5+10; i++)
    {
        dp[i]=1;
        if (i>9)
        {
            dp[i]=(pr[i-10]+1)%MOD;
        }
        if (i>8) pr[i]=pr[i-9];
        pr[i]=(pr[i]+dp[i])%MOD;
    }
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/