#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define y1 Enkognit
#define fi first
#define se second
#define pll pair<ll, ll>

using namespace std;

ll MOD=998244353;
ll n, m, k, l, r, i, j, a[1000001], fact[100001], infact[100001], dp[1000001];
ll w[10001];
vector <pll> v;

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r%2) l=(l*h)%MOD;
        h=(h*h)%MOD;
        r/=2;
    }
    return l;
}

ll get_c(ll n,ll k)
{
    return ((fact[n]*infact[k])%MOD*infact[n-k])%MOD;
}

int main()
{
    cin >> n;
    fact[0]=1;
    infact[0]=1;
    for (int i = 1; i <= n; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i],MOD-2)%MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0]=0;
    ll sum=1, ans=0;
    for (int i = 1; i <= n; i++)
        if (a[i]>0)
        {
            for (int j = i+a[i]; j <= n; j++)
                dp[j]=(dp[j]+(ans+1)*get_c(j-i-1,a[i]-1)%MOD)%MOD;
            ans+=dp[i];
            ans%=MOD;
            //cout << dp[i] << "\n";
        }else
         ans+=dp[i];
    cout << ans;
    return 0;
}