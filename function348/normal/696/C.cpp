#include<cstdio>
#include<iostream>
typedef long long LL;
using namespace std;
const int p=1000000007;
int k,now,inv;
int exp(int a,int b,int c) 
{
	int d=1;
	while (b)
	{
		if (b&1) d=1LL*d*a%c;
		b>>=1;a=1LL*a*a%c;
	}
	return d;
}
int main()
{
	scanf("%d",&k);
	int f=0;
	now=1;
	for (int i=1;i<=k;i++)
	{
		LL x;
		scanf("%lld",&x);
		if (x%2==0) f=1;
		now=1LL*now*(x%(p-1))%(p-1);
	}
	if (now==0) now=p-1;
	int a,b;
	inv=(p+1)/3;
	if (f) a=1LL*(exp(2,now-1,p)+1)*inv%p;
	else a=1LL*(exp(2,now-1,p)-1)*inv%p;
	b=exp(2,now-1,p);
	printf("%d/%d\n",a,b);
	return 0;
}