#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int tmp=abs(x-y);
		int now=0,val=0;
		while(val<tmp || ((val-tmp)%2))
		{
			now++;
			val+=now;
		}
		printf("%d\n",now);
	}
}