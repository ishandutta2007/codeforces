#include <cstdio>
#include <vector>
#include <algorithm>
#define MN 100005
using namespace std;
struct edge{int nex,to,wt;}e[MN<<1];
struct meg
{
	int pos,val;
	friend bool operator<(const meg& a,const meg& b) {return a.val>b.val;}
};
vector <meg> v[MN];
int hr[MN],dep[MN],f1[MN],f2[MN],pin,ans,n,m;
//bool u[MN];

inline int read()
{
	int n=0,f=1;char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}
inline void ins(int x,int y,int z) {e[++pin]=(edge){hr[x],y,z}; hr[x]=pin;}
/*
void dfs2(int x,int fat)
{
	register int i;
	if (u[x]) while (!q[x].empty()) {u[q[x].top().pos]=true; q[x].pop();}
//	if (dep[x]>ans) ans=dep[x];
	for (i=hr[x];i;i=e[i].nex)
	{
		if (e[i].to==fat) continue;
		dfs2(e[i].to,x);
		if (u[e[i].to]) f2[x]=max(f2[x],f2[e[i].to]);
		else f2[x]=max(f2[x],f2[e[i].to]+e[i].wt);
	}
	if (!u[x]) f2[x]+=f1[x];
//		if (u[e[i].to]) dep[e[i].to]=dep[x];
//		else dep[e[i].to]=dep[x]+e[i].wt;
//		dfs2(e[i].to,x);
}

void dfs1(int x,int fat)
{
	register int i,lt;
	for (i=hr[x];i;i=e[i].nex)
	{
		if (e[i].to==fat) continue;
		dfs1(e[i].to,x);
		lt=e[i].wt+f1[e[i].to];
		q[x].push((meg){e[i].to,lt}); f1[x]+=lt;
		if (q[x].size()>=m) {f1[x]-=q[x].top().val; q[x].pop();}
	}
}*/

void dfs(int x,int fat)
{
	register int i,lt,mx;
	for (i=hr[x];i;i=e[i].nex)
	{
		if (e[i].to==fat) continue;
		dfs(e[i].to,x);
//		ltlt=;
		v[x].push_back((meg){e[i].to,e[i].wt+f1[e[i].to]});
	}
	sort(v[x].begin(),v[x].end());
	for (i=0;i<v[x].size()&&i<m-1;++i) f1[x]+=v[x][i].val;
	if (v[x].size()>=m) mx=v[x][m-1].val; else mx=0;
	for (i=0;i<v[x].size();++i)
	{
		if (i<m-1) f2[x]=max(f2[x],f1[x]-f1[v[x][i].pos]+f2[v[x][i].pos]+mx);
		else f2[x]=max(f2[x],f1[x]+v[x][i].val-f1[v[x][i].pos]+f2[v[x][i].pos]);
	}
//	for (i=hr[x];i;i=e[i].nex)
//	{
//		if (e[i].to==fat) continue;
//	}
}

int main()
{
	register int i,x,y,z;
	n=read(); m=read();
	for (i=1;i<n;++i)
	{
		x=read(); y=read(); z=read();
		ins(x,y,z); ins(y,x,z);
	}
	dfs(0,-1);
//	u[0]=true;dfs2(0,-1);
	printf("%d",f2[0]);
}