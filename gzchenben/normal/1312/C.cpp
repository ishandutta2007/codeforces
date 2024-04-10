#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,k,cnt[105];
long long a[35];
bool vis[1005];
void add(long long x)
{
	int now=1;
	while(x)
	{
		cnt[now]+=x%k;
		x/=k;
		cnt[x];
		now++;
	}
}
bool check()
{
	for(int i=1;i<=100;i++)
	{
		if(cnt[i]>1) return false;
	}
	return true;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			add(a[i]);
		}
//		for(int i=1;i<=10;i++) printf("%d %d\n",i,cnt[i]);
		if(check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}