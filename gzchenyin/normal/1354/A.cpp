#include<cstdio>
#include<algorithm>
using namespace std;
long long t,a,b,c,d;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(b>=a) 
		{
			printf("%lld\n",b);
			continue;
		}
		a-=b;
		if(c<=d) 
		{
			printf("-1\n");
			continue;
		}
		printf("%lld\n",b+((a-1)/(c-d)+1)*c);
	}
}