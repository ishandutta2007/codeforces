#include<stdio.h>
int n;
double prob[110];
double dp[110];
double ans;
int main(){
	int i,j,t;
	double tres;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf",&prob[i]);
		prob[i]/=100;
		dp[i]=1;
	}
	for(i=0;i<1000000;i++){
		t=0;
		for(j=1;j<n;j++){
			if(dp[j]*prob[j]*(1-dp[t])>dp[t]*prob[t]*(1-dp[j]))t=j;
		}
		tres=1;
		for(j=0;j<n;j++){
			if(j==t)continue;
			tres*=1-dp[j];
		}
		ans+=(i+1)*tres*dp[t]*prob[t];
		dp[t]*=(1-prob[t]);
	}
	printf("%.20lf",ans);
}