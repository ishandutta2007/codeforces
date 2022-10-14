/*
{By GWj
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int GRAPH_SIZE=80000;
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
	e.clear();
	rep(i,GRAPH_SIZE){
		each[i].clear();
	}
}
int n,m;
char c[202][202];
int get_right(int i,int j){
	return (i-1)*m+(i-1)*(m-1)+j;
}
int get_down(int i,int j){
	return (i-1)*m+(i-1)*(m-1)+(m-1)+j;
}
bool limit[GRAPH_SIZE],ok[GRAPH_SIZE];
vector<int> g[GRAPH_SIZE];
void add_edge(int u,int v){
	g[u].PB(v);
	g[v].PB(u);
}
vector<int> groups[2];
bool vis[GRAPH_SIZE];
void dfss(int now,int col){
	groups[col].PB(now);
	vis[now]=1;
	for(auto it:g[now]){
		if(!vis[it]&&ok[it]){
			dfss(it,col^1);
		}
	}
}
int main(){
  fastio;
	R2(n,m);
	int rest=0;
	rb(i,1,n){
		rb(j,1,m){
			R(c[i][j]);
			rest+=c[i][j]=='#';
		}
	}
	int cnt=0;
	vector<int> useful;
	rb(i,1,n){
		rb(j,1,m-1){
			int id=(i-1)*m+(i-1)*(m-1)+j;
			if(c[i][j]=='#'&&c[i][j+1]=='#'){
				ok[id]=1;
				cnt++;
				useful.PB(id);
			}
		}
	}
	rb(i,1,n-1){
		rb(j,1,m){
			int id=(i-1)*m+(i-1)*(m-1)+(m-1)+j;
			if(c[i][j]=='#'&&c[i+1][j]=='#'){
				cnt++;
				ok[id]=1;
				useful.PB(id);
			}
		}
	}
	rb(i,1,n-1)
		rb(j,1,m-1){// 
			if(c[i][j]=='#'&&c[i][j+1]=='#'&&c[i+1][j]=='#'){
				add_edge(get_right(i,j),get_down(i,j));
			}
		}
	rb(i,2,n)
		rb(j,2,m){// 
			if(c[i][j]=='#'&&c[i-1][j]=='#'&&c[i][j-1]=='#'){
				add_edge(get_right(i,j-1),get_down(i-1,j));
			}
		}
	rb(i,2,n){
		rb(j,1,m-1){// 
			if(c[i][j]=='#'&&c[i-1][j]=='#'&&c[i][j+1]=='#'){
				int ID1=get_right(i,j),ID2=get_down(i-1,j);
				add_edge(ID1,ID2);
			}
		}
	}
	rb(i,1,n-1){
		rb(j,2,m){// 
			if(c[i][j]=='#'&&c[i+1][j]=='#'&&c[i][j-1]=='#'){
				int ID1=get_right(i,j-1),ID2=get_down(i,j);
				add_edge(ID1,ID2);
			} 
		}
	}
	for(auto it:useful){
		if(!vis[it]){
			dfss(it,0);
		}
	}
	for(auto it:groups[0]){
//		cout<<"W:"<<it<<endl;
		for(auto itt:g[it]){
//			cout<<it<<"->"<<itt<<endl;
			make_edge(it,itt,1);
		}
		make_edge(s,it,1);
	}
	for(auto it:groups[1]){
//		cout<<"B:"<<it<<endl;
		make_edge(it,t,1);
	}
//	cout<<cnt<<endl;
	cout<<rest-(cnt-Dinic())<<endl;
	return 0;
}