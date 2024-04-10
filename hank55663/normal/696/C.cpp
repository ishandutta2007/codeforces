#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
long long int f_pow(long long int a,long long int b){
	long long int temp=a,res=1;
	while(b){
		if(b&1)res*=temp;
		temp*=temp;
		temp%=mod;
		res%=mod;
		b/=2;
	}
	return res;
}
main(){
	int k;
	scanf("%d",&k);
	long long int sum=2;
	int odd=1;
	long long int tin=f_pow(2,1e9+5);
	long long int trin=f_pow(3,1e9+5);
	for(int i=0;i<k;i++){
		long long int a;
		scanf("%I64d",&a);
		if(a%2==0)
		odd=0;
		sum=f_pow(sum,a)%mod;
	}
	sum=sum*tin%mod;
	if(!odd){
		printf("%I64d/%I64d",((sum+1)*trin)%mod,sum);
	}
	else
	printf("%I64d/%I64d",((sum-1)*trin)%mod,sum);
}