#include<stdio.h>
int n;
int a[100100];
long long int ans;
long long int sum;
int mod=1000000007;
long long int mpw(long long int x,long long int y){
	if(y==0)return 1;
	long long int tmp=mpw(x,y/2);
	tmp*=tmp;
	tmp%=mod;
	if(y%2==0)return tmp;
	tmp*=x;
	return tmp%mod;
}
long long int inv(long long int x){
	return mpw(x,mod-2);
}
long long int fact(long long int x){
	int i;
	long long int res=1;
	for(i=1;i<=x;i++){
		res*=i;
		res%=mod;
	}
	return res;
}
int main(){
	int i;
	scanf("%d",&n);
	ans=1;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		ans*=inv(fact(sum));
		ans%=mod;
		sum+=a[i];
		ans*=inv(fact(a[i]-1));
		ans%=mod;
		ans*=fact(sum-1);
		ans%=mod;
	}
	printf("%I64d",ans);
}