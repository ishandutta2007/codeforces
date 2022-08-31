#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,ans,A,B,C,D,fa[10000002],cnt,head[400002],f[400002],d[400002],col[400002];
map<int,int>V[200002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
struct edge{
	int to,next,w;
}e[10000002];
inline void add(re int x,re int y,re int z){
	e[++cnt]=(edge){y,head[x],z},head[x]=cnt;
}
inline void dfs(re int x,re int y){
	f[x]=y;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x),d[e[i].to]=e[i].w;
		}
}
inline int Get(re int x){
	if(x==-1)return x;
	re int s=0;
	for(re int i=0;i<30;++i)if(x&(1<<i))s^=1;
	return s;
}
inline void Merge(re int x,re int y){
	fa[root(x)]=root(y);
}
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n+n;++i)fa[i]=i,col[i]=-1;
		for(re int i=1;i<=n;++i)head[i]=0,V[i].clear();
		cnt=0;
		for(re int i=1,x,y,z;i<n;++i)x=read(),y=read(),z=read(),V[x][y]=V[y][x]=z,z=Get(z),add(x,y,z),add(y,x,z);
		dfs(1,1);
		for(re int i=2;i<=n;++i){
			if(d[i]==1)Merge(i,f[i]+n),Merge(i+n,f[i]);
			if(d[i]==0)Merge(i,f[i]),Merge(i+n,f[i]+n);
		}
		for(re int i=1,x,y,z;i<=m;++i){
			x=read(),y=read(),z=read();
			if(z)Merge(x,y+n),Merge(x+n,y);
			else Merge(x,y),Merge(x+n,y+n);
		}
		re bool ia=1;
		for(re int i=1;i<=n;++i)if(root(i)==root(i+n))ia=0;
		for(re int i=1;i<=n;++i)
			if(col[root(i)]==-1){
				col[root(i)]=0;
				col[root(i+n)]=1;
			}
		for(re int i=2;i<=n;++i){
			if(col[root(i)]==col[root(f[i])]&&d[i]==1)ia=0;
			if(col[root(i)]==col[root(f[i]+n)]&&d[i]==0)ia=0;
		}
		if(!ia){
			puts("NO");
			continue;
		}
		puts("YES");
		for(re int i=2;i<=n;++i){
			if(d[i]!=-1)printf("%d %d %d\n",f[i],i,V[f[i]][i]);
			else printf("%d %d %d\n",f[i],i,col[root(i)]==col[root(f[i])]?0:1);
		}
	}
}