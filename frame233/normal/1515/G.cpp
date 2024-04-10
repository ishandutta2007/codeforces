#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
const int N=200005;
typedef long long ll;
struct edge{int v,nxt,w;}c[N<<1];
int front[N],ec;
inline void addedge(int u,int v,int w){c[++ec]=(edge){v,front[u],w},front[u]=ec;}
int dfn[N],low[N],id,col[N],COL,st[N],top,nd[N],qwq;
void tarjan(int x){
	dfn[x]=low[x]=++id,st[++top]=x;
	for(int i=front[x];i;i=c[i].nxt){
		int v=c[i].v;
		if(!dfn[v])tarjan(v),chmin(low[x],low[v]);
		else if(!col[v])chmin(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		col[x]=++COL;
		while(st[top]!=x)col[st[top--]]=COL;
		--top;
	}
}
ll G[N],g,dep[N];
bool mark[N];
void dfs(int x){
	mark[x]=true,dfn[x]=++id;
	for(int i=front[x];i;i=c[i].nxt){
		int v=c[i].v;
		if(col[v]!=qwq)continue;
		if(!dfn[v])dep[v]=dep[x]+c[i].w,dfs(v);
		else g=gcd(abs(dep[x]-dep[v]+c[i].w),g);
	}
	mark[x]=false;
}
int main(){
	int n,m;read(n,m);
	for(int i=1,x,y,z;i<=m;++i)read(x,y,z),addedge(x,y,z);
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;++i)nd[col[i]]=i;
	memset(dfn,0,sizeof(dfn)),id=0;
	for(int i=1;i<=COL;++i)qwq=i,g=0,dfs(nd[i]),G[i]=g;
	int q;read(q);
	for(int t=0,x,a,b;t<q;++t)read(x,a,b),puts(a%gcd(G[col[x]],(ll)b)==0?"YES":"NO");
	return 0;
}