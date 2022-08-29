#include<cstdio>
#include<vector>
#define re register
using namespace std;
inline int read() {
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct edge {
	int to,next;
} e[2000002];
int n,head[1000002],son[1000002],len[1000002],cnt,q,md[1000002],dep[1000002],fa[1000002][22],tp[1000002],h[1000002];
vector<int> u[1000002],d[1000002];
inline void add(re int x,re int y) {
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
inline void dfs(re int x,re int y) {
	fa[x][0]=y;
	dep[x]=md[x]=dep[y]+1;
	for(re int i=head[x]; i; i=e[i].next) {
		if(e[i].to!=y) {
			dfs(e[i].to,x);
			if(md[e[i].to]>md[son[x]])son[x]=e[i].to;
		}
	}
	if(son[x])
		md[x]=md[son[x]];
}
inline void dfs1(re int x,re int y) {
	tp[x]=y;
	len[x]=md[x]-dep[y]+1;
	if(son[x])dfs1(son[x],y);
	for(re int i=head[x]; i; i=e[i].next) {
		if(e[i].to!=son[x]&&e[i].to!=fa[x][0])dfs1(e[i].to,e[i].to);
	}
}
inline int ask(re int x,re int y) {
	if(y>dep[x])return 0;
	if(!y)return x;
	x=fa[x][h[y]];
	y-=1<<h[y];
	if(y<0)while(1);
	if(!y)return x;
	if(dep[x]-dep[tp[x]]==y)return tp[x];
	if(dep[x]-dep[tp[x]]>y)return d[tp[x]][dep[x]-dep[tp[x]]-y-1];
	else return u[tp[x]][y-dep[x]+dep[tp[x]]-1];
}
int tmp[1000002],*f[1000002],*id=tmp,ans[1000002];
void DP(int x,int prt) {
	f[x][0]=1;
	if(son[x]) {
		f[son[x]]=f[x]+1;
		DP(son[x],x);
		ans[x]=ans[son[x]]+1;
	}
	for(int i=head[x]; i; i=e[i].next) {
		int y=e[i].to;
		if(y==prt||y==son[x])continue;
		f[y]=id;
		id+=md[y]-dep[y]+1;
		DP(y,x);

	for(int j=1; j<=md[y]-dep[y]+1; ++j) {
		f[x][j]+=f[y][j-1];
		if(f[x][j]>f[x][ans[x]]||(f[x][j]==f[x][ans[x]]&&ans[x]>j))
			ans[x]=j;
	}
}
if(f[x][ans[x]]==1)ans[x]=0;
	}
int main() {
	n=read();
	re int x,y;
	for(re int i=1; i<n; ++i) {
		x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	f[1]=id;
	id+=md[1];
	DP(1,0);
	int mx=1,la=0;
	for(re int i=1; i<=n; ++i) {
		printf("%d\n",ans[i]);
	}
	
}