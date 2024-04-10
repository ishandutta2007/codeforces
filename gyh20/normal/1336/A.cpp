#include<cstdio>
#include<queue>
using namespace std;
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a,b,c,d[200002],head[200002],cnt,dep[200002],fa[200002],siz[200002];
long long ans;
struct edge{
	int to,next;
}e[400002];
inline void add(re int x,re int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
struct node{
	int pos;
	const bool operator <(const node x)const{
		return dep[x.pos]-siz[x.pos]+1>dep[pos]-siz[pos]+1;
	}
};
priority_queue<node>q;
inline void dfs(re int x,re int y){
	dep[x]=dep[y]+1;fa[x]=y;siz[x]=1;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x),siz[x]+=siz[e[i].to];
}
int main(){
	n=read();m=read();++d[1];dep[1]=-1;
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),++d[x],++d[y],add(x,y),add(y,x);
	dfs(1,1);
	for(re int i=1;i<=n;++i)if(d[i]==1)q.push((node){i});
	for(re int i=1;i<=m;++i){
		re node x=q.top();q.pop();
		ans+=dep[x.pos]-siz[x.pos]+1;
		if((--d[fa[x.pos]])==1)q.push((node){fa[x.pos]});
	}
	printf("%lld",ans);
}