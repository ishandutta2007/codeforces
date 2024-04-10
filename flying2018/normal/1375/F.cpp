#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll a[4]={0,0,0,0};
int p=-1;
int main()
{
	scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
	puts("First");
	printf("%lld\n",10000000000ll);
	fflush(stdout);
	int c;
	scanf("%d",&c);
	a[c]+=10000000000ll;
	if(c==1)
	{
		printf("%lld\n",(a[1]-a[2])+(a[1]-a[3]));
		fflush(stdout);
		int d;
		scanf("%d",&d);
		if(d==2) printf("%lld\n",a[1]-a[3]);
		else printf("%lld\n",a[1]-a[2]);
		return 0;
	}
	if(c==2)
	{
		printf("%lld\n",(a[2]-a[1])+(a[2]-a[3]));
		fflush(stdout);
		int d;
		scanf("%d",&d);
		if(d==1) printf("%lld\n",a[2]-a[3]);
		else printf("%lld\n",a[2]-a[1]);
		return 0;
	}
	if(c==3)
	{
		printf("%lld\n",(a[3]-a[1])+(a[3]-a[2]));
		fflush(stdout);
		int d;
		scanf("%d",&d);
		if(d==2) printf("%lld\n",a[3]-a[1]);
		else printf("%lld\n",a[3]-a[2]);
		return 0;
	}
	return 0;
}