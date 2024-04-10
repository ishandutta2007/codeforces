#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const int D_MAX_V=1002;
const int D_v_size=1002;
struct D_wolf{
	int t,c,r;
	int u,w;
	D_wolf(){t=c=r=u=w=0;}
	D_wolf(int t1,int c1,int r1,int u1,int w1){
		t=t1;c=c1;r=r1;u=u1;w=w1;
	}
};
vector<D_wolf>D_G[D_MAX_V];
int D_level[D_MAX_V];
int D_iter[D_MAX_V];

void add_edge(int from,int to,int cap,int id){
	D_G[from].push_back(D_wolf(to,cap,D_G[to].size(),1,id));
	D_G[to].push_back(D_wolf(from,0,D_G[from].size()-1,0,id));
}
void D_bfs(int s){
	for(int i=0;i<D_v_size;i++)D_level[i]=-1;
	queue<int> Q;
	D_level[s]=0;
	Q.push(s);
	while(Q.size()){
		int v=Q.front();
		Q.pop();
		for(int i=0;i<D_G[v].size();i++){
			if(D_G[v][i].c>0&&D_level[D_G[v][i].t]<0){
				D_level[D_G[v][i].t]=D_level[v]+1;
				Q.push(D_G[v][i].t);
			}
		}
	}
}
int D_dfs(int v,int t,int f){
	if(v==t)return f;
	for(;D_iter[v]<D_G[v].size();D_iter[v]++){
		int i=D_iter[v];
		if(D_G[v][i].c>0&&D_level[v]<D_level[D_G[v][i].t]){
			int d=D_dfs(D_G[v][i].t,t,min(f,D_G[v][i].c));
			if(d>0){
				D_G[v][i].c-=d;
				D_G[D_G[v][i].t][D_G[v][i].r].c+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		D_bfs(s);
		if(D_level[t]<0)return flow;
		for(int i=0;i<D_v_size;i++)D_iter[i]=0;
		int f;
		while((f=D_dfs(s,t,99999999))>0){flow+=f;}
	}
	return 0;
}
const int MAXN=1100;
const int MAXM=61000;
int zeit, dis[MAXN], fin[MAXN], low[MAXN], par[MAXN], dep[MAXN];
int kodat[MAXN], koptr[MAXN + 1];
int zu[MAXM];
int ptr[MAXN];
int nxt[MAXM];
int n;
void dfsInfo(int u, int oy, int d) {
	dis[u] = low[u] = zeit++; par[u] = oy; dep[u] = d;
	int i, v;
	for (i = ptr[u]; ~i; i = nxt[i]) if ((v = zu[i]) != oy) {
		if (!~dis[v]) {
			dfsInfo(v, u, d + 1);
			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], dis[v]);
		}
	}
	fin[u] = zeit++;
}
void dfsInfos() {
	memset(dis, ~0, n * 4); zeit = 0;
	for (int u = 0; u < n; ++u) if (!~dis[u]) dfsInfo(u, -1, 0);
	for (int u = 0; u < n; ++u) {
		int &j = koptr[u + 1] = koptr[u];
		for (int i = ptr[u]; ~i; i = nxt[i]) if (u == par[zu[i]]) kodat[j++] = zu[i];
	}
}
bool produce(int u, int v) {
	return (dis[u] <= dis[v] && fin[u] >= fin[v]);
}
int related(int u, int v) {
	int s = koptr[u], e = koptr[u + 1], h;
	for (; s + 1 < e; ) {
		h = (s + e) >> 1;
		(dis[kodat[h]] <= dis[v]) ? s = h : e = h;
	}
	return kodat[s];
}
bool isBridge(int u, int v) {
	if (dis[u] > dis[v]) swap(u, v);
	return (u == par[v] && dis[v] <= low[v]);
}
bool isFatalEdge(int u, int v, int a, int b) {
	if (dis[u] > dis[v]) swap(u, v);
	return (u == par[v] && dis[v] <= low[v] && produce(v, a) != produce(v, b));
}
bool isFatalPoint(int u, int a, int b) {
	bool ua = produce(u, a), ub = produce(u, b);
	if (!ua && !ub) {
		return 0;
	} else if (ua && ub) {
		int ra = related(u, a), rb = related(u, b);
		return (ra != rb && (dis[u] <= low[ra] || dis[u] <= low[rb]));
	} else {
		if (ub) swap(a, b);
		return (dis[u] <= low[related(u, a)]);
	}
}
int vis[1100];
int x[31000];
int y[31000];
int z[31000];
int f[1100][1100];
vector<pair<int,int> > G[1100];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int s,t;scanf("%d%d",&s,&t);
	s--;t--;

	for(int i=0;i<b;i++){
		int p,q,r;scanf("%d%d%d",&p,&q,&r);p--;q--;
		f[p][q]++;
		f[q][p]++;
		x[i]=p;y[i]=q;z[i]=r;
		if(p==q)continue;
		add_edge(p,q,1,i);
		add_edge(q,p,1,i);
	}
	int ans=max_flow(s,t);
	if(ans>2){
		printf("-1\n");return 0;
	}
	if(ans==0){
		printf("0\n0\n");return 0;
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<D_G[i].size();j++){
			if(D_G[i][j].u&&D_G[i][j].c==0){
				G[i].push_back(make_pair(D_G[i][j].t,D_G[i][j].w));
			}
		}
	}
	int ret=mod*2;
	int L=-1;
	int R=-1;
	for(int i=0;i<a;i++)for(int j=0;j<G[i].size();j++){
		for(int k=0;k<b;k++){
			zu[k]=nxt[k]=-1;
		}
		for(int k=0;k<=a;k++){
			dis[k]=fin[k]=low[k]=par[k]=dep[k]=kodat[k]=koptr[k]=0;
			ptr[k]=-1;
		}
		int cur=z[G[i][j].second];
		zeit=0;
		int sz=0;
		for(int k=0;k<b;k++){
			if(x[k]==y[k])continue;
			if(G[i][j].second==k)continue;
			zu[sz]=y[k];
			nxt[sz]=ptr[x[k]];
			ptr[x[k]]=sz++;
			zu[sz]=x[k];
			nxt[sz]=ptr[y[k]];
			ptr[y[k]]=sz++;
		}
		n=a;
		if(ans==1&&ret>cur){
			for(int k=0;k<a;k++)vis[k]=0;
			queue<int>Q;
			Q.push(s);
			vis[s]=1;
			while(Q.size()){
				int at=Q.front();Q.pop();
				for(int k=ptr[at];~k;k=nxt[k]){
					if(!vis[zu[k]]){
						vis[zu[k]]=1;
						Q.push(zu[k]);
					}
				}
			}
			if(vis[t]==0){
				ret=cur;
				L=G[i][j].second;
				R=-1;
			}
		}
		dfsInfos();
		for(int k=0;k<b;k++){
			if(x[k]==y[k])continue;
			if(G[i][j].second==k)continue;
			if(ret>cur+z[k]&&isFatalEdge(x[k],y[k],s,t)&&(f[x[k]][y[k]]==1||(f[x[k]][y[k]]==2&&((i==x[k]&&G[i][j].first==y[k])||(i==y[k]&&G[i][j].first==x[k]))))){
				ret=cur+z[k];
				L=G[i][j].second;
				R=k;
			}
		}
	}
	if(~R){
		printf("%d\n2\n%d %d\n",ret,L+1,R+1);
	}else printf("%d\n1\n%d\n",ret,L+1);
}