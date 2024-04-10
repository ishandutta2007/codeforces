#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
LL mod=1e9+7;
LL dp[1005][1005][2];
LL DP(int x,int y,int k){
	//printf("%d %d %d\n",x,y,k);
	if(y<0)return 0;
	if(x<y)return 0;
	if(dp[x][y][k]!=-1)return dp[x][y][k];
	dp[x][y][k]=0;
	if(k==0){
		dp[x][y][k]=(DP(x-1,y,1)+DP(x,y-1,1))%mod;
	}
	else{
		if(y!=0)
			dp[x][y][k]=(DP(x-1,y,1)+DP(x,y-1,0)+1)%mod;
		else
			dp[x][y][k]=(DP(x-1,y,0)+1)%mod;
	}
//	printf("%d %d %d %d\n",x,y,k,dp[x][y][k]);
	return dp[x][y][k];
}
LL f_pow(LL a,LL b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));	
	dp[0][0][0]=0;
	dp[0][0][1]=0;
	//printf("%lld\n",f_pow(3,n-1));
	printf("%lld\n",DP(n,n,0));
}