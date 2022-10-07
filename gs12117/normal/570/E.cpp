#include<stdio.h>
int mod=1000000007;
int dp[510][510];
int dpb[510][510];
char a[510][510];
char b[1010][510];
int n,m;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",&a[i]);
	}
	if(n<m){
		k=n;
		n=m;
		m=k;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				b[i+j][j]=a[j][i];
			}
		}
	}
	else{
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				b[i+j][j]=a[i][j];
			}
		}
	}
	if((n+m)%2==0){
		for(i=0;i<m;i++){
			dpb[i][i]=1;
		}
	}
	else{
		for(i=0;i<m;i++){
			if(b[(n+m)/2-1][i]==b[(n+m)/2][i])dpb[i][i]=1;
			if(b[(n+m)/2-1][i]==b[(n+m)/2][i+1])dpb[i][i+1]=1;
		}
	}
	for(i=(n+m)/2-1;i>0;i--){
		for(j=0;j<m;j++){
			for(k=0;k<m;k++){
				dp[j][k]=0;
				if(b[i-1][j]==b[n+m-i-1][k]){
					dp[j][k]+=dpb[j][k];
					dp[j][k]+=dpb[j+1][k];
					dp[j][k]%=mod;
					if(k!=0){
						dp[j][k]+=dpb[j][k-1];
						dp[j][k]%=mod;
						dp[j][k]+=dpb[j+1][k-1];
						dp[j][k]%=mod;
					}
				}
			}
		}
		for(j=0;j<m;j++){
			for(k=0;k<m;k++){
				dpb[j][k]=dp[j][k];
			}
		}
	}
	printf("%d",dp[0][m-1]);
}