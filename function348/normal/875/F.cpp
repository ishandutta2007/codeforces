#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int N=200010;
struct Edge {int x,y,z;};
int n,m,ans;
int u[N],c[N],fa[N];
Edge e[N];
int cmp(Edge a,Edge b) { return a.z>b.z;}
int find(int i) { return fa[i]==i?i:fa[i]=find(fa[i]);}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	sort(e+1,e+1+m,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x=find(e[i].x),y=find(e[i].y);
		if (x==y) 
		{
			if (c[x]==0) c[x]=1,ans+=e[i].z;
		}
		else if (c[x]+c[y]<=1)
		{
			fa[y]=x;c[x]|=c[y];
			ans+=e[i].z;
		}
	}
	cout<<ans;
	return 0;
}