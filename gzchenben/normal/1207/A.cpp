#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,t,a,b,c;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		scanf("%d%d%d%d%d",&a,&b,&c,&n,&m);
		for(int i=0;i<=b;i++)
		{
			for(int j=0;j<=c;j++)
			{
				if(2*i+2*j<=a) ans=max(ans,i*n+j*m);
			}
		}
		printf("%d\n",ans);
	}
}