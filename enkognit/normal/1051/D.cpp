#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pu push
#define ld long double
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pld pair<ll,double>

using namespace std;

const ll MOD=998244353;

ll n,m,j,l,r,k,ans,dp[1001][2001][5];
vector<pll> c[200001];
vector <ll> v;
set<pll> badedj;
map<ll,ll> t;

int main()
{
  //freopen("pizza.in","r",stdin);
  //freopen("pizza.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  dp[1][1][0]=1;
  dp[1][2][1]=1;
  dp[1][2][2]=1;
  dp[1][1][3]=1;
  for (int i = 1; i < n; i++)
      for (int k = 1; k <= m; k++)
      {
          dp[i+1][k][0]=(dp[i+1][k][0]+dp[i][k][0]+dp[i][k][1]+dp[i][k][2])%MOD;
          dp[i+1][k][1]=(dp[i+1][k][1]+dp[i][k][1])%MOD;
          dp[i+1][k][2]=(dp[i+1][k][2]+dp[i][k][2])%MOD;
          dp[i+1][k][3]=(dp[i+1][k][3]+dp[i][k][3]+dp[i][k][1]+dp[i][k][2])%MOD;
          dp[i+1][k+1][0]=(dp[i+1][k+1][0]+dp[i][k][3])%MOD;
          dp[i+1][k+1][3]=(dp[i+1][k+1][3]+dp[i][k][0])%MOD;
          dp[i+1][k+1][1]=(dp[i+1][k+1][1]+dp[i][k][3]+dp[i][k][0])%MOD;
          dp[i+1][k+1][2]=(dp[i+1][k+1][2]+dp[i][k][3]+dp[i][k][0])%MOD;
          dp[i+1][k+2][1]=(dp[i+1][k+2][1]+dp[i][k][2])%MOD;
          dp[i+1][k+2][2]=(dp[i+1][k+2][2]+dp[i][k][1])%MOD;
      }
  cout << (dp[n][m][0]+dp[n][m][1]+dp[n][m][2]+dp[n][m][3])%MOD;
}