#include<cstdio>
#include<cstring>
#define re register
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
int gap[1000002],dis[1000002],n,head[1000002],cnt=1,S,T,q[1000002],hd,tl,m,v[1000002],h1[1000002],pos[50002],a[50002];
struct edge{int to,next,w;}e[8000002];
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt,e[++cnt]=(edge){x,head[y],0},head[y]=cnt;}
inline int bfs(){
	for(re int i=0;i<=T;++i)dis[i]=-1;q[hd=tl=1]=S,dis[S]=0;
	while(hd<=tl){
		re int x=q[hd++];
		for(re int i=head[x];i;i=e[i].next)if(e[i].w&&dis[e[i].to]==-1)dis[e[i].to]=dis[x]+1,q[++tl]=e[i].to;
	}
	return dis[T]>=0;
}
inline int dfs(re int x,re int y){
	if(x==T)return y;
	re int dlt=0;
	for(re int i=head[x];y&&(head[x]=i);i=e[i].next)
		if(dis[e[i].to]==dis[x]+1&&e[i].w){
			re int z=dfs(e[i].to,min(y,e[i].w));
			if(!z)dis[e[i].to]=-1;
			else e[i].w-=z,y-=z,e[i^1].w+=z,dlt+=z;
		}
	return dlt;
}
int main(){
	int t=read();
	while(t--){
		n=read(),S=n+n+n+n+1,T=S+1,cnt=1,head[S]=head[T]=0;
		for(re int i=1;i<=n;++i)pos[a[i]=read()]=i,head[i]=head[i+n]=head[i+n+n]=head[i+n+n+n]=0;
		for(re int i=1;i<=n;++i)
			for(re int j=a[i]+a[i];j<=50000;j+=a[i])
				if(pos[j])
					add(pos[j],i+n+n,1<<30),add(pos[j],i+n+n+n,1<<30),add(pos[j]+n,i+n+n+n,1<<30);
		for(re int i=1;i<=n;++i)add(S,i,1),add(S,i+n,1),add(i+n+n,T,1),add(i+n+n+n,T,1),add(i,i+n+n+n,1<<30);
		re int s=0;
		while(bfs()){
			for(re int i=1;i<=T;++i)h1[i]=head[i];
			s+=dfs(S,1<<30);
			for(re int i=1;i<=T;++i)head[i]=h1[i];
		}
		for(re int i=1;i<=n;++i)pos[a[i]]=0;
		printf("%d\n",s-n);
	}
}