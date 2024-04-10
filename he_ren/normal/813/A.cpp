#include<cstdio>
const int MAXN = 1e3 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int s=0;
	for(int i=1; i<=n; ++i) s+=a[i];
	
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(s>=l && s<=r)
		{
			printf("%d",s);
			return 0;
		}
		if(l>=s)
		{
			printf("%d",l);
			return 0;
		}
	}
	printf("-1");
	return 0;
}