#include<bits/stdc++.h>
using namespace std;
int dp[1000001][4][4];int sum[1000001];
int main(){
	int n,m;
	int temp;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) {
	scanf("%d",&temp);
	sum[temp]++;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<3;j++)//i i+1 i+2
			for(int k=0;k<3;k++)//i-1 i i+1
				for(int l=0;l<3;l++)//i-2 i-1 i
					{
						if(sum[i]<j+k+l) continue;
						dp[i][k][l]=max(dp[i][k][l],dp[i-1][j][k]+(sum[i]-j-k-l)/3+l);
					}
	}
	printf("%d\n",dp[m][0][0]);
	return 0;
}