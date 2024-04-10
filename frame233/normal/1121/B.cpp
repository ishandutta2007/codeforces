#include<cstdio>
const int N=1005;
int cnt[200005],a[N];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		for(int j=1;j<i;++j)
		{
			++cnt[a[i]+a[j]];
		}
	}
	int ans=0;
	for(int i=1;i<=200000;++i) ans=max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}