#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,k,m,head[200002],cnt,pos,dep[200002],rt,p[200002],tg[200002],fa[200002],tot,ans[200002],ia,mxd;
struct edge{int to,next;}e[400002];
//map<int,int>V[200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	dep[x]=dep[y]+1,fa[x]=y;if(dep[x]>dep[pos])pos=x;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			dfs(e[i].to,x);
}
inline void dfs(re int x,re int y,re int z,re int d){
	mxd=max(mxd,d);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y&&!tg[e[i].to]){
			ans[e[i].to]=(ans[x]+z+k-1)%k+1;
			dfs(e[i].to,x,z,d+1);
		}
}
/*
inline void dfs1(re int x,re int y){
	V[x][ans[x]]=dep[x];
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs1(e[i].to,x);
			if(V[e[i].to].size()>V[x].size())swap(V[x],V[e[i].to]);
			for(auto z:V[e[i].to]){
				if(V[x].count(z.first)&&V[x][z.first]+z.second-dep[x]-dep[x]<k)ia=0;
				if(V[x].count(z.first))V[x][z.first]=min(V[x][z.first],z.second);
				else V[x][z.first]=z.second;
			}
		}
}*/
int main(){
	n=read(),k=read(),ia=1;
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfs(1,0),rt=pos,pos=0,dfs(rt,0);
	for(re int i=pos;i;i=fa[i])p[++tot]=i,tg[i]=1,ans[i]=(tot-1)%k+1;
	re int mid=tot+1>>1;
	for(re int i=1;i<=mid;++i){
		mxd=0,dfs(p[i],p[i],-1,0);
		if(mxd)ia&=mxd+i<k;
	}
	for(re int i=mid+1;i<=tot;++i){
		mxd=0,dfs(p[i],p[i],1,0);
		if(mxd)ia&=mxd+(tot-i+1)<k;
	}
//	dfs1(1,1); 
	if((k^2)&&(!ia))puts("No");
	else{
		puts("Yes");
		for(re int i=1;i<=n;++i)printf("%d ",ans[i]);
	}
}