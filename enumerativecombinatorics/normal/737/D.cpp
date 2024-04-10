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
int b[4100];
int sum[4100];
int dp[4100][200][100];
int K=95;
int ABS(int a){
	return max(a,-a);
}
int N;
int calc(int a,int b,int c){
	//if(a<0||b+K<0||c<0)printf("dame\n");
	///if(a>=4100||b+K>=200||c>=100)printf("dame\n");
	
	if(dp[a][b+K][c]!=-mod)return dp[a][b+K][c];
	int s=a;int t=a+b;
	int L=a;
	int R=N-a-b;
	if(R-L<c){
		return dp[s][t-s+K][c]=0;
	}
	int ret=-mod;
	if(s<=t){
		if(L+c+1<=R){
			ret=max(ret,-calc(s+c+1,t-(s+c+1),c+1)+sum[L+c+1]-sum[L]);
		}
		ret=max(ret,-calc(s+c,t-s-c,c)+sum[L+c]-sum[L]);
	}else{
		if(L+c+1<=R){
			ret=max(ret,-calc(s,t+c+1-s,c+1)+sum[R]-sum[R-c-1]);
		}
		ret=max(ret,-calc(s,t+c-s,c)+sum[R]-sum[R-c]);
	}
	//if(s<0||t-s+K<0||c<0)printf("%d %d %d: %d\n",s,t-s+K,c,ret);
	return dp[s][t-s+K][c]=ret;
}
int main(){
	int a;scanf("%d",&a);
	N=a;
	for(int i=0;i<a;i++)scanf("%d",b+i);
	for(int i=0;i<a;i++)sum[i+1]=sum[i]+b[i];
	for(int i=0;i<4100;i++)for(int j=0;j<200;j++)for(int k=0;k<100;k++)
		dp[i][j][k]=-mod;
	printf("%d\n",calc(0,0,1));
}