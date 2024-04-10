#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define pll pair<ll,ll>
#define pld pair<ld,ld>

using namespace std;

ll n, m, k, l, r, i, j, kol, A, B, dp[5001];
ll a[1000001];
ll in[1000001], out[1000001];
pll v[1000001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!in[a[i]]) in[a[i]]=i;
        out[a[i]]=i;
    }
    for (int i = 1; i <= n; i++)
        if (in[a[i]]==i)
    {
        ll mx=out[a[i]];
        ll sum=a[i];
        bool t=0;
        for (int j = i+1; j <= mx; j++)
        {
            if (in[a[j]]<in[a[i]]) {t=1;break;}
            if (in[a[j]]==j) sum^=a[j];
            mx=max(mx,out[a[j]]);
        }
        if (!t) {v[i]=mp(sum,mx);} else v[i]=mp(-1,-1);

    }
    for (int i = 1; i <= n; i++)
    {
        dp[i]=max(dp[i-1],dp[i]);
        if (v[i].fi==-1) continue;
        dp[v[i].se]=max(dp[v[i].se],dp[i-1]+v[i].fi);
    }
    cout << dp[n];
    return 0;
}