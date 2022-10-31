#include<cstdio>
int a[105],b[105],maxx[105];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	int n,m,k,x;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&b[i]);
		maxx[b[i]]=max(maxx[b[i]],a[i]);
	}
	int ans=0;
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&x);
		if(a[x]!=maxx[b[x]])
		{
			++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}