#include <bits/stdc++.h>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define el endl
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double

using namespace std;

ld PI=3.14159265359, sec_clock=1e8;

ll n, m, l, r, k, h, i, j, T, ans;
//ll a[500001], b[500001];
ll a[5005], dp[5005][5005];

int main()
{
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
    {
        ll l=i,r=n;
        while (l<r)
        {
            ll w=(l+r)/2+(l+r)%2;
            if (a[w]<=a[i]+5) l=w; else r=w-1;
        }
        for (int j = 0; j <= k; j++)
        {
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            dp[l+1][j+1]=max(dp[l+1][j+1],dp[i][j]+l-i+1);
        }
    }
    for (int i = 1; i <= n+1; i++)
        for (int j = 0; j <= k; j++) ans=max(dp[i][j],k);
    cout << ans << "\n";
    //cout.precision(9);
    //cerr << "Time: " <<fixed<< clock()/sec_clock << "\n";
    return 0;
}