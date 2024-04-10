#include<cstdio>
#include<iostream>
int main()
{
	long long a,b;
	long long mo=1000000007;
	long long inv=(mo+1)/2;
	scanf("%I64d%I64d",&a,&b);
	long long ans=(a*b+b+2)%mo*a%mo*b%mo*(b-1)%mo*inv%mo*inv%mo;
	printf("%I64d\n",ans);
}