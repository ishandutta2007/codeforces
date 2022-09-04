#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define last Last
using namespace std;
typedef long long LL;
	LL dp[2005][2005];
int main(){
	int x,m,n;
	scanf("%d %d %d",&x,&m,&n);
	int um[2005];
	int rain[2005];
	MEM(rain);
	for(int i=0;i<x;i++)
	um[i]=1e9;
	for(int i=0;i<m;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		for(int j=l;j<r;j++)
		rain[j]=1;
	}
	for(int i=0;i<n;i++){
		int x,p;
		scanf("%d %d",&x,&p);
		um[x]=min(um[x],p);
	}

	dp[0][0]=0;
	dp[0][1]=0;
	for(int j=2;j<=x;j++)
	dp[0][j]=1e9;
	for(int i=1;i<=x;i++){
		if(rain[i-1]){
			dp[i][0]=1e9;
			for(int j=1;j<=x;j++)
			dp[i][0]=min(dp[i][0],dp[i-1][j]+um[j-1]);
			for(int j=1;j<=x;j++)
			dp[i][j]=dp[i-1][j]+um[j-1];
			for(int j=1;j<=x;j++)
			dp[i][i+1]=min(dp[i][i+1],dp[i-1][j]+um[j-1]);
		}
		else{
			dp[i][0]=dp[i-1][0];
			for(int j=1;j<=x;j++)
			dp[i][0]=min(dp[i][0],dp[i-1][j]+um[j-1]);
			for(int j=1;j<=x;j++)
			dp[i][j]=dp[i-1][j]+um[j-1];
			dp[i][i+1]=dp[i][0];
			for(int j=1;j<=x;j++)
			dp[i][i+1]=min(dp[i][i+1],dp[i-1][j]+um[j-1]);
		}
		//printf("%d ",rain[i-1]);
	}
	if(dp[x][0]>5e8)
	dp[x][0]=-1;
	printf("%lld\n",dp[x][0]);
}