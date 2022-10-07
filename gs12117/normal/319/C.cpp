#include<stdio.h>
int n;
long long int a[100100];
long long int b[100100];
long long int ans;
long long int dp[100100];
int deq[100100];
int qs,qe;
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%I64d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%I64d",&b[i]);
	}
	qs=qe=0;
	for(i=0;i<n;i++){
		if(a[i]==1)dp[i]=0;
		else{
			while(qe>qs+1&&dp[deq[qs]]+b[deq[qs]]*a[i]>dp[deq[qs+1]]+b[deq[qs+1]]*a[i])qs++;
			dp[i]=dp[deq[qs]]+b[deq[qs]]*a[i];
		}
		while(qe>qs+1&&(dp[deq[qe-1]]-dp[deq[qe-2]])/((long double)b[deq[qe-1]]-b[deq[qe-2]])<(dp[i]-dp[deq[qe-2]])/((long double)b[i]-b[deq[qe-2]]))qe--;
		deq[qe]=i;
		qe++;
	}
	printf("%I64d",dp[n-1]);
}