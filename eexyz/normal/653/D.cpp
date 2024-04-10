#include<bits/stdc++.h>
using namespace std;
#define eps 1e-12
#define db long double
#define N 5000 
int xx[N],yy[N],vv[N];
queue<int>q;
int dis[N],tot,s,t,n,m,X,res,ret,nxt[N],nd[N],cur[N],val[N],to[N];
inline void add(int x,int y,int v){
	nxt[++tot]=nd[x];
	nd[x]=tot;val[tot]=v;to[tot]=y;
}
bool bfs(){
	memset(dis,-1,sizeof(dis));q.push(s);dis[s]=0;
	int x,i;
	while(q.size()){
		x=q.front();q.pop();
		for(i=nd[x];i;i=nxt[i]){
			if(val[i]&&dis[to[i]]==-1){
				dis[to[i]]=dis[x]+1;q.push(to[i]);
			}
		}
	}
	return dis[t]!=-1;
}
int dfs(int now,int flow){
	if(now==t)return flow;
	int fl=0,qwq;
	for(int & i=cur[now];i;i=nxt[i]){
		if(val[i]&&dis[to[i]]==dis[now]+1){
			qwq=dfs(to[i],min(val[i],flow));
			flow-=qwq;fl+=qwq;
			val[i]-=qwq;
			val[i^1]+=qwq;
			if(!flow)break;
		}
	}
	return fl;
}
int dinic(){
	ret=0;
	while(bfs()){
		for(int i=1;i<=n;++i)cur[i]=nd[i];
		ret+=dfs(s,10000000);
//		cout<<ret<<"\n";
		if(ret>1000000)return ret;
	}
	return ret;
}
inline int check(double x){
	tot=1;memset(nd,0,sizeof(nd));
	s=1;t=n;
	for(int i=1;i<=m;++i)add(xx[i],yy[i],min((long long)(vv[i]/x),1000000ll)),add(yy[i],xx[i],0);
	return dinic();
}
int i;
db l,r,mid;
int main(){
	cin>>n>>m>>X;
	for(i=1;i<=m;++i)cin>>xx[i]>>yy[i]>>vv[i];
	l=0;r=1000000;
	while(l<r-eps){
		mid=(l+r)/2.0;
		if(check(mid)>=X){
			l=mid;
		}
		else r=mid;
	}l=(l+r)/2;
	printf("%.10Lf",l*X);
}