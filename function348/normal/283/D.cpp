#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=5010;
int n;
int a[N],f[N];LL b[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		LL x;
		scanf("%lld",&x);
		while (x%2==0) x/=2,a[i]++;
		b[i]=x;
	}
	int ans=n;
	for (int i=1;i<=n;i++)
	{
		f[i]=1;
		for (int j=1;j<i;j++)
		if ((a[i]<=i-j-1||a[i]-a[j]==i-j)&&b[j]%b[i]==0) f[i]=max(f[i],f[j]+1);
		ans=min(ans,n-f[i]);
	}
	printf("%d\n",ans);
	return 0;
}