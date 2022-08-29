#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
const int Mxdt=100000;
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
int n,m,B[300002],ls[300002],rs[300002],dis[300002],h1[300002],c1,dep[300002],tot,rt[300002];
ll A[300002],tg[300002],f[300002];
struct edge{int to,next;}e1[600002];
inline void add1(re int x,re int y){e1[++c1]=(edge){y,h1[x]},h1[x]=c1;}
inline void Add(re int p,re ll x){A[p]+=x,tg[p]+=x;}
inline void pd(re int p){if(tg[p])Add(ls[p],tg[p]),Add(rs[p],tg[p]),tg[p]=0;}
inline int merge(re int x,re int y){
	if(!x||!y)return x+y;
	if(A[x]>A[y])swap(x,y);
	pd(x),rs[x]=merge(rs[x],y);
	if(dis[rs[x]]>dis[ls[x]])swap(ls[x],rs[x]);
	dis[x]=dis[rs[x]]+1;
	return x;
}
inline void dfs(re int x,re int y){
	dep[x]=dep[y]+1;
	ll sum=0;
	for(re int i=h1[x];i;i=e1[i].next)if(e1[i].to^y)dfs(e1[i].to,x),Add(rt[e1[i].to],-f[e1[i].to]),rt[x]=merge(rt[x],rt[e1[i].to]),sum+=f[e1[i].to];
	Add(rt[x],sum);
	while(rt[x]&&dep[x]<=dep[B[rt[x]]])pd(rt[x]),rt[x]=merge(ls[rt[x]],rs[rt[x]]);
	if(!rt[x])puts("-1"),exit(0);
	f[x]=A[rt[x]];
}
int main(){
	n=read(),m=read(),dep[1]=1;
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add1(x,y),add1(y,x);
	for(re int i=1,x,y,z;i<=m;++i)x=read(),y=read(),z=read(),++tot,A[tot]=z,B[tot]=y,rt[x]=merge(rt[x],tot);
	ll ans=0;
	for(re int i=h1[1];i;i=e1[i].next)dfs(e1[i].to,1),ans+=f[e1[i].to];
	printf("%lld",ans);
}