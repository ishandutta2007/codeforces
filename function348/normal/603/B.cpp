#include<cstdio>
#include<iostream>
using namespace std;
const int mo=1000000007;
int p,k;
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
	scanf("%d%d",&p,&k);
	if (k==0) { printf("%d\n",exp(p,p-1,mo));return 0;}
	if (k==1) { printf("%d\n",exp(p,p  ,mo));return 0;}
	int cnt=1,q=k;
	while (q!=1)
	{
		cnt++;q=1LL*q*k%p;
	}
	printf("%d\n",exp(p,(p-1)/cnt,mo));
	return 0;
}