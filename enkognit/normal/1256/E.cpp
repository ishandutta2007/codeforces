#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define sqr(a) ((a)*(a))
#define pld pair<ld,ld>

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r;
ll q, y;
ll kla, klb, dp[1000001], ans[1000001], e[1000001];
ll a[1000001];
string s, d;
vector <pll> v;
bool tt[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.pb(mp(0,0));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.pb(mp(a[i],i));
    }
    sort(v.begin(),v.end());
    dp[0]=0;
    for (int i = 1; i <= n; i++) dp[i]=1e18;
    for (int i = 0; i < n; i++)
        for (int j = 3; j < min(n-i+1,6ll); j++)
        {
            if (dp[i+j]>dp[i]+v[i+j].fi-v[i+1].fi)
            {
                dp[i+j]=dp[i]+v[i+j].fi-v[i+1].fi;
                e[i+j]=j;
            }
        }
    ll p=0;
    tt[n]=1;
    for (int i = n; i > 0; i--)
    {
        if (tt[i]) p++, tt[i-e[i]]=1;
        ans[v[i].se]=p;
    }
    cout << dp[n] << " " << p << "\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}