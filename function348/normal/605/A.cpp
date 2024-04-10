#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n;
int a[N],f[N],id[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		id[a[i]]=i;
	}
	f[1]=1;
	for (int i=2;i<=n;i++)
	if (id[i-1]<id[i]) f[i]=f[i-1]+1;else f[i]=1;
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,f[i]);
	printf("%d\n",n-ans);
	return 0;
}