#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3fll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,R,B,cx[N],cy[N],dx[N],dy[N],d[N];
int bx[N],by[N],lenx,leny;
struct Point{
	int x,y;
}p[N];
namespace MCMF{
	int head[N],pre[N];
	int ecnt,S,T;
	struct Edge{
		int nxt,to,val;
		ll cost;
	}edge[N<<5];
	void add(int a,int b,int c,ll d){
		edge[++ecnt]={head[a],b,c,d};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c,ll d){
		add(a,b,c,d);
		add(b,a,0,-d);
	}
	void init(int _S,int _T){
		memset(head,0,sizeof(head));
		ecnt=1;
		S=_S,T=_T;
	}
	int vis[N];
	ll mincost,dis[N];
	queue<int> q;
	bool SPFA(){
		memset(dis,0x3f,sizeof(dis));
		q.push(S);
		dis[S]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(edge[i].val&&dis[v]>dis[u]+edge[i].cost){
					dis[v]=dis[u]+edge[i].cost;
					if(!vis[v]){
						q.push(v),vis[v]=1;
					}
				}
			}
		}
		return dis[T]<infll;
	}
	int dfs(int u,int limit){
		if(u==T)return limit;
		int flow=0;
		vis[u]=1;
		for(int &i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]==dis[u]+edge[i].cost&&!vis[v]&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
				mincost+=1LL*k*edge[i].cost;
			}
			if(!limit)break;
		}
		vis[u]=0;
		if(!flow)dis[u]=infll;
		return flow;	
	}
	pair<int,ll> Dinic(){
		mincost=0;
		int maxflow=0;
		for(int i=1;i<=T;++i){
			pre[i]=head[i];
		}
		while(SPFA()){
			maxflow+=dfs(S,inf);
			for(int i=1;i<=T;++i){
				head[i]=pre[i];
			}
		}
		return make_pair(maxflow,mincost);
	}
}
int main(){
	n=read(),m=read(),R=read(),B=read();
	bool flag=0;
	if(R<B)swap(R,B),flag=1;
	for(int i=1;i<=n;++i){
		p[i].x=bx[i]=read(),p[i].y=by[i]=read();
	}
	sort(bx+1,bx+n+1);
	sort(by+1,by+n+1);
	lenx=unique(bx+1,bx+n+1)-bx-1;
	leny=unique(by+1,by+n+1)-by-1;
	for(int i=1;i<=n;++i){
		p[i].x=lower_bound(bx+1,bx+lenx+1,p[i].x)-bx;
		p[i].y=lower_bound(by+1,by+leny+1,p[i].y)-by;
		++cx[p[i].x],++cy[p[i].y];
	}
	int s=lenx+leny+1,t=s+1;
	MCMF::init(t+1,t+2);
	for(int i=1;i<=n;++i){
		MCMF::adde(p[i].x,p[i].y+lenx,1,R-B);
	}
	for(int i=1;i<=lenx;++i){
		dx[i]=cx[i];
	}
	for(int i=1;i<=leny;++i){
		dy[i]=cy[i];
	}
	for(int i=1;i<=m;++i){
		int t=read(),l=read(),d=read();
		if(t==1){
			int x=lower_bound(bx+1,bx+lenx+1,l)-bx;
			if(bx[x]^l)continue;
			dx[x]=min(dx[x],d);
		}
		else{
			int x=lower_bound(by+1,by+leny+1,l)-by;
			if(by[x]^l)continue;
			dy[x]=min(dy[x],d);
		}
	}
	for(int i=1;i<=lenx;++i){
		int l=(cx[i]-dx[i]+1)>>1;
		int r=(cx[i]+dx[i])>>1;
		if(l>r)return !printf("-1\n");
		MCMF::adde(s,i,r-l,0);
		d[s]-=l,d[i]+=l;
	}
	for(int i=1;i<=leny;++i){
		int l=(cy[i]-dy[i]+1)>>1;
		int r=(cy[i]+dy[i])>>1;
		if(l>r)return !printf("-1\n");
		MCMF::adde(i+lenx,t,r-l,0);
		d[i+lenx]-=l,d[t]+=l;
	}
	int need=0;
	for(int i=1;i<=t;++i){
		if(d[i]>0){
			MCMF::adde(MCMF::S,i,d[i],0);
			need+=d[i];
		}
		else{
			MCMF::adde(i,MCMF::T,-d[i],0);
		}
	}
	MCMF::adde(t,s,inf,0);
	auto [flow,cost]=MCMF::Dinic();
	if(flow^need){
		return !printf("-1\n");
	}
	printf("%lld\n",cost+1LL*B*n);
	for(int i=1;i<=n;++i){
		putchar((MCMF::edge[i<<1].val^flag)?'b':'r');
	}
	return 0;
}