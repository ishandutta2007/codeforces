#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int p[1205],n,m,head[1205],cnt=1,S,T,v[1205],dis[1205],ans1,ans2,rt1,rt2,a[1002],sz[1002],tg1[1002],tg2[1002];
deque<int>q;
struct edge{int to,next,w,w1;}e[30005];
inline void add(re int x,re int y,re int z,re int w){if(z<0){puts("-1");exit(0);}e[++cnt]=(edge){y,head[x],z,w},head[x]=cnt;e[++cnt]=(edge){x,head[y],0,-w},head[y]=cnt;}
inline bool spfa(){
	memset(v,0,sizeof(v)),memset(p,0,sizeof(p)),memset(dis,0x3f,sizeof(dis));
	dis[S]=0,q.push_front(S),v[S]=1;
	while(!q.empty()){
		re int x=q.front();q.pop_front();v[x]=0;
		for(re int i=head[x];i;i=e[i].next)
			if(e[i].w&&dis[x]+e[i].w1<dis[e[i].to]){
				dis[e[i].to]=dis[x]+e[i].w1,p[e[i].to]=i;
				if(!v[e[i].to]){
					v[e[i].to]=1;
					if(q.size()&&dis[e[i].to]<dis[q.front()])q.push_front(e[i].to);
					else q.push_back(e[i].to);
				}
			}
	}
	return dis[T]<1e9;
}
inline void dfs(){
	re int tmp=1<<30;
	for(re int i=T;i^S;i=e[p[i]^1].to)tmp=min(tmp,e[p[i]].w);
	for(re int i=T;i^S;i=e[p[i]^1].to)e[p[i]].w-=tmp,e[p[i]^1].w+=tmp;
	ans1+=tmp,ans2+=tmp*dis[T];
}
vector<int>G1[502],G2[502];
inline void dfs1(re int x,re int y,re int z){
	if(~tg1[x])z=x;
	add(z,x,1,0),add(x,x+n,1,-a[x]),sz[x]=0;
	for(auto o:G1[x])if(o^y)dfs1(o,x,z),sz[x]+=sz[o];
	if(~tg1[x])add(S,x,tg1[x]-sz[x],0),sz[x]=tg1[x];
}
inline void dfs2(re int x,re int y,re int z){
	if(~tg2[x])z=x;
	add(x+n,z+n,1,0),sz[x]=0;
	for(auto o:G2[x])if(o^y)dfs2(o,x,z),sz[x]+=sz[o];
	if(~tg2[x])add(x+n,T,tg2[x]-sz[x],0),sz[x]=tg2[x];
}
int main(){
	memset(tg1,-1,sizeof(tg1)),memset(tg2,-1,sizeof(tg2));
	n=read(),rt1=read(),rt2=read(),S=n+n+1,T=S+1;
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),G1[x].push_back(y),G1[y].push_back(x);
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),G2[x].push_back(y),G2[y].push_back(x);
	re int k1=read(),lmt1=0,lmt2=0;
	while(k1--){
		re int x=read(),y=read();if(x==rt1)lmt1=y;
		tg1[x]=y;
	}
	re int k2=read();
	while(k2--){
		re int x=read(),y=read();if(x==rt2)lmt2=y;
		tg2[x]=y;
	}
	dfs1(rt1,rt1,rt1),dfs2(rt2,rt2,rt2);
	while(spfa())dfs();
	if(lmt1==lmt2&&lmt1==ans1)printf("%d",-ans2);
	else puts("-1");
}