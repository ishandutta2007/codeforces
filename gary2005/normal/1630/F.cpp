/**
 *    author:  gary
 *    created: 30.01.2022 12:51:25
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int GRAPH_SIZE= 2e5+233;
int pin[GRAPH_SIZE],dep[GRAPH_SIZE],s=0,t=GRAPH_SIZE-1;
struct EDGE{
	int u,v,c;
};
vector<EDGE> e;
vector<int> each[GRAPH_SIZE];
bool bfs(){
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		for(auto it:each[now]){
			int next=e[it].v;
			if(e[it].c)
			if(dep[next]>dep[now]+1){
				dep[next]=dep[now]+1;
				Q.push(next);
			}
		}
	}
	return dep[t]!=INF;
}
int dfs(int now,int flow){
	if(now==t){
		return flow;
	}
	for(int & i= pin[now];i<each[now].size();i++){
		int it=each[now][i];
		if(e[it].c&&dep[e[it].v]==dep[now]+1){
			int tmp;
			if(tmp=dfs(e[it].v,min(flow,e[it].c))){
				e[it].c-=tmp;
				e[it^1].c+=tmp;
				return tmp;
			}
		}
	}
	return 0;
}
int Dinic(){
	int max_flow=0;
	rep(i,GRAPH_SIZE)
	{
		
		dep[i]=INF;
	}
	dep[s]=0;
	while(bfs()){
		rep(i,GRAPH_SIZE){
			pin[i]=0;
		}
		int tmp;
		while(tmp=dfs(s,INF)){
			max_flow+=tmp;
		}
		rep(i,GRAPH_SIZE){
			dep[i]=INF;
		}
		dep[s]=0;
	}
	return max_flow;
}
void make_edge(int U,int V,int C){
	EDGE tmp;
	tmp.u=U;
	tmp.v=V;
	tmp.c=C;
	e.PB(tmp);
	each[U].PB(e.size()-1);
	swap(tmp.u,tmp.v);
	tmp.c=0;
	e.PB(tmp);
	each[V].PB(e.size()-1);
}
void init(){
	for(auto it:e) each[it.u].clear(),each[it.v].clear();
	e.clear();
}
vector<int> g[GRAPH_SIZE];
int a[GRAPH_SIZE],in[GRAPH_SIZE],out[GRAPH_SIZE];
int n;
void addedge(int u,int v){
	make_edge(u,v+2*n,1);
}
void solve(){
	init();
	cin>>n;rb(i,1,n) cin>>a[i],g[i].clear(),in[i]=2*i-1,out[i]=2*i;
	if(n<=5000){
		rb(i,1,n) rb(j,1,n) if(i!=j&&a[j]%a[i]==0) g[i].PB(j);
	}
	else{
		map<int,int> app;
		rb(i,1,n) app[a[i]]=i;
		rb(i,1,n){
			for(int x=2*a[i];x<=50000;x+=a[i]){
				if(app.find(x)!=app.end()){
					g[i].PB(app[x]);
				}
			}
		}
	}
	rb(i,1,2*n) make_edge(s,i,1);
	rb(i,2*n+1,4*n) make_edge(i,t,1);
	rb(i,1,n){
		for(auto j:g[i]){
			// cout<<i<<"->"<<j<<endl;
			addedge(in[i],in[j]);
			addedge(out[i],out[j]);
			addedge(in[i],out[j]);
		}
		addedge(in[i],out[i]);
	}
	cout<<Dinic()-n<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}