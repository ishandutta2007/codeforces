#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
const int Mxdt=1000000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,m,head[200002],d[200002],cnt,mn,mx,ans,sum,f[200002],dfn[200002],low[200002],stk[200002],tp,ist[200002],bl[200002],tim,blk,vis[200002],q;
char v[200002];
struct edge{int to,next,w;}e[2000002];
inline void add(re int x,re int y,re int w){e[++cnt]=(edge){y,head[x],w},head[x]=cnt;}
inline int Gcd(re int x,re int y){return y?Gcd(y,x%y):x;}
inline int Abs(re int x){return x>0?x:-x;}
inline void dfs(re int x,re int w){
	if(v[x]){
		ans=Gcd(ans,Abs(w-d[x]));
		return;
	}
	d[x]=w,mx=max(mx,w),mn=min(mn,w),v[x]=1;
	for(re int i=head[x];i;i=e[i].next)if(bl[x]==bl[e[i].to])dfs(e[i].to,w+e[i].w);
}
inline void tj(re int x){
	dfn[x]=low[x]=++tim,stk[++tp]=x,ist[x]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].w>0){
			if(!dfn[e[i].to])tj(e[i].to),low[x]=min(low[x],low[e[i].to]);
			else if(ist[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
		}
	if(dfn[x]==low[x]){
		++blk;
		do{
			ist[stk[tp]]=0;
			bl[stk[tp]]=blk;
			--tp;
		}while(stk[tp+1]!=x);
	}
}
signed main(){
	n=read(),m=read();
	for(re int i=1,x,y,w;i<=m;++i)x=read(),y=read(),w=read(),add(x,y,w),add(y,x,-w);
	for(re int i=1;i<=n;++i)if(!dfn[i])tj(i);
	for(re int i=1;i<=n;++i){
		if(!vis[bl[i]]){
			vis[bl[i]]=1;
			ans=0,dfs(i,0);
			f[bl[i]]=ans;
		}
	}
	q=read();
	while(q--){
		re int x=bl[read()],y=read(),z=read();y=z-y;y%=z;
		re int s=Gcd(z,f[x]);
		if(y%s==0)puts("YES");
		else puts("NO");
	}
}