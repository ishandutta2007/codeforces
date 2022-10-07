#include<stdio.h>
int n;
int maxit=1001000;
int a[101000];
long long int dp[1001000];
long long int it[1<<23];
int mod=1000000007;
long long int calc(int x){
	x+=7;
	int i;
	long long ans=0;
	for(i=0;i<22;i++){
		if(x&(1<<i)){
			ans+=it[x];
			x-=(1<<i);
		}
	}
	return ans;
}
void push(int x,long long int y){
	x+=7;
	int i;
	for(i=0;i<22;i++){
		if(x&(1<<i)){
			it[x]+=y;
			x+=(1<<i);
		}
	}
}
int main(){
	int i;
	long long int t,p;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	push(-1,1);
	for(i=0;i<n;i++){
		t=calc(a[i]-1);
		p=calc(a[i]);
		t%=mod;
		p-=t;
		p+=mod;
		p%=mod;
		t=calc(a[i]);
		t%=mod;
		t*=a[i];
		t%=mod;
		t+=mod;
		t-=p;
		t%=mod;
		push(a[i],t);
	}
	printf("%I64d",(calc(1001000)%mod+mod-1)%mod);
}