/*
AuThOr Gwj
*/
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int GRAPH_SIZE=200 ;
int pin[GRAPH_SIZE],dep[GRAPH_SIZE],s,t;
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
int n,m,a[101],u[101],v[101];
int main(){
	fastio;
	R2(n,m);
	vector<int> pr;
	vector<int> fact[101];
	rb(i,1,n){
		int ai;
		R(ai);
		a[i]=ai;
		for(LL j=1;j*j<=ai;j++){
			if(ai%j==0){
				if(j!=1)fact[i].PB(j); 
				if(ai/j!=1)fact[i].PB(ai/j);
			}
		}
		sort(ALL(fact[i]));
		for(auto it:fact[i]){
			if(ai%it==0){
				pr.PB(it);
			}
			while(ai%it==0){
				ai/=it;
			} 
		}
	} 
	rb(i,1,m){
		R2(u[i],v[i]);
	}
	sort(ALL(pr));
	pr.erase(unique(ALL(pr)),pr.end());
	int res=0;
	int cnt[101];
	for(auto it:pr){
		init();
		memset(cnt,0,sizeof(cnt));
		rb(i,1,n){
		s=0;
		t=199;
			while(a[i]%it==0){
				cnt[i]++;
				a[i]/=it;
			}
		}
		rb(i,1,n){
			if(i&1){
				make_edge(s,i,cnt[i]);
			}
			else{
				make_edge(i,t,cnt[i]);
			}
		}
		rb(i,1,m){
			if(u[i]&1){
				
			}	
			else{
				swap(v[i],u[i]);
			}
			make_edge(u[i],v[i],INF);
		}
		res+=Dinic();
	}
	cout<<res<<endl;
	return 0;
}