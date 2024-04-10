#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef vector<vector<ll>> mat;
const ll mod=1e9+7;
const int N=1e5+5;
int n,m;
ll dp[N];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	dp[0]=2; dp[1]=2;
	for(int i=2;i<=1e5;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;
	cout<<(dp[n]+dp[m]-2+mod)%mod;
	return 0;
}