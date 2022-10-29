#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pll pair<ll,ll>
#define y1 Enkognit
#define fi first
#define se second
#define pld pair<ld,ld>

using namespace std;

const ll MOD=1000000007;

ll l, r, n, m, k, x, y, dp[1000001], dk[1000001][2];
ll tt[1000001], ta[1000001];
vector <ll> an;

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h,l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}


int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    vector<ll> v;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v.pb(x);
        ta[x]++;
    }
    sort(v.begin(),v.end());
    ll oo=0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!tt[v[i]-1]) tt[v[i]-1]=1,oo++; else
        if (!tt[v[i]]) tt[v[i]]=1,oo++; else
        if (!tt[v[i]+1]) tt[v[i]+1]=1,oo++;
    }
    for (int i = 1; i <= n+1; i++)
    {
        dp[i]=1e18;
    }
    dp[2]=((ta[1]+ta[2])>0);
    dp[1]=((ta[1])>0);
    dp[0]=0;
    for (int i = 0; i <= n; i++)
    {
        //cout << dp[i] << "\n";
        dp[i+3]=min(dp[i+3],dp[i]+((ta[i+1]+ta[i+2]+ta[i+3])>0));
        dp[i+2]=min(dp[i+2],dp[i]+((ta[i+1]+ta[i+2])>0));
        dp[i+1]=min(dp[i+1],dp[i]+((ta[i+1])>0));
    }
    cout << dp[n+1] << " " << oo;
    return 0;
}