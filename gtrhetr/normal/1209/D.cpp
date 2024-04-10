#include<bits/stdc++.h>
using namespace std;

int a[100010],b[100010],fa[100010],size[100010],h[100010],n,k;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int find(int x) { return (x==fa[x])?x:fa[x]=find(fa[x]); }

inline void merge(int x,int y)
{
	if (x==y) return;
	fa[x]=y;size[y]+=size[x];
}

int main()
{
	n=rd();k=rd();
	for (int i=1;i<=k;i++) a[i]=rd(),b[i]=rd();
	for (int i=1;i<=n;i++) fa[i]=i,size[i]=1;
	for (int i=1;i<=k;i++) merge(find(a[i]),find(b[i]));
	for (int i=1;i<=k;i++) h[find(a[i])]++;
	int ans=0;
	for (int i=1;i<=n;i++) if (find(i)==i)
	{
		if (h[i]<size[i]) ans+=h[i];
		else ans+=size[i]-1;
	}
	printf("%d\n",k-ans);
	return 0;
}