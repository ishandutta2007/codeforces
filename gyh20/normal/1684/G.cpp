#include<cstdio>
#include<cstring>
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
inline int min(re int x,re int y){return x<y?x:y;}
int gap[10002],dis[10002],n,head[10002],cnt=1,S,T,q[10002],hd,tl,m,v[10002];
struct edge{int to,next,w;}e[8000002];
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;e[++cnt]=(edge){x,head[y],0},head[y]=cnt;}
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
	while(dis[S]<T)ans+=dfs(S,1e9);
	return ans;
}
char usd[1002];
int ansa[20002],ansb[20002],k,a[20002];
signed main(){
	n=read(),m=read(),S=n+1,T=S+1;
	for(re int i=1;i<=n;++i)a[i]=read();
	re int num=0;
	for(re int i=1;i<=n;++i)if(a[i]*3>m)add(S,i,1),++num;else add(i,T,1);
	for(re int i=1;i<=n;++i)
		if(a[i]*3>m){
			for(re int j=1;j<=n;++j)
				if(a[i]+a[j]+a[i]<=m&&a[i]%a[j]==0)
					add(i,j,1);
		}
	if(SAP()^num)return puts("-1"),0;
	for(re int i=1;i<=n;++i)
		if(a[i]*3>m){
			re int pos=0;
			for(re int j=head[i];j;j=e[j].next)if(!e[j].w)pos=e[j].to;
			++k;
			ansa[k]=a[i]+a[i]+a[pos],ansb[k]=a[i]+a[pos],usd[i]=usd[pos]=1;
		}
	for(re int i=1;i<=n;++i)if(!usd[i])++k,ansa[k]=a[i]*3,ansb[k]=a[i]*2;
	printf("%lld\n",k);
	for(re int i=1;i<=k;++i)printf("%lld %lld\n",ansa[i],ansb[i]);
}