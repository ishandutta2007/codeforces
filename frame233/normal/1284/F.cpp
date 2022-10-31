#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=250005;
std::vector<int> e1[N],e2[N];int dep[N],anc[N][20],fa[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1,anc[x][0]=fa;for(int i=1;i<20;++i)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(auto v:e1[x])if(v!=fa)dfs1(v,x);
}
int lca(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=19;i>=0;--i)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;--i)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
void solve(int x,int y){
	int z=lca(x,y),p=find(x);
	if(dep[p]>dep[z])printf("%d %d %d %d\n",p,anc[p][0],x,y),fa[p]=find(anc[p][0]);
	else{
		int cur=y;for(int i=19;i>=0;--i)if(dep[cur]-(1<<i)>=dep[z]&&find(anc[cur][i])!=p)cur=anc[cur][i];
		printf("%d %d %d %d\n",cur,anc[cur][0],x,y),fa[cur]=find(anc[cur][0]);
	}
}
void dfs2(int x,int fa){for(auto v:e2[x])if(v!=fa)dfs2(v,x),solve(v,x);}
int main(){
	int n;read(n);
	for(int i=1,x,y;i<n;++i)read(x,y),e1[x].pb(y),e1[y].pb(x);
	for(int i=1,x,y;i<n;++i)read(x,y),e2[x].pb(y),e2[y].pb(x);
	printf("%d\n",n-1),std::iota(fa+1,fa+n+1,1),dfs1(1,0),dfs2(1,0);
	return 0;
}