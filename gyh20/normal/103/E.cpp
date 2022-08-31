#include<cstdio>
#include<cstring>
#define int long long
#define re register
using namespace std;
const int Mxdt=1000000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	re int t=0,f=0;re char v=gc();
	while(v<'0')f|=(v=='-'),v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return f?-t:t;
}
inline int min(re int x,re int y){return x<y?x:y;}
int gap[1000002],dis[1000002],n,head[1000002],cnt=1,S,T,q[1000002],hd,tl,m,v[1000002],inf=1e14;
struct edge{int to,next,w;}e[8000002];
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt,e[++cnt]=(edge){x,head[y],0},head[y]=cnt;}
inline int dfs(re int x,re int y){
	if(x==T)return y;
	re int tmp=0;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].w&&dis[x]==dis[e[i].to]+1){
			re int dlt=dfs(e[i].to,min(y,e[i].w));
			y-=dlt,e[i].w-=dlt,e[i^1].w+=dlt,tmp+=dlt;
			if(!y||dis[S]==T)return tmp;
		}
	if(!(--gap[dis[x]]))dis[S]=T;
	++gap[++dis[x]];
	return tmp;
}
inline int SAP(){
	dis[q[hd=tl=1]=T]=0,v[T]=1;
	while(hd<=tl){
		re int x=q[hd++];
		for(re int i=head[x];i;i=e[i].next)if(!v[e[i].to])v[e[i].to]=1,++gap[dis[e[i].to]=dis[x]+1],q[++tl]=e[i].to;
	}
	re int ans=0;
	while(dis[S]<T)ans+=dfs(S,1ll<<60);
	return ans;
}
signed main(){
	n=read(),S=n+n+1,T=S+1;
	for(re int i=1;i<=n;++i){
		re int x=read();
		while(x--)add(i,n+read(),inf);
		add(i+n,T,inf);
	}
	re int sum=0;
	for(re int i=1;i<=n;++i){
		re int x=read();
		add(S,i,-x+inf),sum+=x;
	}
	printf("%lld",sum-n*inf+SAP());
}