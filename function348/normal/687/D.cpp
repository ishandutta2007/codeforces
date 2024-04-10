#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;
struct Edge {int x,y,z,id;};
int n,m,q;
Edge e[N*N];
int fa[N],dis[N];
int cmp(Edge a,Edge b) { return a.z>b.z;}
int find(int i)
{
	if (fa[i]==i) return i;
	int y=find(fa[i]);
	dis[i]^=dis[fa[i]];
	fa[i]=y;
	return y;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[i]=(Edge){x,y,z,i};
	}
	sort(e+1,e+1+m,cmp);
	while (q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		for (int i=1;i<=n;i++) fa[i]=i,dis[i]=0;
		int f=0;
		for (int i=1;i<=m;i++)
		{
			if (e[i].id<l||e[i].id>r) continue;
			int k1=find(e[i].x),k2=find(e[i].y);
			if (k1!=k2)
			{
				fa[k2]=k1;
				dis[k2]=dis[e[i].x]^dis[e[i].y]^1;
			}
			else
			if (dis[e[i].x]==dis[e[i].y])
			{
				printf("%d\n",e[i].z);
				f=1;
				break;
			}
		}
		if (!f) printf("-1\n");
	}
	return 0;
}