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
int n,a[100000+1],dp[5000+2][2600][3];
int main(){
	fastio;
	/*
	dp[i][j][0]=dp[i-1][j-1][2]...
	*/
	cin>>n;
	rb(i,1,n) cin>>a[i];
	memset(dp,0x3f,sizeof(dp));
	dp[1][0][2]=dp[1][1][0]=0;
	rb(i,2,n){
		rb(j,0,(n+1)/2){
			if(j){
				dp[i][j][0]=min(dp[i-1][j-1][1]+max(min(a[i-2]-1,a[i-1])-a[i]+1,0),dp[i-1][j-1][2]+max(a[i-1]-a[i]+1,0));
			}
			dp[i][j][1]=dp[i-1][j][0]+max(a[i]-a[i-1]+1,0);
			dp[i][j][2]=min(dp[i-1][j][2] ,dp[i-1][j][1]);
		}
	}
//	cout<<dp[2][1][2]<<endl;
	rb(j,1,(n+1)/2){
		cout<<min(dp[n][j][0],min(dp[n][j][1],dp[n][j][2]))<<" ";
	}
	return 0;
}