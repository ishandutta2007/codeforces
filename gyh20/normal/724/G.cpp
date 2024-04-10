#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
#define ll long long
const int M=1e9+7; 
using namespace std;
const int Mxdt=100000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline ll read(){
	re ll t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,head[100002],cnt,v[100002],C[100002],s,sz,ans,F[62][62],num[62],pw[62],D[100002];
ll dis[100002],p[62],z,B;
struct edge{int to,next;ll w;}e[400002];
inline void add(re int x,re int y,re ll w){e[++cnt]=(edge){y,head[x],w},head[x]=cnt;}
inline void ins(re ll x){
	B|=x;
	for(re int i=59;~i;--i)
		if((x>>i)&1){
			if(!p[i]){p[i]=x,++s;return;}
			x^=p[i];
		}
}
inline void dfs(re int x,re ll y){
	if(v[x]){
		if(y^dis[x])ins(y^dis[x]);
		return;
	}
	v[x]=1,dis[x]=y,++sz;
	for(re int i=59;~i;--i)if((y>>i)&1)++num[i];
	for(re int i=head[x];i;i=e[i].next)dfs(e[i].to,y^e[i].w);
}
int main(){
	n=read(),m=read();
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),add(x,y,z=read()),add(y,x,z);
	for(re int i=pw[0]=1;i<=59;++i)pw[i]=Mod(pw[i-1]<<1);
	for(re int i=0;i<=59;++i)for(re int j=0;j<=59;++j)F[i][j]=1ll*pw[i]*pw[j]%M;
	for(re int i=1;i<=n;++i)C[i]=(1ll*i*(i-1)>>1)%M;
	for(re int i=1;i<=n;++i)
		if(!v[i]){
			memset(p,0,sizeof(p)),memset(num,0,sizeof(num)),s=sz=B=0;
			dfs(i,0);
			for(re int j=1;j<=sz;++j)D[j]=1ll*j*(sz-j)%M;
			for(re int j=59;~j;--j)
				if((B>>j)&1)add(ans,1ll*C[sz]*F[j][s-1]%M);
				else if(num[j])add(ans,1ll*D[num[j]]*F[j][s]%M);
		}
	printf("%d",ans);
}