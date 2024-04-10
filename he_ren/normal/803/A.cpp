#include<cstdio>
const int MAXN = 100 + 5;

int ans[MAXN][MAXN];

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(k>n*n)
	{
		printf("-1");
		return 0;
	}
	
	if(k&1)
	{
		ans[1][1]=1;
		--k;
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j) if(!ans[i][j])
		{
			if(k<=1) break;
			if(i==j) ans[i][i]=ans[i+1][i+1]=1;
			else ans[i][j]=ans[j][i]=1;
			k-=2;
		}
		if(k<=1) break;
	}
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j) printf("%d ",ans[i][j]);
		putchar('\n');
	}
	return 0;
}