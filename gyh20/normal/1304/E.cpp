#include<cstdio>
#include<iostream>
#define re register
using namespace std;
struct edge{
	int to,next;
}e[200002];
int n,q,head[200002],cnt,a,b,x,y,k,fa[200002][22],dep[200002];
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
	t=(t<<3)+(t<<1)+v-48;
	v=getchar();}
	return t;
}
inline void add(re int x,re int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
inline void dfs(re int x,re int y){
	fa[x][0]=y;
	dep[x]=dep[y]+1;
	for(re int i=head[x];i;i=e[i].next){
		if(e[i].to!=y)dfs(e[i].to,x);
	}
}
inline int lca(re int x,re int y){
	if(dep[x]>dep[y])swap(x,y);
	int tmp=dep[y]-dep[x];
	for(re int i=20;i>=0;--i){
		if(tmp&(1<<i))y=fa[y][i];
	}
	if(x==y)return x;
	for(re int i=20;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
inline int dis(re int x,re int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
inline bool check(re int x,re int y,re int z){
	int tmp=dis(x,y);
	if(tmp==z)return 1;
	if(tmp>z)return 0;
	if((z-tmp)&1)return 0;
	return 1;
}
int main(){
	n=read();
	for(re int i=1;i<n;++i){
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	dfs(1,1);
	for(re int i=1;i<=20;++i){
		for(re int j=1;j<=n;++j){
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	q=read();
	while(q--){
		x=read();y=read();a=read();b=read();k=read();
		if(check(a,b,k)||check(x,b,k-dis(a,y)-1)||check(y,b,k-dis(a,x)-1))puts("YES");
		else puts("NO");
	}
}