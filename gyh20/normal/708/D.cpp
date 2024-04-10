#include<cstdio>
#include<cstring>
using namespace std;
#define re register
int q[100002],n,m,hd,tl,p[402],dis[402],S,T,head[402],v[402],ans1,cnt=1,ans2,d[402];
#define gc getchar
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
struct edge{int to,next,w,v;}e[30002];
inline int min(re int x,re int y){return x<y?x:y;}
inline bool SPFA(){
	memset(p,0,sizeof(p)),memset(dis,0x3f,sizeof(dis)),memset(v,0,sizeof(v));
	q[hd=tl=1]=S,dis[S]=0,v[S]=1;
	while(hd<=tl){
		re int x=q[hd++];v[x]=0;
		for(re int i=head[x];i;i=e[i].next)
			if(e[i].w&&dis[e[i].to]>dis[x]+e[i].v){
				dis[e[i].to]=dis[x]+e[i].v;
				p[e[i].to]=i;
				if(!v[e[i].to])v[e[i].to]=1,q[++tl]=e[i].to;
			}
	}
	return dis[T]<1e9;
}
inline void add(re int x,re int y,re int w,re int v){
	e[++cnt]=(edge){y,head[x],w,v},head[x]=cnt;
	e[++cnt]=(edge){x,head[y],0,-v},head[y]=cnt;
}
inline void dfs(){
	re int tmp=2147483647;
	for(re int x=T;x^S;x=e[p[x]^1].to)tmp=min(tmp,e[p[x]].w);
	ans2+=tmp*dis[T],ans1+=tmp;
	for(re int x=T;x^S;x=e[p[x]^1].to)e[p[x]].w-=tmp,e[p[x]^1].w+=tmp;
}
int main(){
	n=read(),m=read(),S=n+1,T=S+1;
	for(re int i=1,x,y,c,f;i<=m;++i){
		x=read(),y=read(),c=read(),f=read();
		if(c<f)ans2+=f-c,add(x,y,f-c,0);
		else add(y,x,c-f,1);
		d[x]+=f,d[y]-=f;
		add(y,x,1<<29,2),add(x,y,min(c,f),1); 
	}add(1,n,1<<29,0);
	for(re int i=1;i<=n;++i)if(d[i]>0)add(S,i,d[i],0);else add(i,T,-d[i],0);
	while(SPFA())dfs();
	printf("%d",ans2);
}