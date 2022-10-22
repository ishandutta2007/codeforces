#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n;
#define Maxn 505
#define cout cerr
#define FR first
#define SE second
int a[Maxn];

int cnt;
namespace G{
	#define V 2005
	#define E 100010
	int head[V],v[E<<1],w[E<<1],cap[E<<1],nxt[E<<1],tot=0;
	const int inf=1000000000;
	inline void add_edge(int s,int e,int c,int t){
		tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;cap[tot]=c;w[tot]=t;
		tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;cap[tot]=0;w[tot]=-t;
	}
	int D[V],dist[V];
	int S,T;
	queue<int> q;bool inq[V];
	bool SPFA(){
		rep(i,1,cnt)D[i]=-inf;
		D[S]=0;
		q.push(S);inq[S]=true;
		while(!q.empty()){
			int u=q.front();q.pop();inq[u]=false;
			for(int i=head[u];i;i=nxt[i])
				if(cap[i]&&D[u]+w[i]>D[v[i]]){
					D[v[i]]=D[u]+w[i];
					if(!inq[v[i]]){
						inq[v[i]]=true;
						q.push(v[i]);
					}
				}
		}
		return D[T]!=-inf;
	}
	
	priority_queue<pii> Q;
	bool Dij(){
		rep(i,1,cnt)dist[i]=-inf;
		Q.push(pii(0,S));dist[S]=0;
		while(!Q.empty()){
			pii x=Q.top();Q.pop();int u=x.SE;
			if(x.FR!=dist[u])continue;
			for(int i=head[u];i;i=nxt[i])
				if(cap[i]&&dist[u]+D[u]+w[i]-D[v[i]]>dist[v[i]]){
					dist[v[i]]=dist[u]+D[u]+w[i]-D[v[i]];
					Q.push(pii(dist[v[i]],v[i]));
				}
		}
		return dist[T]!=-inf;
	}
	int Ans=0;
	int vis[V],visT;
	int aug(int u,int flow){
		if(u==T||!flow)return flow;
		int res=0;
		vis[u]=visT;
		for(int i=head[u];i;i=nxt[i])
			if(cap[i]&&vis[v[i]]!=visT&&dist[v[i]]==(dist[u]+D[u]+w[i]-D[v[i]])){
				int t=aug(v[i],min(flow,cap[i]));
				cap[i]-=t;res+=t;Ans+=w[i]*t;
				if(i&1)cap[i+1]+=t;
				else cap[i-1]+=t;
				flow-=t;
			}
		return res;
	}
	void solve(){
		SPFA();
		while(SPFA()){
			visT++;
			aug(S,inf);
			rep(i,1,cnt)
				if(dist[i]==-inf)D[i]=-inf;
				else D[i]+=dist[i];
		}
		bool flag=false;
		for(int i=head[S];i;i=nxt[i])
			if(cap[i]){
				puts("-1");
				flag=true;
				exit(0);
			}
		for(int i=head[T];i;i=nxt[i])
			if(cap[i-1]){
				puts("-1");
				flag=true;
				exit(0);
			}
		if(!flag){
			printf("%d\n",Ans);
		}
	}
}

struct Tree{
	int rt;
	int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
	int type[Maxn];
	void init(){
		memset(type,-1,sizeof(int)*(n+1));
	}
	inline void add_edge(int s,int e){
		tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
		tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
	}
	int stk[Maxn],tp=0;
	int dfs(int u,int f,bool z){
		int pre=tp;
		stk[++tp]=u;
		int res=0;
		for(int i=head[u];i;i=nxt[i])
			if(v[i]^f){
				res+=dfs(v[i],u,z);
			}
		if(type[u]!=-1){
			int cur=type[u]-res;
			if(cur<0){
				puts("-1");
				exit(0);
			}
			if(z){
			cnt++;
			G::add_edge(G::S,cnt,cur,0);
			per(i,tp,pre+1)G::add_edge(cnt,stk[i],1,0);
			tp=pre;
		}else{
			cnt++;
			G::add_edge(cnt,G::T,cur,0);
			per(i,tp,pre+1)G::add_edge(stk[i]+n,cnt,1,0);
			tp=pre;
		}
			return type[u];
		}
		return res;
	}
}T1,T2;

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(n);cnt=2*n+2;G::S=2*n+1;G::T=2*n+2;
	T1.init();T2.init();
	rd(T1.rt);rd(T2.rt);
	rep(i,1,n){
		rd(a[i]);
		G::add_edge(i,i+n,1,a[i]);
	}
	int s,e;
	rep(i,1,n-1){
		rd(s);rd(e);
		T1.add_edge(s,e);	
	}
	rep(i,1,n-1){
		rd(s);rd(e);
		T2.add_edge(s,e);	
	}
	int q;rd(q);
	while(q--){
		rd(s);rd(e);
		T1.type[s]=e;
	}
	rd(q);
	while(q--){
		rd(s);rd(e);
		T2.type[s]=e;
	}
	T1.dfs(T1.rt,0,1);T2.dfs(T2.rt,0,0);
	G::solve();
	return 0;
}/*
4 1 2
1 2 3 4
1 2
1 3
3 4
1 2
2 3
1 4
2
1 3
4 1
1
2 3
*/