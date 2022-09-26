/*#include<bits/stdc++.h>
using namespace std;
#define N 233
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
int n,a[N][N],z[N][N]; 
const int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
ll ans;
struct Val{
	int x,y;
	int w;
	friend operator < (const Val &a,const Val &b){
		return a.w<b.w;
	}
};
inline int ID(int x,int y){
	return (x-1)*n+y;
}
vector<Val> vec;
namespace Maxflow{
	int head[N*N],ecnt,S,T,dep[N*N];
	int pre[N*N];
	struct Edge{
		int nxt,to,val;
	}edge[N*N<<3];
	void add(int a,int b,int c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c){
		add(a,b,c),add(b,a,0);
	}
	void ST(int _S,int _T){
		S=_S,T=_T;
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
		for(int &i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]==dep[u]+1&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
				if(!limit)break;
			}
		}
		if(!flow)dep[u]=inf;
		return flow;
	}
	int Dinic(){
		memcpy(pre,head,sizeof(head));
		int maxflow=0;
		while(bfs()){
			maxflow+=dfs(S,inf);
			memcpy(head,pre,sizeof(head));
		}
		return maxflow;
	}
	void tui(int lim){
		memcpy(pre,head,sizeof(head));
		while(lim&&bfs()){
			lim-=dfs(S,inf);
			memcpy(head,pre,sizeof(head));
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();
			if(a[i][j]>0)vec.push_back({i,j,a[i][j]});
		}
	}
	Maxflow::init(n*n+1,n*n+2);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]>0){
				Maxflow::adde(ID(i,j),Maxflow::T,inf);
				z[i][j]=Maxflow::ecnt;
			}
			if(~a[i][j]){
				for(int k=0;k<4;++k){
					int x=d[k][0]+i,y=d[k][1]+j;
					if(x>=1&&x<=n&&y>=1&&y<=n)Maxflow::adde(ID(i,j),ID(x,y),1);
				}
			}
		}
	}
	sort(vec.begin(),vec.end());
	int flow=0;
	int las=0;
	for(int i=0;i<(int)vec.size();){
		int W=vec[i].w;
		ans+=1LL*(W-las)*flow;
		las=W;
		while(i<(int)vec.size()&&vec[i].w==W){
			int x=vec[i].x,y=vec[i].y;
			int w=vec[i].w;
			las=w;
			int lim=Maxflow::edge[z[x][y]].val;
			Maxflow::ST(ID(x,y),n*n+1);
			Maxflow::edge[z[x][y]].val=Maxflow::edge[z[x][y]^1].val=0;
			flow-=lim; 
			Maxflow::tui(lim);
			Maxflow::ST(n*n+1,n*n+2);
			Maxflow::adde(Maxflow::S,ID(x,y),inf);
			flow+=Maxflow::Dinic();
			++i;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
template <class T> T gi() {
	T x = 0; bool f = 0; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') f = 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f ? -x : x;
}
const int N = 310, inf = 1e9;
int n;
int id(int x, int y) { return (x - 1) * n + y; }
int a[N][N], b[N * N];
struct node { int to, nxt, w; } g[2000010];
int lst[N * N], gl = 1, S, T;
bool vis[N * N];
void add(int x, int y, int w) {
	g[++gl] = (node) {y, lst[x], w}; lst[x] = gl;
	g[++gl] = (node) {x, lst[y], 0}; lst[y] = gl;
}
vector<int> v;
int dfs(int u, int flow) {
	if (u == T) return flow;
	int fl = 0; vis[u] = 1;
	for (int i = lst[u]; i; i = g[i].nxt) {
		int v = g[i].to; 
		if (g[i].w && !vis[v]) {
			int d = dfs(v, min(g[i].w, flow));
			g[i].w -= d; g[i ^ 1].w += d;
			flow -= d; fl += d; if (!flow) break;
		}
	}
	return fl;
}
int idfs(int u, int flow, int from) {
	if (u == S) return flow;
	vis[u] = 1; int fl = 0;
	for (int i = lst[u]; i; i = g[i].nxt) {
		int v = g[i].to; if (vis[v] || (u == T && v != from)) continue;
		if (g[i].w) {
			int d = idfs(v, min(flow, g[i].w), from);
			g[i].w -= d; g[i ^ 1].w += d; flow -= d;
			fl += d; if (!flow) break;
		}
	}
	return fl;
}
int now;
void insert(int x) {
	int f;
	while (memset(vis, 0, sizeof(vis)), f = idfs(T, inf, x)) now -= f;
	for (int i = lst[x]; i; i = g[i].nxt)
		if (g[i].to == T) { g[i].w = g[i ^ 1].w = 0; break; }
	add(S, x, inf);
	while (memset(vis, 0, sizeof(vis)), f = dfs(S, inf)) now += f;
}
int main() {
	n = gi<int>();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = gi<int>();
	S = n * n + 1, T = S + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] > 0)
				add(id(i, j), T, inf), v.push_back(id(i, j)), b[id(i, j)] = a[i][j];
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= n; j++)
			if ((~a[i][j]) && (~a[i + 1][j]))
				add(id(i, j), id(i + 1, j), 1), add(id(i + 1, j), id(i, j), 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < n; j++)
			if ((~a[i][j]) && (~a[i][j + 1]))
				add(id(i, j), id(i, j + 1), 1), add(id(i, j + 1), id(i, j), 1);
	sort(v.begin(), v.end(), [] (int x, int y) { return b[x] < b[y]; });
	long long ans = 0;
	for (int i = 0; i < (int) v.size() - 1; i++)
		insert(v[i]), ans += 1ll * (b[v[i + 1]] - b[v[i]]) * now;
	cout << ans << endl;;;;;;;;;
	return 0;
}