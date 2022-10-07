#include<stdio.h>
int primes[20];
int pd[63];
int pn;
int dp[110][1<<17];
int dpb[110][1<<17];
int n;
int a[110];
int dn[63];
int d[63][1<<17];
int ans[110];
int main(){
	int i,j,k,t;
	for(i=2;i<60;i++){
		for(j=2;j<i;j++){
			if(i%j==0)break;
		}
		if(j==i){
			primes[pn]=i;
			pn++;
		}
	}
	for(i=1;i<60;i++){
		for(j=0;j<pn;j++){
			if(i%primes[j]==0){
				pd[i]+=(1<<j);
			}
		}
	}
	for(j=1;j<60;j++){
		for(k=0;k<(1<<pn);k++){
			if((pd[j]&k)==0){
				d[j][dn[j]]=k;
				dn[j]++;
			}
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<(1<<pn);j++){
			dp[i+1][j]=999999999;
		}
		for(j=1;j<60;j++){
			if(j>a[i])t=j-a[i];
			else t=a[i]-j;
			for(k=0;k<dn[j];k++){
				if(dp[i+1][d[j][k]+pd[j]]>dp[i][d[j][k]]+t){
					dp[i+1][d[j][k]+pd[j]]=dp[i][d[j][k]]+t;
					dpb[i+1][d[j][k]+pd[j]]=j;
				}
			}
		}
	}
	j=(1<<pn)-1;
	for(i=n;i>0;i--){
		ans[i-1]=dpb[i][j];
		j-=pd[dpb[i][j]];
	}
	for(i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
}