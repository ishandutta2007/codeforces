#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
LL x,y;
LL ans1[100000];
int ans2[100000];
int num;
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}
void calc(LL x,LL y) 
{
	if (x%y==0)
	{
		ans1[++num]=(x-y)/y;
		ans2[num]=1;
		return;
	}
	if (y%x==0)
	{
		ans1[++num]=(y-x)/x;
		ans2[num]=2;
		return;
	}
	if (x>y)
	{
		ans1[++num]=x/y;
		ans2[num]=1;
		calc(x%y,y);
	}
	else
	{
		ans1[++num]=y/x;
		ans2[num]=2;
		calc(x,y%x);
	}
}
int main()
{
	cin>>x>>y;
	if (gcd(x,y)!=1) { printf("Impossible\n");return 0;}
	calc(x,y);
	for (int i=1;i<=num;i++)
		printf("%I64d%c",ans1[i],ans2[i]+64);
	return 0;
}