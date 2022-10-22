#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		bool flag;
		int n,k1,k2;
		scanf("%d%d%d",&n,&k1,&k2);
		for(int i=1;i<=k1;i++)
		{
			int x;
			scanf("%d",&x);
			if(x==n) flag=true;
		}
		for(int i=1;i<=k2;i++)
		{
			int x;
			scanf("%d",&x);
			if(x==n) flag=false;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
}