#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
long long u,v;
long long Bit(long long x,int f)
{
	return (x>>f)%2;
}
bool check2()
{
	long long tmp=(v-u);
	for(int i=1;i<=60;i++)
	{
		if(Bit(tmp,i) && Bit(u,i-1)) return false;
	}
	long long ans1=0,ans2=0;
	for(int i=0;i<60;i++)
	{
		if(Bit(tmp,i+1))
		{
			ans1+=(1ll<<i);
			ans2+=(1ll<<i); 
		} 
		else if(Bit(u,i)) ans1+=(1ll<<i);
	}
	printf("2\n%lld %lld\n",ans1,ans2);
	return true; 
}
int main()
{
	scanf("%lld%lld",&u,&v);
	if((u%2ll)!=(v%2ll) || u>v)
	{
		printf("-1\n");
		return 0;
	}
	if(u==0ll && v==0ll)
	{
		printf("0\n");
		return 0;
	}
	if(u==v)
	{
		printf("1\n%lld\n",u);
		return 0;
	}
	if(check2())
	{
		return 0;
	}
	printf("3\n%lld %lld %lld\n",u,(v-u)/2ll,(v-u)/2ll);
}