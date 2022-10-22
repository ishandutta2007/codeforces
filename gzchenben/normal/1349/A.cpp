#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n,k,a[100005],b[100005];
int cnt[200005];
long long ans=1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		for(int j=2;j*j<=a[i];j++)
		{
			if(b[i]%j==0) cnt[j]++;
			while(b[i]%j==0) b[i]/=j;
		}
		if(b[i]!=1) cnt[b[i]]++;
	}
	for(int i=1;i<=200000;i++)
	{
		if(cnt[i]<n-1) continue;
		int minn1=1e9,minn2=1e9;
		for(int j=1;j<=n;j++)
		{
			int tmp=0;
			while(a[j]%i==0)
			{
				a[j]/=i;
				tmp++;
			}
			if(tmp<minn1)
			{
				minn2=minn1;
				minn1=tmp;
			}
			else if(tmp<minn2)
			{
				minn2=tmp;
			}
		}
		if(minn2==1e9) continue;
		for(int j=1;j<=minn2;j++)
		{
			ans*=i;
		}
	}
	printf("%lld\n",ans);
}