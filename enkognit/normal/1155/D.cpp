#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1000000007;

ll n, m, i, j, ans, Q, k, l, T, dp[300005][3];
string s;
vector <ll> v;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        dp[i][0]=max(dp[i-1][0]+x,max(x,0ll));
        dp[i][1]=max(max(dp[i-1][1]+x*m, dp[i-1][0]+x*m),0ll);
        dp[i][2]=max(max(dp[i-1][2]+x, dp[i-1][1]+x),0ll);
        ans=max(ans,max(max(dp[i][0], dp[i][1]), dp[i][2]));
    }
    cout << ans;
}
/*
10 11
1 2
1 3
1 4
3 4
2 5
2 6
5 6
3 7
4 8
5 9
6 10
*/