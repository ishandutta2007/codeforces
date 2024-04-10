#include<cstdio>
const int MAXN = 1e2 + 5;
const int MAXM = 1e2 + 5;

int a[MAXN],b[MAXM];
int c[MAXN][MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]), c[i][1]=a[i];
	for(int i=1; i<=m; ++i)
		scanf("%d",&b[i]), c[1][i]=b[i];
	
	for(int i=2; i<=m; ++i) a[1]^=b[i];
	for(int i=2; i<=n; ++i) b[1]^=a[i];
	if(a[1]!=b[1])
	{
		printf("NO");
		return 0;
	}
	c[1][1]=a[1];
	printf("YES\n");
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
			printf("%d ",c[i][j]);
		putchar('\n');
	}
	return 0;
}