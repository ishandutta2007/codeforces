#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define rep(u) for(int&i=c[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e5+1,INF=0x3f3f3f3f;
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
queue<int>q;
int n,m,g,tot=1,S,T,ans,sum;
int a[N],h[N],c[N],dis[N],cnt[N];
struct edge{int t,n,w;}e[N];
V add_edge(int x,int y,int w){
	e[++tot]=(edge){y,h[x],w},h[x]=tot;
	e[++tot]=(edge){x,h[y],0},h[y]=tot;
}
V input(){
	n=getint(),m=getint(),g=getint(),S=n+m+1,T=S+1;
	FOR(i,1,n)a[i]=getint();
	FOR(i,1,n)
		if(a[i])add_edge(i,T,getint());
		else add_edge(S,i,getint());
	int opt,w,k;
	FOR(i,1,m)
		if(getint()){
			ans+=w=getint(),k=getint();
			while(k--)add_edge(getint(),i+n,INF);
			add_edge(i+n,T,w+getint()*g);
		}
		else{
			ans+=w=getint(),k=getint();
			while(k--)add_edge(i+n,getint(),INF);
			add_edge(S,i+n,w+getint()*g);
		}
}
I bfs(){
	FOR(i,1,T)dis[i]=cnt[i]=0;
	q.push(T),dis[T]=1;
	for(int u;!q.empty();q.pop())REP(u=q.front())
		if(e[i^1].w&&!dis[v])dis[v]=dis[u]+1,q.push(v);
	FOR(i,1,T)cnt[dis[i]]++;
	return dis[S];
}
I dfs(int u,int res){
	if(u==T)return res;
	int f,out=0;
	rep(u)if(dis[u]==dis[v]+1&&e[i].w){
		f=dfs(v,min(res,e[i].w)),e[i].w-=f,e[i^1].w+=f,res-=f,out+=f;
		if(!res)return out;
	}
	if(!--cnt[dis[u]++])dis[S]=T+1;
	return cnt[dis[u]]++,out;
}
V work(){
	while(bfs())while(dis[S]<=T)
		copy(h+1,h+1+T,c+1),ans-=dfs(S,INF);
	cout<<ans;
}
int main(){
	input();
	work();
	return 0;
}