/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
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
const int GRAPH_SIZE= 4000+20;
int pin[GRAPH_SIZE],dep[GRAPH_SIZE],s=0,t=GRAPH_SIZE-1;
struct EDGE{
	int u,v,c,id;
};
vector<EDGE> e;
vector<int> each[GRAPH_SIZE];
class MAX_FLOW{
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
	public:
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
	public:
		void make_edge(int U,int V,int C,int ID){
			EDGE tmp;
			tmp.u=U;
			tmp.v=V;
			tmp.c=C;
			tmp.id=ID;
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
}mf;
int n1,n2,m;
int deg[GRAPH_SIZE];
int main(){
	fastio;
	cin>>n1>>n2>>m;
	int MK=0;
	rb(i,1,m){
		int u,v;
		R2(u,v);
		v+=n1;
		deg[u]++;
		deg[v]++;
		mf.make_edge(u,v,1,i); 
	}
	int k=INF;
	rb(i,1,n1+n2){
		check_min(k,deg[i]);
	}
	vector<vector<int > > rest;
	rb(i,1,n1)
		mf.make_edge(s,i,deg[i]-k,0);
	rb(i,n1+1,n1+n2)
		mf.make_edge(i,t,deg[i]-k,0);
	rb(ZZ,0,k){//k-ZZ 
		rest.PB(vector<int>(0));
		mf.Dinic();
		rb(i,1,n1)
			 for(auto it:each[i])
			 	if(e[it].v>n1)
			 	if(e[it].c==1){
			 		rest[ZZ].PB(e[it].id);
				 } 
		rb(i,1,n1)
			mf.make_edge(s,i,1,0);
		rb(i,n1+1,n1+n2)
			mf.make_edge(i,t,1,0); 
	}
	reverse(ALL(rest));
	for(auto it:rest){
		cout<<it.size()<<' ';
		for(auto itt:it)
			cout<<itt<<' ';
		cout<<endl;
	}
	return 0;
}
/** 
  * 
  *
  *
  *
  **/