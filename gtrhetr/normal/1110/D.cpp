#include<bits/stdc++.h>
using namespace std;

int f[1000010][3][3];
int num[1000010],cnt[1000010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=n;i++) cnt[num[i]]++;
	if (m<=2)
	{
		int ans=0;
		for (int i=1;i<=m;i++) ans+=cnt[i]/3;
		printf("%d\n",ans);
		return 0;
	}
	for (int i=3;i<=m;i++)
	{
		for (int j=0;j<3;j++) for (int k=0;k<3;k++) for (int l=0;l<3;l++)
		{
			if (i==3&&j) continue;
			if (i==3&&k) continue;
			if (i==4&&j) continue;
			if (j+k+l>cnt[i-2]) continue;
			if (k+l>cnt[i-1]) continue;
			if (l>cnt[i]) continue;
			f[i][k][l]=max(f[i][k][l],f[i-1][j][k]+l+(cnt[i-2]-j-k-l)/3);
		}
	}
	int ans=0;
	for (int i=0;i<3;i++) for (int j=0;j<3;j++)
	{
		if (i+j>cnt[m-1]) continue;
		if (j>cnt[m]) continue;
		ans=max(ans,f[m][i][j]+(cnt[m-1]-i-j)/3+(cnt[m]-j)/3);
	}
	printf("%d\n",ans);
	return 0;
}