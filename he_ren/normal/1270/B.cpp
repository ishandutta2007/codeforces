#include<cstdio>
const int MAXN = 2e5 + 5;
const int inf = 1e9 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<n; ++i)
		if(a[i]-a[i+1]>=2 || a[i+1]-a[i]>=2)
		{
			printf("YES\n%d %d\n",i,i+1);
			return;
		}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}