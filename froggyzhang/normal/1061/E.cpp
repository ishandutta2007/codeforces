#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 10010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,rt1,rt2,q1,q2,p1[N],p2[N],ans,w[N],tot;
vector<int> G1[N],G2[N];
int cnt,head[N],maxcost,S,T,dis[N],vis[N];
queue<int> q;
struct Edge{
	int to,nxt,val,cost;
}edge[N<<5];
void add(int a,int b,int c,int d){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].val=c;
	edge[cnt].cost=d;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
bool SPFA(){
	memset(dis,~0x3f,sizeof(dis));
	dis[S]=0;
	q.push(S);
	vis[S]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]<dis[u]+edge[i].cost&&edge[i].val){
				dis[v]=dis[u]+edge[i].cost;
				if(!vis[v]){
					vis[v]=1,q.push(v);
				}
			}
		}
	}
	return dis[T]>-inf;
}
int dfs(int u,int limit){
	if(u==T)return limit;
	vis[u]=1;
	int flow=0;
	for(int i=head[u];i&&limit;i=edge[i].nxt){
		int v=edge[i].to;
		if(!vis[v]&&dis[v]==dis[u]+edge[i].cost&&edge[i].val){
			int k=dfs(v,min(limit,edge[i].val));
			edge[i].val-=k;
			edge[i^1].val+=k;
			limit-=k;
			flow+=k;
			maxcost+=k*edge[i].cost;
		}
	}
	if(!flow)dis[u]=inf;
	vis[u]=0;
	return flow;
}
int Dinic(){
	int maxflow=0;
	while(SPFA()){
		maxflow+=dfs(S,inf);
	}
	return maxflow;
}
vector<int> dfs1(int u,int fa){
	vector<int> tmp;
	tmp.push_back(u);
	int o=(p1[u]<inf?p1[u]:0);
	bool ok=(o>0);
	for(int i=0;i<G1[u].size();++i){
		int v=G1[u][i];
		if(v==fa)continue;
		vector<int> k=dfs1(v,u);
		if(!ok)o+=k[k.size()-1];
		p1[u]-=k[k.size()-1];
		if(k.size()>1){
			for(int j=0;j<k.size()-1;++j){
				tmp.push_back(k[j]);
			}
		}
	}
	if(p1[u]<0){
		printf("-1\n");
		exit(0);
	}
	if(p1[u]<=n){
		++tot;
		add(S,tot,p1[u],0);
		add(tot,S,0,0);
		for(int i=0;i<tmp.size();++i){
			add(tot,tmp[i],1,0);
			add(tmp[i],tot,0,0);
		}
		tmp.clear();
	}
	tmp.push_back(o);
	return tmp;
}
vector<int> dfs2(int u,int fa){
	vector<int> tmp;
	tmp.push_back(u);
	int o=(p2[u]<inf?p2[u]:0);
	bool ok=(o>0);
	for(int i=0;i<G2[u].size();++i){
		int v=G2[u][i];
		if(v==fa)continue;
		vector<int> k=dfs2(v,u);
		if(!ok)o+=k[k.size()-1];
		p2[u]-=k[k.size()-1];
		if(k.size()>1){
			for(int j=0;j<k.size()-1;++j){
				tmp.push_back(k[j]);
			}
		}
	}
	if(p2[u]<0){
		printf("-1\n");
		exit(0);
	}
	if(p2[u]<=n){
		++tot;
		add(tot,T,p2[u],0);
		add(T,tot,0,0);
		for(int i=0;i<tmp.size();++i){
			add(tmp[i]+n,tot,1,0);
			add(tot,tmp[i]+n,0,0);
		}
		tmp.clear();
	}
	tmp.push_back(o);
	return tmp;
}
void Solve(){
	S=4*n+q1+q2+1,T=S+1;
	tot=2*n;
	cnt=1;
	for(int i=1;i<=n;++i){
		add(i,i+n,1,w[i]);
		add(n+i,i,0,-w[i]);
	}
	dfs1(rt1,0);
	dfs2(rt2,0);
	Dinic();
	for(int i=head[S];i;i=edge[i].nxt){
		if(edge[i].val){
			printf("-1\n");
			return;
		}
	}
	for(int i=head[T];i;i=edge[i].nxt){
		if(edge[i^1].val){
			printf("-1\n");
			return;
		} 
	} 
	printf("%d\n",maxcost);
}
int main(){
//	freopen("w.in","r",stdin);
//	freopen("w.out","w",stdout);
	n=read(),rt1=read(),rt2=read();
	for(int i=1;i<=n;++i){
		w[i]=read();
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G1[u].push_back(v),G1[v].push_back(u);
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G2[u].push_back(v),G2[v].push_back(u);
	}
	memset(p1,0x3f,sizeof(p1));
	memset(p2,0x3f,sizeof(p2));
	q1=read();
	for(int i=1;i<=q1;++i){
		int x=read(),y=read();
		p1[x]=y;
	}
	q2=read();
	for(int i=1;i<=q2;++i){
		int x=read(),y=read();
		p2[x]=y;
	}
	Solve();
	return 0;
}