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
int x[5100];
long long dp[2][10100];
int A[5100];
int B[5100];
int C[5100];
int D[5100];

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	b--;c--;
	for(int i=0;i<a;i++)scanf("%d",x+i);
	x[a]=mod;
	for(int i=0;i<a;i++)scanf("%d",A+i);
	for(int i=0;i<a;i++)scanf("%d",B+i);
	for(int i=0;i<a;i++)scanf("%d",C+i);
	for(int i=0;i<a;i++)scanf("%d",D+i);
	for(int i=0;i<2;i++)for(int j=0;j<10100;j++)dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=0;i<a;i++){
		int t=i%2;
		for(int j=0;j<10100;j++)dp[!t][j]=inf;
		for(int j=0;j<a*2;j++){
			if(dp[t][j]==inf)continue;
			if(i==b){
				if(j>1||(j==1&&i==a-1))dp[!t][j-1]=min(dp[!t][j-1],dp[t][j]+(long long)(j-1)*(x[i+1]-x[i])+C[i]);
				dp[!t][j+1]=min(dp[!t][j+1],dp[t][j]+(long long)(j+1)*(x[i+1]-x[i])+D[i]);
			}else if(i==c){
				if(j>1||(j==1&&i==a-1))dp[!t][j-1]=min(dp[!t][j-1],dp[t][j]+(long long)(j-1)*(x[i+1]-x[i])+A[i]);
				dp[!t][j+1]=min(dp[!t][j+1],dp[t][j]+(long long)(j+1)*(x[i+1]-x[i])+B[i]);
			}else{
				dp[!t][j+2]=min(dp[!t][j+2],dp[t][j]+(long long)(j+2)*(x[i+1]-x[i])+B[i]+D[i]);
				if(j>1)dp[!t][j]=min(dp[!t][j],dp[t][j]+(long long)j*(x[i+1]-x[i])+min(B[i]+C[i],A[i]+D[i]));
				else if(j==1){
					if(b<i)dp[!t][j]=min(dp[!t][j],dp[t][j]+(long long)j*(x[i+1]-x[i])+A[i]+D[i]);
					else dp[!t][j]=min(dp[!t][j],dp[t][j]+(long long)j*(x[i+1]-x[i])+C[i]+B[i]);
				}
				if(j>2||(j==2&&i==a-1))dp[!t][j-2]=min(dp[!t][j-2],dp[t][j]+(long long)(j-2)*(x[i+1]-x[i])+A[i]+C[i]);
			}
		}
	}
	printf("%I64d\n",dp[a%2][0]);
}