#include<bits/stdc++.h>
using namespace std;

vector<int> v[100010];

int fa[100010],r[100010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int find(int x) { return (x==fa[x])?x:fa[x]=find(fa[x]); }
inline int findr(int x) { return (x==r[x])?x:r[x]=findr(r[x]); }

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=n+1;i++) fa[i]=r[i]=i;
	for (int i=1;i<=n;i++)
	{
		v[i].push_back(0);v[i].push_back(n+1);
		sort(v[i].begin(),v[i].end());
		for (int j=0;j<v[i].size()-1;j++)
		{
			if (v[i][j]+1<v[i][j+1]) fa[find(i)]=find(v[i][j]+1),fa[find(i)]=find(v[i][j+1]-1);
			for (int hh=findr(v[i][j]+1);hh<v[i][j+1];hh=findr(hh)) fa[find(i)]=find(hh),r[hh]=hh+1;
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++) if (find(i)==i) ans++;
	printf("%d\n",ans-1);
	return 0;
}