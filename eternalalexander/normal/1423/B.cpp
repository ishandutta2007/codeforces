#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=20005,M=400005,inf=0x3f3f3f3f;
int n,m,s,t;

int num=1,flow=0;
int b[M],nt[M],cap[M],p[N];
queue<int> q;
int d[N],cur[N];
inline void add(int u,int v,int w){
	num++;b[num]=v,cap[num]=w,nt[num]=p[u],p[u]=num;
	num++;b[num]=u,cap[num]=0,nt[num]=p[v],p[v]=num;
}
inline int bfs(){
	memset(d,-1,sizeof(d));
	d[s]=0;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=p[u];i;i=nt[i]){
			int v=b[i];
			if(cap[i]>0&&d[v]<0) {
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return d[t]!=-1;
}
int dfs(int u,int f){
	if(u==t) return f;
	int w,tot=0;
	for(int &i=cur[u];i;i=nt[i]){
		int v=b[i];
		if(cap[i]>0&&d[v]==d[u]+1&&(w=dfs(v,min(f,cap[i])))){
			cap[i]-=w,cap[i^1]+=w;
			f-=w,tot+=w;
			if(f<=0) break;
		}
	}
	return tot;
}
inline int max_flow(){
	flow=0;
	while(bfs()){
		memcpy(cur,p,sizeof(p));
		flow+=dfs(s,inf);
	}
	return flow;
}
struct edge{
	int u,v,w;
}e[M];
inline bool check(int x){
	num=1;memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++) add(s,i,1),add(i+n,t,1);
	for(int i=1;i<=m;i++) if(e[i].w<=x) add(e[i].u,e[i].v+n,e[i].w);
	return max_flow()==n;
}
int main(){
	n=read(),m=read();
	s=0,t=2*n+1;
	for(int i=1;i<=m;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	int l=1,r=1e9,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}