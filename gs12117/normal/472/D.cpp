#include<stdio.h>
int n;
int a[2010][2010];
int dp[2010][2];
int chk[2010];
int main(){
	int i,j,p,d,back;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j&&a[i][j]!=0){
				printf("NO");
				return 0;
			}
			if(i!=j&&a[i][j]==0){
				printf("NO");
				return 0;
			}
			if(a[i][j]!=a[j][i]){
				printf("NO");
				return 0;
			}
		}
	}
	for(i=1;i<n;i++){
		dp[i][0]=a[0][i];
	}
	chk[0]=1;
	for(i=0;i<n-1;i++){
		p=-1;
		for(j=0;j<n;j++){
			if(chk[j]==0&&(p==-1||dp[j][0]<dp[p][0])){
				p=j;
			}
		}
		chk[p]=1;
		d=dp[p][0];
		back=dp[p][1];
		for(j=0;j<n;j++){
			if(dp[j][0]>a[p][j]){
				if(dp[j][0]!=a[p][j]+d){
					printf("NO");
					return 0;
				}
				dp[j][0]=a[p][j];
				dp[j][1]=p;
			}
			else{
				if(a[back][j]+d!=a[p][j]){
					printf("NO");
					return 0;
				}
			}
		}
	}
	printf("YES");
	return 0;
}