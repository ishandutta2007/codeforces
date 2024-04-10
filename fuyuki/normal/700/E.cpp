#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
const int N=4e5+1;
char a[N];
int n,tot,qwq,cnt,last,ans;
int h[N],dp[N],t[N],pos[N];
struct edge{int t,n;}e[N];
int ch[N][26],fa[N],len[N];
int rt[N],ls[N<<5],rs[N<<5];
V cpy(int x,int y){FOR(i,0,25)ch[x][i]=ch[y][i];}
V ins(int x){
	int p(last),np,q,nq;
	len[np=last=++tot]=len[p]+1;
	while(p&&!ch[p][x])ch[p][x]=np,p=fa[p];
	if(!p)return void(fa[np]=1);
	if(len[q=ch[p][x]]==len[p]+1)return void(fa[np]=q);
	cpy(nq=++tot,q),len[nq]=len[p]+1,fa[nq]=fa[q],fa[q]=fa[np]=nq;
	while(p&&ch[p][x]==q)ch[p][x]=nq,p=fa[p];
}
V input(){scanf("%d%s",&n,a+1),last=tot=1;}
#define lson ls[p],L,mid
#define root(p) rt[p],1,n
#define rson rs[p],mid+1,R
V ins(int&p,int L,int R,int x){
	if(!p)p=++cnt;if(L==R)return;
	int mid=L+R>>1;
	(x<=mid)?ins(lson,x):ins(rson,x);
}
V add_edge(int x,int y){e[++qwq]=(edge){y,h[x]},h[x]=qwq;}
V init(){
	FOR(i,1,n)ins(a[i]-'a'),ins(root(last),i),pos[last]=i;
	FOR(i,2,tot)add_edge(fa[i],i);
}
I merge(int x,int y){
	if(!x||!y)return x|y;
	int p=++cnt;
	ls[p]=merge(ls[x],ls[y]);
	rs[p]=merge(rs[x],rs[y]);
	return p;
}
V dfs1(int u){REP(u)dfs1(v),rt[u]=merge(rt[u],rt[v]),pos[u]=pos[v];}
I ask(int p,int L,int R,int l,int r){
	if(!p)return 0;
	if(L==l&&R==r)return 1;
	int mid=L+R>>1;
	if(l>mid)return ask(rson,l,r);
	if(r<=mid)return ask(lson,l,r);
	return ask(lson,l,mid)|ask(rson,mid+1,r);
}
I find(int x,int y){
	return ask(root(y),pos[x]-len[x]+len[y],pos[x]-1);
}
V dfs2(int u){
	if(fa[u]==1||find(u,t[fa[u]]))
		dp[u]=dp[fa[u]]+1,t[u]=u;
	else dp[u]=dp[fa[u]],t[u]=t[fa[u]];
	if(ans<dp[u])ans=dp[u];
	REP(u)dfs2(v);
}
V work(){dfs1(1),dfs2(1),cout<<ans;}
int main(){
	input();
	init();
	work();
	return 0;
}