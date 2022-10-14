/*
{By GWj
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
int n;
int dp[5005][5005];
int a[5005];
int main(){
	fastio;
	R(n);
	rb(i,1,n){
		R(a[i]);
	}
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;
	rb(i,1,n){
		rb(j,0,n){
			if(j>a[i]){
				dp[i][a[i]]=min(dp[i][a[i]],dp[i-1][j]);
			}
			else{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+(a[i]!=j));
			}
			if(a[i]>=j){
				if(i==1){
					dp[i][j]=min(dp[i][j],j+(j!=a[i]));
				}	
				else{
					if(a[i-1]<j)
					dp[i][j]=min(dp[i][j],dp[i-1][a[i-1]]+j-a[i-1]+(j!=a[i]));
				} 
			}
		}
	}
//	cout<<dp[10][6]<<endl;
	int rest=INF;
	rb(i,0,n){
		rest=min(rest,dp[n][i]);
	}
	cout<<rest<<endl;
	return 0;
}
/*
16
1 1 2 3 3 4 5 6 6 6 4 3 2 1 1 1
*/