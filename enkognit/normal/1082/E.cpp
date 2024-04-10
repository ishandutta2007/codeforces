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

ll n, m, k, l, r, i, j, kol, A, B, last[1000001], tt[1000001], mn[1000001];
ll a[1000001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll kl=0, ans=0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i]==m) kl++; else
        {
            last[a[i]]-=kl-tt[a[i]];
            mn[a[i]]=min(mn[a[i]],last[a[i]]);
            last[a[i]]++;
            tt[a[i]]=kl;
            ans=max(ans,last[a[i]]-mn[a[i]]);
        }
    }
    cout << ans+kl;
    return 0;
}