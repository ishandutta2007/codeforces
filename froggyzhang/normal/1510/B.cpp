/*qwq*/
#include<bits/stdc++.h>
using namespace std;
#define N 2333
const int inf=0x3f3f3f3f;
typedef long long ll;
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
int D,n;
namespace MCMF{
	int head[N];
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
	int vis[N],dis[N],mincost;
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
int a[N],nxt[N],las[N];
char s[N];
vector<int> ans;
int main(){
	D=read(),n=read();
	MCMF::init(2*n+1,2*n+2);
	for(int i=1;i<=n;++i){
		scanf("%s",s);
		for(int j=0;j<D;++j){
			if(s[j]-'0')a[i]|=1<<j;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		MCMF::adde(2*n+1,i,1,__builtin_popcount(a[i]));
		MCMF::adde(i,2*n+2,1,1);
		MCMF::adde(i+n,2*n+2,1,0);
		for(int j=1;j<=n;++j){
			if(i==j)continue;
			if((a[i]&a[j])==a[i]){
				MCMF::adde(i,j+n,1,-__builtin_popcount(a[i]));	
			}
		}
	}
	auto [flow,cost]=MCMF::Dinic();
	printf("%d\n",cost-1);
	for(int u=1;u<=n;++u){
		for(int i=MCMF::head[u];i;i=MCMF::edge[i].nxt){
			int v=MCMF::edge[i].to;
			if(!MCMF::edge[i].val&&v>n&&v<=2*n){
				nxt[u]=v-n;
				las[v-n]=u;
			}
		}	
	}
	for(int u=1;u<=n;++u){
		if(las[u])continue;
		for(int v=u;v;v=nxt[v]){
			for(int i=0;i<D;++i){
				if((a[v]^a[las[v]])>>i&1)ans.push_back(i);	
			}
		}
		ans.push_back(-1);
	}
	ans.pop_back();
	for(auto x:ans){
		if(x==-1)printf("R ");
		else printf("%d ",x);
	}
	return 0;
}