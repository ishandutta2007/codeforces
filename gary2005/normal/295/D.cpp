/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MOD=1e9+7;
int n,m;
int dp[2002][2002];
#define add(a,b) a+=b;if(a>=MOD){a-=MOD;}
int two[2002*2002]={1};
int main(){
	fastio;
	cin>>n>>m;
	rb(i,2,m)
		dp[1][i]=1;
	rb(i,1,n*m)
	{
		two[i]=two[i-1]*2;
		add(two[i],0);
	}
	rb(i,2,n){
		int g=0,s=0;
		rb(j,2,m)
		{
			add(s,dp[i-1][j]);
			add(g,s);
			dp[i][j]=g;	
		}	
	}
	rb(j,1,m){
		rb(i,1,n){
			add(dp[i][j],dp[i-1][j]);
		}
	}
	int rest=0;
	rb(i,1,n){
		int ways=1;
		int sum=0;
		rb(j,2,m){
			add(sum,dp[i-1][j-1]);
			add(ways,sum);
			add(ways,dp[i-1][j-1]);
			add(rest,(1ll*ways*dp[n-i+1][j]%MOD*(m-j+1)%MOD));
		}
	}
	cout<<rest<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/