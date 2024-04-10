#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, k, j, o, l, r, dp[3001][3001];
pll a[500001];

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a,a+n);
    dp[0][0]=a[0].se;
    for (int i = 1; i < n; i++)
    {
        ll mi=1e18;
        for (int j = i-1; j > -1; j--)
        {
            mi=min(dp[i-1][j],mi);
            dp[i][j]=dp[i-1][j]+a[i].fi-a[j].fi;
        }
        dp[i][i]=mi+a[i].se;
    }
    ll mi=1e18;
    /*for (int i = 0; i < n; i++)
    {
        cout << i+1 << ": ";
        for (int j = 0; j < i+1; j++) cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    for (int i = 0; i < n; i++) mi=min(mi,dp[n-1][i]);
    cout << mi;
    return 0;
}
/*

*/