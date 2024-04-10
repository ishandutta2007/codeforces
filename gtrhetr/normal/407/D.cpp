#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

pii st[410][410];

int top[410],id[160010];
int num[410][410],lst[410][410],mx[410],n,m;

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
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) num[i][j]=rd();
	int ans=0;
	for (int i=n;i;i--)
	{
		memset(id,0,sizeof(id));
		int tt=0;
		for (int j=1;j<=m;j++) if (!id[num[i][j]]) id[num[i][j]]=++tt;
		for (int j=1;j<=tt;j++) top[j]=0;
		for (int j=1;j<=m;j++)
		{
			for (int k=n;k>=i;k--) if (id[num[k][j]])
			{
				int now=id[num[k][j]];
				for (int l=1;l<=top[now];l++)
				{
					int hh=max(st[now][l].second,k);
					lst[hh][j]=max(lst[hh][j],st[now][l].first);
				}
				while (top[now]>0&&st[now][top[now]].second>=k) top[now]--;
				st[now][++top[now]]=pii(j,k);
			}
		}
		memset(mx,0,sizeof(mx));
		for (int j=i;j<=n;j++) for (int k=1;k<=m;k++)
		{
			mx[k]=max(max(mx[k],mx[k-1]),lst[j][k]);
			ans=max(ans,(j-i+1)*(k-mx[k]));
		}
	}
	printf("%d\n",ans);
	return 0;
}