#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0,f=0;re char v=gc();
	while(v<'0')f|=(v=='-'),v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return f?-t:t;
}
int n,a[100002],siz[100002],ch[100002][2],RT,tot,fa[100002];
ll tg[100002],sum[100002],val[100002],ans,mx,T[100002];
inline void add(re int x,re ll y){val[x]+=y,tg[x]+=y;}
inline void pd(re int p){
	if(tg[p]){
		if(ch[p][0])add(ch[p][0],tg[p]);
		if(ch[p][1])add(ch[p][1],tg[p]);
		tg[p]=0;
	}
}
inline void pu(re int p){
	siz[p]=siz[ch[p][0]]+siz[ch[p][1]]+1;
}
inline void Pd(re int x){
	if(x^RT)Pd(fa[x]);
	pd(x);
}
inline void rot(re int x){
	re int y=fa[x],z=fa[y],L=ch[y][1]==x;
	if(y==RT)RT=x;
	else ch[z][ch[z][1]==y]=x;
	fa[x]=z,ch[y][L]=ch[x][L^1],fa[ch[x][L^1]]=y,ch[x][L^1]=y,fa[y]=x;
	pu(y),pu(x);if(z)pu(z);
}
inline void splay(re int x){
	Pd(x);
	while(x^RT){
		re int y=fa[x],z=fa[y];
		if(y^RT){
			if((ch[y][0]==x)^(ch[z][0]==y))rot(x);
			else rot(y);
		}
		rot(x);
	}
}
inline int findk(re int x){
	re int p=RT;
	while(p){
		if(siz[ch[p][0]]+1==x)return p;
		if(siz[ch[p][0]]>=x)p=ch[p][0];
		else x-=siz[ch[p][0]]+1,p=ch[p][1];
	}
}
inline void ins(re int x,re int y){
	x=findk(x);
	splay(x),++tot,val[tot]=y,ch[tot][1]=ch[x][1],fa[ch[x][1]]=tot,ch[x][1]=tot,fa[tot]=x;
	re int p=tot;
	while(p)pu(p),p=fa[p];
}
inline ll ask(re int x){x=findk(x);splay(x);return val[x];}
inline void DFS(re int p,re int sz){
	pd(p),T[sz+siz[ch[p][0]]+1]=val[p];
	if(ch[p][0])DFS(ch[p][0],sz);
	if(ch[p][1])DFS(ch[p][1],sz+siz[ch[p][0]]+1);
}
signed main(){
	n=read(),RT=tot=siz[1]=1;
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1,x;i<=n;++i){
		re int p=RT,pos=i,sz=0;
		while(p){
			pd(p);
			re int S=sz+siz[ch[p][0]]+1;
			if(S==1)break;
			if(val[p]<=1ll*(S-1)*a[i])pos=min(pos,S-1),p=ch[p][0];
			else sz=S,p=ch[p][1];
		}
		ins(pos,a[i]),splay(tot),val[tot]+=1ll*(pos-1)*a[i],add(ch[tot][1],a[i]);
	}
	DFS(RT,0);
	for(re int i=1;i<=n;++i)ans=max(ans,sum[i]=sum[i-1]+T[i+1]);
	printf("%lld",ans);
}