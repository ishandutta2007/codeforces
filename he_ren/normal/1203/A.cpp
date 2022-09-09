#include<cstdio>
const int MAXN = 200 + 5;

int a[MAXN];

inline void solve(int n)
{
	for(int i=1; i<=n; ++i)
	{
		bool flag=1;
		for(int j=1; j<n; ++j)
			if(a[i+j]<a[i+j-1])
			{
				flag=0;
				break;
			}
		if(flag)
		{
			printf("YES\n");
			return;
		}
		
		flag=1;
		for(int j=1; j<n; ++j)
			if(a[i+j]>a[i+j-1])
			{
				flag=0;
				break;
			}
		if(flag)
		{
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1; i<=n; ++i)
			scanf("%d",&a[i]),
			a[n+i] = a[i];
		solve(n);
	}
	return 0;
}