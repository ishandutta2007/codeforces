#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,r;
		scanf("%d%d%d%d",&a,&b,&c,&r);
		if(a>b) swap(a,b);
		int tmp=max(0,min(c+r,b)-max(c-r,a));
		printf("%d\n",b-a-tmp);
	}
	return 0;
}