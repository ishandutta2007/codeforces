#include<cstdio>
#include<iostream>
using namespace std;
const int mo=1000000009;
int n,m,k;
int exp(int a,int b)
{
	int d=1;
	while (b)
	{
		if (b&1) d=1LL*d*a%mo;
		b>>=1;a=1LL*a*a%mo;
	}
	return d;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int p=n-n/k;
	if (m<=p) { printf("%d\n",m);return 0;}
	int x=exp(2,m-p);
	int now=(2LL*x-2)*k%mo;
	now=(now+m-(m-p)*k)%mo;
	now=(now+mo)%mo;
	printf("%d\n",now);
	return 0;
}