#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[1005];
int t,sum0[1005],sum1[1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a+1);
		int n=strlen(a+1);
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			sum0[i]=sum0[i-1]+1-(a[i]-'0');
			sum1[i]=sum1[i-1]+(a[i]-'0');
		}
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,sum0[i]+(sum1[n]-sum1[i]));
			ans=min(ans,sum1[i]+(sum0[n]-sum0[i])); 
		}
		ans=min(ans,min(sum0[n],sum1[n]));
		printf("%d\n",ans);
	}
}