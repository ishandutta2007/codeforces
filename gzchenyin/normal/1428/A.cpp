#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,a,b,c,d;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		scanf("%d%d%d%d",&a,&c,&b,&d);
		if(a!=b&&c!=d) ans+=2;
		printf("%d\n",ans+abs(a-b)+abs(c-d));
	}
}