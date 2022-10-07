#include<stdio.h>
int n,m;
double p[22];
double ans[22];
double dp[1<<20];
int main(){
	int i,j,k;
	double sp;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lf",&p[i]);
	}
	dp[0]=1;
	for(i=1;i<(1<<n);i++){
		sp=0;
		k=0;
		for(j=0;j<n;j++){
			if(((1<<j)&i)==0){
				sp+=p[j];
				k++;
			}
		}
		if(n-k>m)continue;
		for(j=0;j<n;j++){
			if(p[j]<0.000000001)continue;
			if(((1<<j)&i)!=0){
				dp[i]+=dp[i-(1<<j)]*p[j]/(sp+p[j]);
				ans[j]+=dp[i-(1<<j)]*p[j]/(sp+p[j]);
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%.10lf ",ans[i]);
	}
	return 0;
}