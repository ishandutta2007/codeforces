#include<cstdio>
#include<iostream>
using namespace std;
const int N=2010;
int n,ans;
int a[N],g[N],h[N],f[N][N],s[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]+(a[i]==1);
	for (int i=1;i<=n;i++) f[i][i]=1;
	for (int i=2;i<=n;i++)
	for (int j=1;i+j-1<=n;j++)
	if (a[j]==2) f[j][i+j-1]=f[j+1][i+j-1]+1;
	else f[j][i+j-1]=max(f[j+1][i+j-1],s[i+j-1]-s[j-1]);
	ans=max(n-s[n],s[n]);
	for (int i=1;i<=n;i++) if (a[i]==2) g[i]=g[i-1]+1;else g[i]=max(g[i-1],s[i]);
	for (int i=n;i>=1;i--) if (a[i]==1) h[i]=h[i+1]+1;else h[i]=max(h[i+1],n-i+1-(s[n]-s[i-1]));
	for (int i=1;i<=n;i++)
	for (int j=1;i+j-1<=n;j++)
	{
		ans=max(ans,g[j-1]+(n-j+1-(s[n]-s[j-1])));
		ans=max(ans,s[j-1]+f[j][i+j-1]+(n-(i+j-1)-(s[n]-s[i+j-1])));
		ans=max(ans,s[i+j-1]+h[i+j]);
	}
	printf("%d\n",ans);
	return 0;
}