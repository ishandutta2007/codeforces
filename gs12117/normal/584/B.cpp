#include<stdio.h>
int n;
long long int p,q;
int mod=1000000007;
int main(){
	int i;
	scanf("%d",&n);
	p=1;
	q=1;
	for(i=0;i<n;i++){
		p*=27;
		p%=mod;
		q*=7;
		q%=mod;
	}
	printf("%I64d",(mod+p-q)%mod);
}