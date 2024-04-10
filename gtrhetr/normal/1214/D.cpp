#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod1 998244353
#define mod2 1000000007

ll *f1[1000010],*f2[1000010],*g1[1000010],*g2[1000010];
int *a[1000010],n,m;
char s[1000010];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) a[i]=new int[m+2];
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) a[i][j]=(s[j]=='.');
	}
	for (int i=1;i<=n;i++) f1[i]=new ll[m+2],f2[i]=new ll[m+2],g1[i]=new ll[m+2],g2[i]=new ll[m+2];
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) f1[i][j]=f2[i][j]=g1[i][j]=g2[i][j]=0;
	f1[1][1]=f2[1][1]=1;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (a[i][j])
	{
		if (i>1) f1[i][j]+=f1[i-1][j],f2[i][j]+=f2[i-1][j];
		if (j>1) f1[i][j]+=f1[i][j-1],f2[i][j]+=f2[i][j-1];
		if (f1[i][j]>=mod1) f1[i][j]-=mod1;
		if (f2[i][j]>=mod2) f2[i][j]-=mod2;
	}
	if (!f1[n][m]&&!f2[n][m]) { puts("0");return 0; }
	g1[n][m]=g2[n][m]=1;
	for (int i=n;i;i--) for (int j=m;j;j--) if (a[i][j])
	{
		if (i<n) g1[i][j]+=g1[i+1][j],g2[i][j]+=g2[i+1][j];
		if (j<m) g1[i][j]+=g1[i][j+1],g2[i][j]+=g2[i][j+1];
		if (g1[i][j]>=mod1) g1[i][j]-=mod1;
		if (g2[i][j]>=mod2) g2[i][j]-=mod2;
	}
	bool flag=false;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
	{
		if (i==1&&j==1) continue;
		if (i==n&&j==m) continue;
		if (a[i][j]&&f1[i][j]*g1[i][j]%mod1==f1[n][m]&&f2[i][j]*g2[i][j]%mod2==f2[n][m]) flag=true;
	}
	if (flag) puts("1");
	else puts("2");
	return 0;
}