/*
AuThOr GaRyMr
*/
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int dp[100+10][101][101][2];
int a[101];
int main(){
	int ji,ou;
	ji=ou=0;
	int n;
	cin>>n;
	rb(i,1,n){
		cin>>a[i];
	}
	rb(i,1,n){
		int ok=2;
		rb(j,1,n){
			if(a[j]==i) ok=0;
		}
		if(ok){
			if(i&1){
				ji++;
			}
			else{
				ou++;
			}
		}
	}
	memset(dp,63,sizeof(dp));
	if(a[1]){
		dp[1][ji][ou][a[1]&1]=0;
	}
	else{
		if(ji)
		dp[1][ji-1][ou][1]=0;
		if(ou)
		dp[1][ji][ou-1][0]=0;
	}
	rb(i,2,n)
		rb(j,0,ji)
			rb(k,0,ou){
				if(a[i]){
					dp[i][j][k][a[i]&1]=min(dp[i-1][j][k][0]+bool(((a[i]&1)+0)%2),dp[i-1][j][k][1]+bool(((a[i]&1)+1)%2));
				}
				else{
					if(j!=ji)
					dp[i][j][k][1]=min(dp[i-1][j+1][k][0]+bool(((1)+0)%2),dp[i-1][j+1][k][1]+bool(((1)+1)%2));
					if(k!=ou)
					dp[i][j][k][0]=min(dp[i-1][j][k+1][0]+bool(((0)+0)%2),dp[i-1][j][k+1][1]+bool(((0)+1)%2));
				}
			}
	int res=INF;
	rb(i,0,ji)
		rb(j,0,ou)
			rb(flag,0,1)
				res=min(res,dp[n][i][j][flag]);
	cout<<res;
	return 0;
}