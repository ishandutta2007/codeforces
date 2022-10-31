#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int b[110];
int dp[110][3];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	for(int i=0;i<110;i++)for(int j=0;j<3;j++)dp[i][j]=mod;
	dp[0][0]=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<3;j++){
			if(b[i]/2&&j!=1){
				dp[i+1][1]=min(dp[i+1][1],dp[i][j]);
			}
			if(b[i]%2&&j!=2){
				dp[i+1][2]=min(dp[i+1][2],dp[i][j]);
			}
			dp[i+1][0]=min(dp[i+1][0],dp[i][j]+1);
		}
	}
	int ret=mod;
	for(int i=0;i<3;i++)ret=min(ret,dp[a][i]);
		printf("%d\n",ret);
}