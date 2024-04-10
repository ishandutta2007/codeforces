#include<cstdio>
const int MAXN = 1e3 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans=0;
	for(int i=2; i<n; ++i)
		if((a[i]<a[i-1] && a[i]<a[i+1]) || (a[i]>a[i-1] && a[i]>a[i+1]))
			++ans;
	printf("%d",ans);
	return 0;
}