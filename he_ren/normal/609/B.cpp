#include<cstdio>
typedef long long ll;
const int MAXM = 10 + 5;

int cnt[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		++cnt[x];
	}
	
	int ans=0;
	for(int i=1; i<=m; ++i)
		for(int j=1; j<i; ++j)
		{
			ans += cnt[i]*cnt[j];
		}
	
	printf("%d",ans);
	return 0;
}