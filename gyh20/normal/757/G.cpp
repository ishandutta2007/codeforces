#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
const int Mxdt=1000000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(ll x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(ll x,char ch)
{
	print(x),pc(ch,false);
}
int rt[200002],n,ls[37000002],rs[37000002],tot,tg[37000002],p[200002],m,dep[200002],siz[200002],fa[200002],c[200002],son[200002],dfn[200002],pl[200002],top[200002],tim,head[200002],cnt,val[200002],lv;
ll sz[37000002],sum[200002],g[200002],la,dis[200002];
inline void ins(re int &p,re int l,re int r,re int x,re int y,re int z){
	if(p<=lv)++tot,ls[tot]=ls[p],rs[tot]=rs[p],sz[tot]=sz[p],tg[tot]=tg[p],p=tot;
	if(l>=x&&r<=y){tg[p]+=z;return;}
	sz[p]+=(sum[min(y,r)]-sum[max(x,l)-1])*z;
	re int mid=l+r>>1;
	if(x<=mid)ins(ls[p],l,mid,x,y,z);
	if(y>mid)ins(rs[p],mid+1,r,x,y,z);
}
inline ll ask(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y)return sz[p]+1ll*tg[p]*(sum[r]-sum[l-1]);
	re int mid=l+r>>1;
	re ll s=tg[p]*(sum[min(y,r)]-sum[max(x,l)-1]);
	if(x<=mid)s+=ask(ls[p],l,mid,x,y);
	if(y>mid)s+=ask(rs[p],mid+1,r,x,y);
	return s;
}
struct edge{int to,next,w;}e[400002];
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}
inline void dfs1(re int x,re int y){
	siz[x]=1,fa[x]=y,dep[x]=dep[y]+1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			val[e[i].to]=e[i].w,dis[e[i].to]=dis[x]+e[i].w,dfs1(e[i].to,x),siz[x]+=siz[e[i].to];
			if(siz[e[i].to]+10>siz[son[x]])son[x]=e[i].to;
		}
}
inline void dfs2(re int x,re int y){
	dfn[x]=++tim,pl[tim]=x,top[x]=y,sum[tim]=sum[tim-1]+val[x];
	if(son[x])dfs2(son[x],y);
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^fa[x]&&e[i].to^son[x])dfs2(e[i].to,e[i].to);
}
inline void ins(re int p,re int q,re int x,re int y){
	rt[p]=rt[q],lv=tot;
	while(x){
		ins(rt[p],1,n,dfn[top[x]],dfn[x],y);
		x=fa[top[x]];
	}
}
inline ll ask(re int p,re int x){
	re ll s=0;
	while(x){
		s+=ask(rt[p],1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	return s;
}
signed main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)p[i]=read();
	for(re int i=1,x,y,z;i<n;++i)x=read(),y=read(),z=read(),add(x,y,z),add(y,x,z);
	dfs1(1,0),dfs2(1,1);
	for(re int i=1;i<=n;++i)ins(i,i-1,p[i],1),g[i]=g[i-1]+dis[p[i]];
	while(m--){
		if(read()==1){
			re int x=read()^la,y=read()^la,z=read()^la;
			printnum(la=(dis[z]*(y-x+1)-2*ask(y,z)+2*ask(x-1,z)+g[y]-g[x-1]),'\n');
			la&=((1<<30)-1);
		}
		else{
			re int x=read()^la;
			ins(x,x,p[x],-1);
			g[x]+=dis[p[x+1]]-dis[p[x]];
			swap(p[x],p[x+1]);
			ins(x,x,p[x],1);
			if(tot>32000000){
				tot=0;
				for(re int i=1;i<=n;++i)ins(i,i-1,p[i],1);
			}
		}
	}
	return pc('o',1);
}