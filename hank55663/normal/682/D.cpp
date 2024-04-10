#include<bits/stdc++.h>
using namespace std;
#define N 1005
int main(){
	int n,m,K;
	scanf("%d %d %d",&n,&m,&K);
	char s[N],t[N];
	scanf("%s",s);
	scanf("%s",t);
	int dp[N][N];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	if(s[i]==t[0])
	dp[i][0]=1;
	for(int i=0;i<m;i++)
	if(s[0]==t[i])
	dp[0][i]=1;
	for(int i=1;i<n;i++)
	for(int j=1;j<m;j++)
	if(s[i]==t[j])
	dp[i][j]=dp[i-1][j-1]+1;
	int Max[N][N];
	memset(Max,0,sizeof(Max));
	Max[0][0]=dp[0][0];
	for(int i=0;i<n;i++){
		Max[i][0]=max(Max[i-1][0],dp[i][0]);
	}
	for(int i=0;i<m;i++){
		Max[0][i]=max(Max[0][i-2],dp[0][i]);
	}
	for(int i=1;i<n;i++){ 
		for(int j=1;j<m;j++){
			Max[i][j]=max(dp[i][j],max(Max[i-1][j],Max[i][j-1]));
		}
	} 
	int ans[N][N];
	memset(ans,0,sizeof(ans));
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++){
		ans[i][j]=dp[i][j];
	}
	for(int i=2;i<=K;i++){
		for(int j=n-1;j>=0;j--)
			for(int k=m-1;k>=0;k--){
				int aa=ans[j][k];
					aa=max(aa,dp[j][k]+Max[j-dp[j][k]][k-dp[j][k]]);
				ans[j][k]=aa;
			}
		for(int i=0;i<n;i++){
			Max[i][0]=max(Max[i-1][0],ans[i][0]);
		}
		for(int i=0;i<m;i++){
			Max[0][i]=max(Max[0][i-2],ans[0][i]);
		}
		for(int i=1;i<n;i++){ 
			for(int j=1;j<m;j++){
				Max[i][j]=max(ans[i][j],max(Max[i-1][j],Max[i][j-1]));
			}
		}	 
	}
	int aaaa=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	aaaa=max(aaaa,ans[i][j]);
	printf("%d\n",aaaa);
}