/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct edge{
	int f,t,w;
};int a[105],a_[105],n,s,t;
vector<edge> E;vector<int> each[105],fromzero;
void make_edge(int u,int v,int w){
	edge tmp;
	tmp.f=u;
	tmp.t=v;
	tmp.w=w;
	E.PB(tmp);
	swap(tmp.f,tmp.t);
	tmp.w=0;
	E.PB(tmp);
	each[u].PB(E.size()-2);
	each[v].PB(E.size()-1);
	if(v==t){
		fromzero.PB(E.size()-2);
	}
} 
set<int> prim_factor;

void rebuild_graph(int x){
	rep(i,E.size()){
		if(i&1){
			E[i].w=0;
		}
	}
	for(auto it:each[0]){
		int flow=0;
		while(a[E[it].t]%x==0){
			a[E[it].t]/=x;
			flow++;
		}
		E[it].w=flow;
		E[it^1].w=0;
//		cout<<0<<" "<<E[it].t<<" "<<E[it].w<<"\n";
	}
	for(auto it:fromzero){
		int flow=0;
		while(a[E[it].f]%x==0){
			a[E[it].f]/=x;
			flow++;
		}
		E[it].w=flow;
		E[it^1].w=0;
//		cout<<E[it].f<<" "<<t<<" "<<E[it].w<<"\n";
		
	}
}
int pin[105],dep[105];
bool bfs(){
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		for(auto it:each[now]){
			int next=E[it].t;
			if(E[it].w)
			if(dep[next]>dep[now]+1){
				dep[next]=dep[now]+1;
				Q.push(next);
			}
		}
	}
	return dep[t]!=INF;
}
int dfs(int now,int flow){
//	cout<<now<<" "<<flow<<endl;
	if(now==t){
		return flow;
	}
	for(int & i= pin[now];i<each[now].size();i++){
		int it=each[now][i];
		if(E[it].w&&dep[E[it].t]==dep[now]+1){
			int tmp;
			if(tmp=dfs(E[it].t,min(flow,E[it].w))){
				E[it].w-=tmp;
				E[it^1].w+=tmp;
				return tmp;
			}
		}
	}
	return 0;
}
int Dinic(){
	int max_flow=0;
	rb(i,1,t)
	{
		dep[i]=INF;
	}
	while(bfs()){
//		cout<<"d-d\n "; 
		rb(i,0,t){
			pin[i]=0;
		}
		int tmp;
		while(tmp=dfs(s,INF)){
			max_flow+=tmp;
		}
		rb(i,1,t){
			dep[i]=INF;
		}
	}
	return max_flow;
}
bool check(int x){
	if(x==1) return 0;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
vector<int> factor[202];
int main(){
	int res=0;
	int m;
	cin>>n>>m;
	s=0;
	t=n+1;
	rb(i,1,n){
		cin>>a[i];
		a_[i]=a[i];
		if(i&1){
			make_edge(s,i,0);
		}
		else{
			make_edge(i,t,0);
		}
	} 
	rb(it,1,n){
		for(int i=1;i*i<=a_[it];i++){
			if(a_[it]%i==0){
				if(i!=1)factor[it].PB(i);
				if(a_[it]/i!=1)factor[it].PB(a_[it]/i);
			} 
		}
		sort(ALL(factor[it]));
	}
	rb(i,1,n){
		for(auto it:factor[i])
		{
			if(a_[i]%it==0) prim_factor.insert(it);
			else continue;
			while(a_[i]%it==0){
				a_[i]/=it;
			}
		}
	}
	rb(i,1,m){
		int ik,jk;
		cin>>ik>>jk;
		if(ik&1){
			make_edge(ik,jk,INF);
		}
		else{
			make_edge(jk,ik,INF);
		}
	}
	for(set<int> :: IT ite=prim_factor.begin();ite!=prim_factor.end();ite++){
		rebuild_graph(*ite);
//		cout<<*ite<<endl;
		res+=Dinic();
	}
	cout<<res<<endl;
	return 0;
}