#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m,a[35][35],s0[100],s1[100];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+m;i++)
		{
			s0[i]=s1[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]==0) s0[i+j-1]++;
				else s1[i+j-1]++;
			}
		}
		for(int i=1;i<=(n+m-1)/2;i++)
		{
			ans+=min(s0[i]+s0[n+m-i],s1[i]+s1[n+m-i]);
		}
		printf("%d\n",ans);
	}
}