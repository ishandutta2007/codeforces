#include<cstdio>
#include<algorithm>
using namespace std;
int t,x1,x2,y1,y2;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		long long x=x2-x1,y=y2-y1;
		if(x>y)
		{
			long long t=x;
			x=y;
			y=t;
		}
		printf("%lld\n",x*x+x*(y-x)+1);
	}
}