#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t; 
}
int t,n,m,a,b,da,db,head[100002],cnt,vis[200002],mxd,mxp,fa[200002];
struct edge{
	int to,next;
}e[200002];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]};
	head[x]=cnt;
}
inline void dfs(re int x,re int y,re int z){
	if(z>mxd)mxd=z,mxp=x;
	fa[x]=y;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x,z+1);
}
int main(){
	t=read();
	while(t--){
		n=read(),a=read(),b=read(),da=read(),db=read();
		for(re int i=1;i<=n;++i)head[i]=0,vis[i]=-1;
		for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
		mxd=0,dfs(1,0,1);
		re int x=a,y=b,z=0,dis=0;
		while(x)vis[x]=z++,x=fa[x];
		while(vis[y]==-1)y=fa[y],++dis;
		dis+=vis[y];
		if(dis<=da||da*2>=db)puts("Alice");
		else{
			dfs(mxp,mxp,1);
			if(da*2>=mxd-1)puts("Alice");
			else puts("Bob");
		}
	}
}