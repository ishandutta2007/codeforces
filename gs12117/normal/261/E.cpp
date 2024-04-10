#include<stdio.h>
#include<algorithm>
int m,n,p;
int a[3000000];
int dp[3000000];
int dpr[3000000];
int an;
int sumb;
int main(){
	int i,j,k;
	scanf("%d%d%d",&m,&n,&p);
	a[0]=1;
	an=1;
	for(i=2;i<=p;i++){
		for(j=2;j<i;j++){
			if(i%j==0)break;
		}
		if(j!=i)continue;
		for(j=0;j<an;j++){
			if((long long int)a[j]*i<=(long long int)n){
				a[an]=a[j]*i;
				an++;
			}
		}
	}
	std::sort(a,a+an);
	for(i=1;i<an;i++){
		dp[i]=999999999;
	}
	for(i=2;i<p;i++){
		k=0;
		for(j=0;j<an;j++){
			if(a[j]%i==0){
				if(dp[k]+1<dp[j]){
					dp[j]=dp[k]+1;
					if(i+dp[j]<=p)dpr[j]=1;
				}
				k++;
			}
		}
	}
	int ans=0;
	for(i=0;i<an;i++){
		if(a[i]>=m&&dpr[i]==1)ans++;
	}
	printf("%d",ans);
}