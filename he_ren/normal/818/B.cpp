#include<cstdio>
const int MAXN = 100 + 5;
const int MAXM = 100 + 5;

int l[MAXM],a[MAXN];
int has[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i) scanf("%d",&l[i]), --l[i];
	
	for(int i=1; i<m; ++i)
	{
		int x=(l[i+1]-l[i]+n)%n;
		if(!x) x=n;
		
		if(a[l[i]]!=x && (a[l[i]] || has[x]))
		{
			printf("-1");
			return 0;
		}
		
		a[l[i]] = x;
		has[x] = 1;
	}
	
	for(int i=0; i<n; ++i)
	{
		if(a[i]) printf("%d ",a[i]);
		else
		{
			for(int j=1; j<=n; ++j)
			{
				if(!has[j])
				{
					printf("%d ",j);
					has[j]=1;
					break;
				}
			}
		}
	}
	return 0;
}