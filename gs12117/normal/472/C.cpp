#include<stdio.h>
#include<string.h>
int n;
char a[100100][2][55];
int b[100100];
int dp[100100][2];
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s%s",a[i][0],a[i][1]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		b[i]--;
	}
	dp[0][0]=1;
	dp[0][1]=1;
	for(i=0;i<n-1;i++){
		if(dp[i][0]==1&&strcmp(a[b[i]][0],a[b[i+1]][0])<=0){
			dp[i+1][0]=1;
		}
		if(dp[i][0]==1&&strcmp(a[b[i]][0],a[b[i+1]][1])<=0){
			dp[i+1][1]=1;
		}
		if(dp[i][1]==1&&strcmp(a[b[i]][1],a[b[i+1]][0])<=0){
			dp[i+1][0]=1;
		}
		if(dp[i][1]==1&&strcmp(a[b[i]][1],a[b[i+1]][1])<=0){
			dp[i+1][1]=1;
		}
	}
	if(dp[n-1][0]==1||dp[n-1][1]==1){
		printf("YES");
	}
	else printf("NO");
}