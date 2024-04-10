#include<cstdio>
const int MAXD = 100 + 5;

int p[MAXD];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=d; ++i) scanf("%d",&p[i]);
	
	int ans=0;
	while(n--)
	{
		for(int i=1; i<=m; ++i)
		{
			int x;
			scanf("%d",&x);
			for(int j=1; j<=d; ++j) if(p[j]==x)
			{
				ans+=j;
				for(int k=j; k>=2; --k) p[k]=p[k-1];
				p[1]=x;
				break;
			}
		}	
	}
	printf("%d\n",ans);
	return 0;
}