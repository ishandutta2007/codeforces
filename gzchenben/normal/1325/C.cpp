#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,siz[200005],u[200005],v[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		siz[u[i]]++;
		siz[v[i]]++;
	}
	int mx=0,now=3;
	for(int i=1;i<=n;i++)
	{
		if(siz[i]>=3) mx=i;
	}
	if(!mx)
	{
		for(int i=1;i<=n-1;i++) printf("%d\n",i-1);
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		if((u[i]==mx || v[i]==mx) && now!=i-1)
		{
			printf("%d\n",-(now-i-2));
		}
		else
		{
			printf("%d\n",now);
			now++;
		}
	}
	return 0;
}