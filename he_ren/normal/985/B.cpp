#include<cstdio>
const int MAXN = 2e3 + 5;
const int MAXM = 2e3 + 5;

char a[MAXN][MAXM];
int s[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",a[i]+1);
		for(int j=1; j<=m; ++j)
		{
			a[i][j]-='0';
			if(a[i][j]) ++s[j];
		}
	}
	
	for(int i=1; i<=n; ++i)
	{
		bool flag=1;
		for(int j=1; j<=m; ++j)
			if(a[i][j] && s[j]==1)
			{
				flag=0;
				break;
			}
		if(flag)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}