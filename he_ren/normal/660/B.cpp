#include<cstdio>
const int MAXN = 100 + 5;

int n;
int a[MAXN][5];

inline void solve(int x)
{
	for(int i=1; i<=n; ++i)
	{
		if(!a[i][1])
		{
			a[i][1]=x;
			return;
		}
		if(!a[i][4])
		{
			a[i][4]=x;
			return;
		}
	}
	for(int i=1; i<=n; ++i)
	{
		if(!a[i][2])
		{
			a[i][2]=x;
			return;
		}
		if(!a[i][3])
		{
			a[i][3]=x;
			return;
		}
	}
}

int main(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
		solve(i);
	
	for(int i=1; i<=n; ++i)
	{
		if(a[i][2]) printf("%d ",a[i][2]);
		if(a[i][1]) printf("%d ",a[i][1]);
		if(a[i][3]) printf("%d ",a[i][3]);
		if(a[i][4]) printf("%d ",a[i][4]);
	}
	return 0;
}