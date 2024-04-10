#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
typedef long long ll;
const ll infll=0x3f3f3f3f3f3f3f3fll;
#define N 4422
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
int n,a[N],b[N];
namespace MCMF{
	int head[N*3];
	int ecnt,S,T;
	struct Edge{
		int nxt,to,val,cost;
	}edge[N<<6];
	void add(int a,int b,int c,int d){
		edge[++ecnt]={head[a],b,c,d};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c,int d){
		add(a,b,c,d);
		add(b,a,0,-d);
	}
	void init(int _S,int _T){
		memset(head,0,sizeof(head));
		ecnt=1;
		S=_S,T=_T;
	}
	int vis[N*3],dis[N*3],mincost;
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
		return dis[T]<inf;
	}
	int dfs(int u,int limit){
		if(u==T)return limit;
		int flow=0;
		vis[u]=1;
		for(int i=head[u];i&&limit;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]==dis[u]+edge[i].cost&&!vis[v]&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
				mincost+=k*edge[i].cost;
			}
		}
		vis[u]=0;
		if(!flow)dis[u]=inf;
		return flow;	
	}
	pair<int,int> Dinic(){
		mincost=0;
		int maxflow=0;
		while(SPFA()){
			maxflow+=dfs(S,inf);
		}
		return make_pair(maxflow,mincost);
	}
}
int mn;
int Solve(int x){
	static int p[N];
	MCMF::init(6*n+1,6*n+2);
	int S=6*n+1,T=6*n+2;
	for(int i=1;i<=n;++i){
		MCMF::adde(S,i,1,0);
		MCMF::adde(i,i+n,1,0);
		MCMF::adde(i,2*n+i,1,0);
		
		MCMF::adde(5*n+i,T,1,0);
		MCMF::adde(3*n+i,5*n+i,1,0);	
		MCMF::adde(4*n+i,5*n+i,1,0);
	}
	for(int i=1;i<=n;++i){
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return b[i]<b[j];});
	for(int i=2;i<=n;++i){
		MCMF::adde(n+p[i],n+p[i-1],n,0);
	}
	for(int i=1;i<=(n<<1);++i){
		int u=lower_bound(p+1,p+n+1,i,[&](int i,int j){return b[i]<b[j];})-p;
		if(u<=n)MCMF::adde(n+p[u],2*n+i,n,1);	
	}
	for(int i=1;i<=n;++i){
		p[i]=n+i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return 1LL*x*a[i]+b[i]<1LL*x*a[j]+b[j];});
	for(int i=2;i<=n;++i){
		MCMF::adde(4*n+p[i]-n,4*n+p[i-1]-n,n,0);
	}
	
	for(int i=1;i<=(n<<1);++i){
		int u=upper_bound(p+1,p+n+1,i,[&](int i,int j){return 1LL*x*a[i]+b[i]<1LL*x*a[j]+b[j];})-p-1;
		if(u>=1)MCMF::adde(2*n+i,4*n+p[u]-n,n,1);
	}
	return MCMF::Dinic().second;
}
inline bool check(int T){
	static int p[N];
	for(int i=1;i<=(n<<1);++i){
		p[i]=i;
	}
	sort(p+1,p+(n<<1)+1,[&](int i,int j){return b[i]==b[j]?a[i]>a[j]:b[i]<b[j];});
	ll mx=0;
	vector<ll> A,B;
	for(int i=1;i<=(n<<1);++i){
		ll w=1LL*a[p[i]]*T+b[p[i]];
		mx=max(mx,w);
		if(p[i]<=n)A.push_back(mx);
		else B.push_back(w);
	}
	sort(B.begin(),B.end());
	for(int i=0;i<n;++i){
		if(A[i]<B[i])return false;
	}
	return true;
}
int main(){
	n=read();
	for(int i=1;i<=(n<<1);++i){
		a[i]=read(),b[i]=read();
	}
	int l=0,r=1e9+233,ans=-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=r=mid;
		}
		else{
			l=mid+1;
		}
	}
	if(!~ans)return !printf("-1\n");
	mn=Solve(ans);
	printf("%d %d",ans,mn);
	return 0;
}