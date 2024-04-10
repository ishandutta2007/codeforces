#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj=false){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48);
}
inline void printnum(int x,char ch)
{
	print(x),pc(ch);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int vis[100002],tim,head[100002],n,m,q,cnt,pl[100002],dfn[100002],top[100002],fa[100002],dep[100002],son[100002],siz[100002],head1[100002],cnt1,a[100002],tp,stk[100002],f[100002],g[100002];
struct edge{int to,next;}e[200002],e1[200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void add1(re int x,re int y){e1[++cnt1]=(edge){y,head1[x]},head1[x]=cnt1;}
inline void dfs1(re int x,re int y){
	siz[x]=1,fa[x]=y,dep[x]=dep[y]+1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs1(e[i].to,x),siz[x]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;
		}
}
inline void dfs2(re int x,re int y){
	top[x]=y,dfn[x]=++tim,pl[tim]=x;
	if(son[x])dfs2(son[x],y);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^fa[x]&&e[i].to^son[x])dfs2(e[i].to,e[i].to);
}
inline int lca(re int x,re int y){
	while(top[x]^top[y]){
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
inline bool in(re int x,re int y){return dfn[y]>=dfn[x]&&dfn[y]<dfn[x]+siz[x];}
inline void DP(re int x){
	f[x]=g[x]=0;
	for(re int i=head1[x];i;i=e1[i].next)DP(e1[i].to),f[x]+=f[e1[i].to],g[x]+=g[e1[i].to];
	if(vis[x]==tim)f[x]+=g[x],g[x]=1;
	else if(g[x]>1)++f[x],g[x]=0;
	head1[x]=0;
}
int main(){
	n=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfs1(1,0),dfs2(1,1),q=read();
	while(q--){
		m=read(),++tim;re bool ia=1;cnt1=0;
		for(re int i=1;i<=m;++i)a[i]=read(),vis[a[i]]=tim;
		for(re int i=1;i<=m&&ia;++i)if(vis[fa[a[i]]]==tim)ia=0;
		if(!ia){
			pc('-'),pc('1'),pc('\n');
			continue;
		}
		for(re int i=1;i<=m;++i)a[i]=dfn[a[i]];
		sort(a+1,a+m+1),stk[tp=1]=1;
		for(re int i=1;i<=m;++i){
			a[i]=pl[a[i]];
			if(a[i]==1)continue;
			while(tp>1&&!in(stk[tp-1],a[i]))add1(stk[tp-1],stk[tp]),--tp;
			if(in(stk[tp],a[i]))stk[++tp]=a[i];
			else{
				re int tmp=lca(a[i],stk[tp]);
				add1(tmp,stk[tp]),--tp;
				if(tmp^stk[tp])stk[++tp]=tmp;
				stk[++tp]=a[i];
			}
		}
		while(tp>1)add1(stk[tp-1],stk[tp]),--tp;
		DP(1);
		printnum(f[1],'\n');
	}
	pc('',1);
}