#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,head[200002],cnt,vis[200002],fa[200002],dep[200002],d[200002],u1,u2,v1,v2,p;
vector<int>ans,tmp;
struct edge{
	int to,next;
}e[400002];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]};
	head[x]=cnt;
}
inline void dfs1(re int x,re int z){
	vis[x]=1,dep[x]=dep[fa[x]=z]+1;
	for(re int i=head[x];i;i=e[i].next){
		re int y=e[i].to;
		if(y==z)continue;
		if(!vis[y])dfs1(y,x),d[x]+=d[y]; 
		else if(dep[y]<dep[x])++d[x],--d[y];
	}
}
inline void dfs2(re int x,re int z){
	for(re int i=head[x];i;i=e[i].next){
		re int y=e[i].to;
		if(dep[y]==dep[x]+1)dfs2(y,x);
		else if(dep[y]<dep[p]&&(y^z))u1?u2=x,v2=y:(u1=x,v1=y);
		if(u2)return;
	}
}
inline int LCA(re int x,re int y){
	while(x^y)dep[x]>dep[y]?x=fa[x]:y=fa[y];
	return x;
}
inline void get(re int x,re int y){
	re int t=y;
	if(dep[x]<dep[y]){
		tmp.clear();y=fa[y];
		while(x^y)tmp.push_back(y),y=fa[y];
		tmp.push_back(x);
		for(int i=tmp.size()-1;~i;--i)ans.push_back(tmp[i]);
	}
	else while(x^y)ans.push_back(x),x=fa[x];
	ans.push_back(t);
}
inline void print(){
	printf("%d ",ans.size());
	for(re int i=0;i<ans.size();++i)printf("%d ",ans[i]);
	puts(""),ans.clear();
}
int main(){
	n=read(),m=read();
	for(re int i=1,x,y;i<=m;++i)add(x=read(),y=read()),add(y,x);
	for(re int i=1;i<=n;++i)if(!vis[i])dfs1(i,0);
	for(re int i=1;i<=n;++i)if(d[i]>=2){p=i;break;}
	if(!p)return puts("NO"),0;
	puts("YES");
	dfs2(p,fa[p]);
	if(dep[v2]<dep[v1])swap(u1,u2),swap(v1,v2);
	int lca=LCA(u1,u2);
	get(lca,u1),get(v1,v2),print();
	get(lca,u2),ans.push_back(v2),print();
	get(lca,v2),print();
}