#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define MAX 5050
#define MAXL 100100
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
struct edge{int u,v,w,id;}e[MAXL];
bool operator<(edge a,edge b)
{
	if(a.w!=b.w)return a.w<b.w;
	return a.u>b.u;
}
int f[MAX],n,m,K,tot;
int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
vector<int> g;
int Kruskal(int mid)
{
	for(int i=1;i<=m;++i)if(e[i].u==1)e[i].w+=mid;
	for(int i=1;i<=n;++i)f[i]=i;
	int cnt=0;g.clear();sort(&e[1],&e[m+1]);
	for(int i=1;i<=m;++i)
	{
		int u=getf(e[i].u),v=getf(e[i].v);
		if(u==v)continue;
		f[u]=v;g.push_back(e[i].id);
		if(e[i].u==1)++cnt;
	}
	for(int i=1;i<=m;++i)if(e[i].u==1)e[i].w-=mid;
	return cnt;
}
void Calc(int mid)
{
	for(int i=1;i<=m;++i)if(e[i].u==1)e[i].w+=mid;
	for(int i=1;i<=n;++i)f[i]=i;
	int cnt=0,tot=0;g.clear();sort(&e[1],&e[m+1]);
	for(int i=1;i<=m;++i)
	{
		int u=getf(e[i].u),v=getf(e[i].v);
		if(u==v)continue;
		if(e[i].u==1&&cnt==K)continue;
		f[u]=v;g.push_back(e[i].id);
		if(e[i].u==1)++cnt;++tot;
	}
	if(cnt<K||tot!=n-1){puts("-1");exit(0);}
}
int main()
{
	n=read();m=read();K=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		if(u>v)swap(u,v);if(u==1)++tot;
		e[i]=(edge){u,v,w,i};
	}
	int l=-100000,r=100000,ret=-1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int d=Kruskal(mid);
		if(d<K)r=mid-1;
		else l=mid+1,ret=mid;
	}
	if(ret<-1e5){puts("-1");return 0;}
	Calc(r);printf("%d\n",n-1);
	for(int i=0;i<n-1;++i)printf("%d ",g[i]);
	return 0;
}