#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, kol=0, T=0, mask, dp[300001][4];

string s;
ll tt[200001];
vector <ll> v1, v2, v3;
bool t1[200001], t2[200001], t3[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    n=k1+k2+k3;
    for (int i = 0; i < k1; i++)
    {
        ll x;
        cin >> x;
        t1[x]=1;
    }
    for (int i = 0; i < k2; i++)
    {
        ll x;
        cin >> x;
        t2[x]=1;
    }
    for (int i = 0; i < k3; i++)
    {
        ll x;
        cin >> x;
        t3[x]=1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][1]=dp[i-1][1]+!t1[i];
        dp[i][2]=min(dp[i-1][1],dp[i-1][2])+!t2[i];
        dp[i][3]=min(min(dp[i-1][1],dp[i-1][2]),dp[i-1][3])+!t3[i];
    }
    cout << min(min(dp[n][1],dp[n][2]),dp[n][3]);
    return 0;
}
/*
1
9
1 3 1 10 5 1 2 3 4
6
5 2
11 1
4 3
10 1
2 1
2 55
3
*/