#include<cstdio>
#include<iostream>
#include<queue>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
struct rec  {int x,y,l,r;};
struct Edge {int y,z,ne;};
typedef long long LL;
typedef pair<LL,int> PII;
const int N=10010;
const LL inf=10000000000010LL;
int n,m,k,num;
int s1,s2,aim;
LL f1[N],f2[N];
int v[N];
rec tmp[N];
priority_queue<PII> Q;
rec q[N];
Edge e[100000];int last[N];
inline void add(int x,int y,int z)
{
	e[++num]=(Edge){y,z,last[x]};last[x]=num;
}
inline void dij(int S,LL *f)
{
	for (int i=1;i<=n;i++) f[i]=inf;
	f[S]=0;
	while (!Q.empty()) Q.pop();
	Q.push(MP(0,S));
	while (!Q.empty())
	{
		PII tmp=Q.top();Q.pop();
		int now=tmp.SC;
		LL dis=tmp.FR;
		if (f[now]!=dis) continue;
		for (int j=last[now];j;j=e[j].ne)
		if (f[e[j].y]>dis+e[j].z)
		{
			f[e[j].y]=dis+e[j].z;
			Q.push(MP(f[e[j].y],e[j].y));
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d%d",&s1,&s2,&aim);
	for (int i=1;i<=m;i++) 
	{
		scanf("%d%d%d",&tmp[i].x,&tmp[i].y,&tmp[i].r);
		add(tmp[i].x,tmp[i].y,tmp[i].r);
	}
	for (int i=1;i<=k;i++) 
	{
		scanf("%d%d%d%d",&q[i].x,&q[i].y,&q[i].l,&q[i].r);
		add(q[i].x,q[i].y,q[i].r);
	}
	while (1)
	{
		dij(s1,f1);dij(s2,f2);
		int flag=0;
		for (int i=1;i<=k;i++) 
		if (!v[i]&&f1[q[i].x]<f2[q[i].x]) 
		{
			add(q[i].x,q[i].y,q[i].l);
			flag=1;
			v[i]=1;
		}
		if (!flag) break;
	}
	if (f1[aim]<f2[aim]) 
	{
		printf("WIN\n");
		for (int i=1;i<=k;i++) printf("%d ",v[i]?q[i].l:q[i].r);
		return 0;
	}
	
	for (int i=1;i<=n;i++) v[i]=last[i]=0;
	num=0;
	for (int i=1;i<=m;i++) add(tmp[i].x,tmp[i].y,tmp[i].r);
	for (int i=1;i<=k;i++) add(q[i].x,q[i].y,q[i].r);
	
	while (1)
	{
		dij(s1,f1);dij(s2,f2);
		int flag=0;
		for (int i=1;i<=k;i++) 
		if (!v[i]&&f1[q[i].x]<=f2[q[i].y]) 
		{
			add(q[i].x,q[i].y,q[i].l);
			flag=1;
			v[i]=1;
		}
		if (!flag) break;
	}
	if (f1[aim]<=f2[aim]) 
	{
		printf("DRAW\n");
		for (int i=1;i<=k;i++) printf("%d ",v[i]?q[i].l:q[i].r);
		return 0;
	}
	printf("LOSE\n");
	return 0;
}