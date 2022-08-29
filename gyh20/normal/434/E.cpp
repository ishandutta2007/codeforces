#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,M,K,X,cnt,head[100002],I[100002],O[100002],mn,siz[100002],pos,stk[100002],tp,v[100002],Z,v1[1000002],v2[1000002],cc,nxt[1000002];
char vs[100002];
long long ans;
struct edge{int to,next;}e[200002];
const int B=131071;
struct Hash{
	int h[B+1],stk[B+1],tp;
	inline void Ins(re int x){
		re int tmp=x&B;
		for(re int i=h[tmp];i;i=nxt[i])if(v1[i]==x){++v2[i];return;}
		if(!h[tmp])stk[++tp]=tmp;
		v1[++cc]=x,v2[cc]=1,nxt[cc]=h[tmp],h[tmp]=cc;
	}
	inline int ask(re int x){
		re int tmp=x&B;
		for(re int i=h[tmp];i;i=nxt[i])if(v1[i]==x)return v2[i];
		return 0;
	}
	inline void clr(){
		cc=0;
		for(re int i=1;i<=tp;++i)h[stk[i]]=0;
		tp=0;
	}
}V1,V2;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	re int mx=0;siz[x]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y&&!vs[e[i].to])
			dfs(e[i].to,x),siz[x]+=siz[e[i].to],mx=max(mx,siz[e[i].to]);
	mx=max(mx,Z-siz[x]);
	if(mx<mn)mn=mx,pos=x;
}
inline void calc(re int x,re int y,re int z1,re int z2,re int z){
	z1=(1ll*z1*K+v[x])%M,z2=(1ll*z*v[x]+z2)%M;
	O[x]+=V1.ask(1ll*(X-z1+M)*ksm(1ll*z*K%M,M-2)%M),I[x]+=V2.ask(z2);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y&&!vs[e[i].to])
			calc(e[i].to,x,z1,z2,1ll*z*K%M);
}
inline void ins(re int x,re int y,re int z1,re int z2,re int z){
	z1=(1ll*z1*K+v[x])%M,z2=(1ll*z*v[x]+z2)%M;
	V1.Ins(z2),V2.Ins(1ll*(X-z1+M)*ksm(1ll*z*K%M,M-2)%M);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y&&!vs[e[i].to])
			ins(e[i].to,x,z1,z2,1ll*z*K%M);
}
inline void dfz(re int x,re int y){
	Z=y,mn=n+1,dfs(x,x),x=pos,vs[x]=1;
	V1.clr(),V2.clr(),V1.Ins(v[x]%M),V2.Ins(1ll*(X-v[x]+M)*ksm(K,M-2)%M);tp=0;
	for(re int i=head[x];i;i=e[i].next)
		if(!vs[e[i].to]){
			calc(e[i].to,x,0,0,1);
			ins(e[i].to,x,v[x]%M,v[x]%M,K);
			stk[++tp]=e[i].to;
		}
	O[x]+=V1.ask(X),I[x]+=V2.ask(0);
	V1.clr(),V2.clr();
	for(re int i=tp;i;--i)calc(stk[i],x,0,0,1),ins(stk[i],x,v[x]%M,v[x]%M,K);
	for(re int i=head[x];i;i=e[i].next)
		if(!vs[e[i].to])
			dfz(e[i].to,siz[e[i].to]>siz[x]?y-siz[x]:siz[e[i].to]);
}
int main(){
	n=read(),M=read(),K=read(),X=read();
	for(re int i=1;i<=n;++i)v[i]=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfz(1,n);
	for(re int i=1;i<=n;++i)ans-=2ll*I[i]*(n-I[i])+2ll*O[i]*(n-O[i])+1ll*I[i]*(n-O[i])+1ll*O[i]*(n-I[i]);
	ans/=2,ans+=1ll*n*n*n;
	printf("%lld",ans);
}