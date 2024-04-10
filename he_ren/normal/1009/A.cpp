#include<cstdio>
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;

int c[MAXN],a[MAXM];
bool del[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&a[i]);
	
	int ans=0;
	for(int i=1,j=1; i<=n && j<=m; ++i)
		if(c[i]<=a[j])
		{
			++j;
			++ans;
		}
	printf("%d",ans);
	return 0;
}