#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 2333
typedef long long ll;
int n;
map<int,vector<pair<int,int> > > X,Y;
struct Point{
	int x,y;
}p[N];
namespace Maxflow{
	int head[N],ecnt,S,T,dep[N];
	struct Edge{
		int nxt,to,val;
	}edge[N*N<<1];
	void add(int a,int b,int c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c){
		add(a,b,c),add(b,a,0);
	}
	void init(int _S,int _T){
		ecnt=1;
		memset(head,0,sizeof(head));
		S=_S,T=_T;
	}
	queue<int> q;
	bool bfs(){
		memset(dep,0,sizeof(dep));
		q.push(S);
		dep[S]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(edge[i].val&&!dep[v]){
					dep[v]=dep[u]+1;
					q.push(v);
				}
			}
		}
		return dep[T]>0;
	}
	int dfs(int u,int limit){
		if(u==T)return limit;
		int flow=0;
		for(int i=head[u];i&&limit;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]==dep[u]+1&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
			}
		}
		if(!flow)dep[u]=inf;
		return flow;
	}
	int Dinic(){
		int maxflow=0;
		while(bfs()){
			maxflow+=dfs(S,inf);
		}
		return maxflow;
	}
}
struct Line{
	int u,v;	
}a[N],b[N];
bool Intersect(int i,int j){
	return p[b[j].u].y>p[a[i].u].y&&p[b[j].u].y<p[a[i].v].y&&p[a[i].u].x>p[b[j].u].x&&p[a[i].u].x<p[b[j].v].x;
}
struct Union_Set{
	int f[N];
public:
	void init(int n){
		for(int i=1;i<=n;++i)f[i]=i;	
	}
	inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
	inline void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx;	
	}	
}S1,S2;
int l[N],r[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	Maxflow::init(2*n+1,2*n+2);
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;
		X[p[i].x].emplace_back(p[i].y,i);
		Y[p[i].y].emplace_back(p[i].x,i);
	}
	int nx=0,ny=0;
	for(auto [qwq,t]:X){
		sort(t.begin(),t.end());
		for(int i=1;i<(int)t.size();++i){
			a[++nx]={t[i-1].second,t[i].second};
		}	
	}
	for(auto [qwq,t]:Y){
		sort(t.begin(),t.end());
		for(int i=1;i<(int)t.size();++i){
			b[++ny]={t[i-1].second,t[i].second};	
		}	
	}
	for(int i=1;i<=nx;++i)Maxflow::adde(Maxflow::S,i,1);
	for(int i=1;i<=ny;++i)Maxflow::adde(i+nx,Maxflow::T,1);
	for(int i=1;i<=nx;++i){
		for(int j=1;j<=ny;++j){
			if(Intersect(i,j)){
				Maxflow::adde(i,j+nx,1);	
			}	
		}
	}
	Maxflow::Dinic();
	S1.init(n);
	S2.init(n);
	for(int i=1;i<=nx;++i){
		if(Maxflow::dep[i])S1.Merge(a[i].u,a[i].v);	
	}
	for(int i=1;i<=ny;++i){
		if(!Maxflow::dep[i+nx])S2.Merge(b[i].u,b[i].v);
	}
	{
		for(int i=1;i<=n;++i){
			l[i]=1e9+1,r[i]=0;
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			int fa=S2.getf(i);
			l[fa]=min(l[fa],p[i].x);
			r[fa]=max(r[fa],p[i].x);
		}
		for(int i=1;i<=n;++i)cnt+=S2.getf(i)==i;
		cout<<cnt<<'\n';
		for(int i=1;i<=n;++i){
			if(S2.getf(i)==i){
				cout<<l[i]<<' '<<p[i].y<<' '<<r[i]<<' '<<p[i].y<<'\n';	
			}	
		}
	}
	{
		for(int i=1;i<=n;++i){
			l[i]=1e9+1,r[i]=0;
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			int fa=S1.getf(i);
			l[fa]=min(l[fa],p[i].y);
			r[fa]=max(r[fa],p[i].y);
		}
		for(int i=1;i<=n;++i)cnt+=S1.getf(i)==i;
		cout<<cnt<<'\n';
		for(int i=1;i<=n;++i){
			if(S1.getf(i)==i){
				cout<<p[i].x<<' '<<l[i]<<' '<<p[i].x<<' '<<r[i]<<'\n';	
			}	
		}
	}
	return 0;
}