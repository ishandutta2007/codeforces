#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[200005],b[200005],ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			b[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[a[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			while(b[i]>=i)
			{
				b[i]-=i;
				ans++;
			}
			b[i+1]+=b[i];
		}
		printf("%d\n",ans);
	}
}