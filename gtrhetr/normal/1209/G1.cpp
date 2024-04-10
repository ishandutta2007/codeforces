#include<bits/stdc++.h>
using namespace std;

int mn[200010],mx[200010];
int size[200010],maxn[200010];
int num[200010],fa[200010],r[200010],n,q;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int find(int x) { return (x==fa[x])?x:fa[x]=find(fa[x]); }
inline int findr(int x) { return (x==r[x])?x:r[x]=findr(r[x]); }

inline void merge(int x,int y)
{
	if (x==y) return;
	fa[x]=y;size[y]+=size[x];maxn[y]=max(maxn[y],maxn[x]);
}

int main()
{
	n=rd();q=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=200000;i++) fa[i]=i,size[i]=0;
	for (int i=1;i<=200000;i++) mn[i]=n+1;
	for (int i=1;i<=n;i++) mn[num[i]]=min(mn[num[i]],i),mx[num[i]]=i;
	for (int i=1;i<=n;i++) size[num[i]]++;
	for (int i=1;i<=200000;i++) maxn[i]=size[i];
	for (int i=1;i<=n;i++) r[i]=i;
	for (int i=1;i<=200000;i++) if (mx[i])
	{
		for (int j=findr(mn[i]);j<=mx[i];j=findr(j))
		{
			merge(find(i),find(num[j]));
			if (j<mx[i]) r[j]=j+1;
			else break;
		}
	}
	int ans=0;
	for (int i=1;i<=200000;i++) if (find(i)==i) ans+=size[i]-maxn[i];
	printf("%d\n",ans);
	return 0;
}