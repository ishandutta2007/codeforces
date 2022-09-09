#include<cstdio>
const int MAXN = 1e6 + 5;
const int maxw = 2e6;
const int MAXW = maxw + 5;

int t[MAXW];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int w;
		scanf("%d",&w);
		++t[w];
	}
	
	int ans=0;
	for(int i=0; i<=maxw; ++i)
	{
		ans+=t[i]&1;
		t[i+1]+=t[i]>>1;
	}
	
	printf("%d",ans);
	return 0;
}