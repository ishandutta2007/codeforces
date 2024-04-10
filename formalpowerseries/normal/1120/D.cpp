#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct unionFindSet{
	LL fa[200005];
	void makeSet(LL up){for(LL i=0;i<=up;++i)	fa[i]=i;}
	LL findSet(LL x){return x==fa[x]?x:fa[x]=findSet(fa[x]);}
	bool unionSet(LL x,LL y)
	{
		LL xx=findSet(x),yy=findSet(y);
		if(xx==yy)	return false;
		return fa[yy]=xx,true;
	}
	bool unionSetS(LL x,LL y)
	{
		LL xx=findSet(x),yy=findSet(y);
		if(xx==yy)	return false;
		return true;
	}
}ufs;
struct Edge{
	LL u,v,val,id;
	Edge(){}
	Edge(LL U,LL V,LL VAL,LL I){u=U,v=V,val=VAL,id=I;}
	bool operator < (Edge ano) const {return val<ano.val;}
}ed[200005];
#define mp make_pair
vector<LL> G[200005];
LL n,a[200005],LeaF,m;
pair<LL,LL> dfs(LL now,LL pre)
{
	if(LL(G[now].size())==1 && now!=1)	++LeaF;
	LL L=0,R=0;
	for(auto st:G[now])
	{
		if(st==pre)	continue;
		pair<LL,LL> dk=dfs(st,now);
		if(!L)	L=dk.first;
		R=dk.second;
	}
	if(!L)	L=R=LeaF;
	ed[++m]=Edge(L,R+1,a[now],now);
	return mp(L,R);
}
bool used[200005];
void Kruskal()
{
	sort(ed+1,ed+1+m);
	++LeaF;
	ufs.makeSet(LeaF);
	LL ans=0;
	for(LL i=1;i<=m;++i)
	{
		LL u=ed[i].u,v=ed[i].v;
		ans+=ufs.unionSet(u,v)?ed[i].val:0;
	}
	printf("%lld ",ans);
	ufs.makeSet(LeaF);
	for(LL i=1;i<=m;++i)
	{
		LL l=i,r=i;
		while(ed[r].val==ed[i].val)	++r;
		--r;
		for(LL j=l;j<=r;++j)	used[ed[j].id]=ufs.unionSetS(ed[j].u,ed[j].v);
		for(LL j=l;j<=r;++j)	ufs.unionSet(ed[j].u,ed[j].v);
		i=r;
	}
}
int main(){
	scanf("%lld",&n);
	for(LL i=1;i<=n;++i)	scanf("%lld",&a[i]);
	for(LL i=1;i<n;++i)
	{
		LL u,v;
		scanf("%lld %lld",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs(1,0);
	Kruskal();
	LL st=0;
	for(LL i=1;i<=n;++i)	st+=used[i];
	printf("%lld\n",st);
	for(LL i=1;i<=n;++i)	if(used[i])	printf("%lld ",i);
	return 0;
}
/*
 Let you Dive
*/