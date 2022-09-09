#include<cstdio>
const int MAXN = 2e5 + 5;

int a[MAXN],lst[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i)
	{
		if(a[i]!=a[i-1]) lst[i]=i-1;
		else lst[i]=lst[i-1];
	}
	
	while(m--)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		if(a[r]!=x) printf("%d\n",r);
		else
		{
			if(lst[r]>=l) printf("%d\n",lst[r]);
			else printf("-1\n");
		}
	}
	return 0;
}