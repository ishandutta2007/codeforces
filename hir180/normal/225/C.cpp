#include<cstdio>
#include<algorithm>
using namespace std;
int q[1000];
int dp[1001][1001][2];
int main(){
	/*(^(^(^(^o^)^)^)^) ('') */
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char w;
			scanf(" %c",&w);
			if(w=='#'){
				q[j]++;}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=1;j<=min(y,i+1)&&i+1>=j;j++){
			dp[i+1][j][0]=dp[i][j-1][0]+n-q[i];
			dp[i+1][j][1]=dp[i][j-1][1]+q[i];
		}
		dp[i+1][0][0]=100000000;
		dp[i+1][0][1]=100000000;
		for(int j=x;j<=min(y,i+1);j++){
			dp[i+1][0][0]=min(dp[i+1][0][0],dp[i+1][j][1]);
			dp[i+1][0][1]=min(dp[i+1][0][1],dp[i+1][j][0]);
		}
	}
	int sum=100000000;
	for(int i=x;i<=min(y,m);i++){
		sum=min(sum,dp[m][i][0]);
		sum=min(sum,dp[m][i][1]);
	}
	printf("%d\n",sum);
return 0;
}