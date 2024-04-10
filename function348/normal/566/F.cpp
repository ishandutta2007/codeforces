#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000010;
int n,ans;
int a[N],f[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for (int i=1000000;i>=1;i--)
	if (a[i])
	{
		f[i]=1;
		for (int j=2;i*j<=1000000;j++)
			f[i]=max(f[i],f[i*j]+1);
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}