#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int dp[1<<16][130];
char in[20];
int p[20];
int q[20];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%s%d%d",in+i,p+i,q+i);
	}
	for(int i=0;i<(1<<a);i++)for(int j=0;j<130;j++)dp[i][j]=-mod;
	dp[0][0]=0;
	int rn=0;
	for(int i=0;i<a;i++)if(in[i]=='R')rn++;
	for(int i=0;i<(1<<a);i++){
		int R=0;
		int B=0;
		for(int j=0;j<a;j++){
			if(i&(1<<j)){
				if(in[j]=='R')R++;
				else B++;
			}
		}
//		printf("%d: %d %d\n",i,R,B);
		for(int j=0;j<130;j++){
			if(dp[i][j]<0)continue;
			//printf("%d %d: %d\n",i,j,dp[i][j]);
			for(int k=0;k<a;k++){
				if(i&(1<<k))continue;
				dp[i+(1<<k)][j+min(R,p[k])]=max(dp[i+(1<<k)][j+min(R,p[k])],dp[i][j]+min(B,q[k]));
			}
		}
	}
	int rsum=0;
	int bsum=0;
	for(int i=0;i<a;i++){
		rsum+=p[i];
		bsum+=q[i];
	}
	int ret=mod*2;
	for(int i=0;i<130;i++)ret=min(ret,max(rsum-i,bsum-dp[(1<<a)-1][i]));
	printf("%d\n",ret+a);
}