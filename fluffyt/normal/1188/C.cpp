#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,k,ans,a[300005];
int f[1005][1005];
void add(int &x,int val)
{
	x+=val;
	if(x>=mod) x-=mod;
}
int gets(int x)
{
	for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) f[i][j]=0;
	for(int i=0;i<=n;i++) f[i][0]=1;
	int p=0;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-a[p]>=x&&p<i) p++;
		for(int j=1;j<=k;j++)
		{
			f[i][j]=f[i-1][j]+f[p-1][j-1];
			if(f[i][j]>=mod) f[i][j]-=mod;
		}
	}
	return f[n][k];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	m=a[n]-a[1];
	a[0]=-1000000;
	for(int i=1;1ll*i*(k-1)<=m;i++) add(ans,gets(i));
	printf("%d\n",ans);
	return 0;
}