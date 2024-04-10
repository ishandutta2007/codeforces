#include<cstdio>
const int MAXN = 100 + 5;
const int MAXT = 200 + 5;

int a[MAXN],b[MAXN];
int t[MAXT*2];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]), t[a[i]]=1;
	
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i)
		scanf("%d",&b[i]), t[b[i]]=1;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)	
			if(!t[a[i]+b[j]])
			{
				printf("%d %d\n",a[i],b[j]);
				return 0;
			}
	return 0;
}