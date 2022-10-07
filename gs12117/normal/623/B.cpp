#include<stdio.h>
int n,a,b;
int p[1001000];
long long int ans;
long long int minf=1e17;
long long int dp[1001000];
long long int f(int v,int start,int end){
	int i,j;
	long long int res,t;
	dp[start]=0;
	for(i=start;i<end;i++){
		if(p[i]%v==0)dp[i+1]=dp[i];
		else if(p[i]%v==1||p[i]%v==v-1)dp[i+1]=dp[i]+b;
		else dp[i+1]=minf;
	}
	for(i=start;i<end;i++){
		if(dp[i+1]>dp[i]+a)dp[i+1]=dp[i]+a;
	}
	res=minf;
	t=0;
	for(i=end;i>=start;i--){
		if(t+dp[i]<res)res=t+dp[i];
		if(i!=start){
			if(p[i-1]%v==0)t=t;
			else if(p[i-1]%v==1||p[i-1]%v==v-1)t=t+b;
			else t=minf;
		}
	}
	return res;
}
int main(){
	int i,j,t;
	long long int resf;
	scanf("%d%d%d",&n,&a,&b);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	ans=minf;
	t=p[0];
	for(i=2;i*i<=t;i++){
		if(t%i==0){
			while(t%i==0)t/=i;
			resf=f(i,1,n);
			if(ans>resf)ans=resf;
		}
	}
	if(t!=1){
		resf=f(t,1,n);
		if(ans>resf)ans=resf;
	}
	t=p[0]+1;
	for(i=2;i*i<=t;i++){
		if(t%i==0){
			while(t%i==0)t/=i;
			resf=b+f(i,1,n);
			if(ans>resf)ans=resf;
		}
	}
	if(t!=1){
		resf=b+f(t,1,n);
		if(ans>resf)ans=resf;
	}
	t=p[0]-1;
	for(i=2;i*i<=t;i++){
		if(t%i==0){
			while(t%i==0)t/=i;
			resf=b+f(i,1,n);
			if(ans>resf)ans=resf;
		}
	}
	if(t!=1){
		resf=b+f(t,1,n);
		if(ans>resf)ans=resf;
	}
	t=p[n-1];
	for(i=2;i*i<=t;i++){
		if(t%i==0){
			while(t%i==0)t/=i;
			resf=f(i,0,n-1);
			if(ans>resf)ans=resf;
		}
	}
	if(t!=1){
		resf=f(t,0,n-1);
		if(ans>resf)ans=resf;
	}
	t=p[n-1]+1;
	for(i=2;i*i<=t;i++){
		if(t%i==0){
			while(t%i==0)t/=i;
			resf=b+f(i,0,n-1);
			if(ans>resf)ans=resf;
		}
	}
	if(t!=1){
		resf=b+f(t,0,n-1);
		if(ans>resf)ans=resf;
	}
	t=p[n-1]-1;
	for(i=2;i*i<=t;i++){
		if(t%i==0){
			while(t%i==0)t/=i;
			resf=b+f(i,0,n-1);
			if(ans>resf)ans=resf;
		}
	}
	if(t!=1){
		resf=b+f(t,0,n-1);
		if(ans>resf)ans=resf;
	}
	printf("%I64d",ans);
	return 0;
}