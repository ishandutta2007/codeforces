#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,a[505],b[505];
long long suma,sumb;
bool able[505],pre[505];
int main()
{
	able[0]=true;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		suma+=a[i];
		sumb+=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<k;j++)
		{
			pre[j]=able[j]; 
		}
		if(a[i]+b[i]<k) continue;
		for(int j=1;j<k;j++)
		{
			if(a[i]<j || b[i]<(k-j)) continue;
			for(int t=0;t<k;t++)
			{
				if(pre[t]) able[(t+j)%k]=true;
			}
		}
	}
	long long least=(suma/k)+(sumb/k);
	if((suma%k)+(sumb%k)<k)
	{
		printf("%lld\n",least);
		return 0;
	}
	for(int i=1;i<k;i++)
	{
		if(able[i] && (suma%k)>=(i) && (sumb%k)>=(k-i))
		{
			printf("%lld\n",least+1);
			return 0;
		}
	}
	printf("%lld\n",least);
	return 0;
}