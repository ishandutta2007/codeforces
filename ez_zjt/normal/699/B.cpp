#include <cstdio>
#include <cstring>
#define MAXN 1010

int n,m;
int a[MAXN][MAXN];

int sum(int x1,int y1,int x2,int y2)
{
	if(x2<x1) return 0;
	if(y2<y1) return 0;
	return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
}

int main()
{
	memset(a,0,sizeof a);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		static char str[MAXN];
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)
			if(str[j]=='*')
				a[i][j]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(sum(1,1,i-1,j-1)==0 && sum(i+1,1,n,j-1)==0 && sum(1,j+1,i-1,m)==0 && sum(i+1,j+1,n,m)==0)
			{
				printf("YES\n%d %d\n",i,j);
				return 0;
			}
	printf("NO\n");
}