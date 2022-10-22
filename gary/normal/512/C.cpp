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
int f[202],s=0,t;
struct edge{
	int from,to,w;
};
vector<edge> E;
vector<int> each[202],each_recover[202];
void make_edge(int u,int v,int w){
	edge tmp;
	tmp.from=u;
	tmp.to=v;
	tmp.w=w;
	E.PB(tmp);
	each[u].PB(E.size()-1);
	swap(tmp.from,tmp.to);
	tmp.w=0;
	E.PB(tmp);
	each[v].PB(E.size()-1);
}
bool check(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
vector<vector< int> > table;
int dep[202];
bool bfs(){
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		for(auto it:each[now]){
			edge next=E[it];
			if(next.w)
			if(dep[next.to]>dep[now]){
				dep[next.to]=dep[now]+1;
				Q.push(next.to);
			}
		}
	}
	return dep[t]!=INF;
}
int pin[202];
int dfs(int now,int flow){
	if(now==t){
		return flow;
	}
	for(int & i=pin[now];i<each[now].size();++i){
		edge & e = E[each[now][i]];
		if(dep[e.to]==dep[now]+1&&e.w){
			int tmp_flow;
			if(tmp_flow=dfs(e.to,min(flow,e.w))){
				e.w-=tmp_flow;
				E[each[now][i]^1].w+=tmp_flow;
				return tmp_flow;
			}
		}
	}
	return 0;
}
int n;
void Dinic(){
	rb(i,1,n+1){
			dep[i]=INF;
		}
	while(bfs()){
		rb(i,0,n+1){
			pin[i]=0;
		}
		while(dfs(s,INF));
		rb(i,1,n+1){
			dep[i]=INF;
		}
	}
}
vector<int> T_V;
int vis[202];
void dfs2(int now){
	if(now==0||now==t) return;
	vis[now]=1;
	T_V.PB(now);
	for(auto it:each_recover[now]){
		if(!vis[it]){
			dfs2(it);
		}
	}
}
int ok[202];
int main(){
	cin>>n;
	rb(i,1,n){
		cin>>f[i];
	}
	t=n+1;
	rb(i,1,n){
		if(f[i]&1){
			make_edge(i,t,2);
		}
		else{
			make_edge(s,i,2);
		}
	}
	rb(i,1,n){
		rb(j,1,n){
			if(i!=j&&(!(f[i]&1)))
			if(check(f[i]+f[j])){
				make_edge(i,j,1);
			}
		}
	}//
//	rep(i,E.size()){cout<<E[i].from<<" "<<E[i].to<<" "<<E[i].w <<endl;
//		if((i&1)==0);
//		else{
//			if(E[i].w){
//				
//				each_recover[E[i].to].PB(E[i].from);
//				each_recover[E[i].from].PB(E[i].to);
//			}
//		}
//	}
//	cout<<"__\n";
	Dinic(); 
	rep(i,E.size()){//cout<<E[i].from<<" "<<E[i].to<<" "<<E[i].w <<endl;
		if((i&1)==0);
		else{
			if(E[i].w){
				each_recover[E[i].to].PB(E[i].from);
				each_recover[E[i].from].PB(E[i].to);
			}
		}
	}
	for(auto it:each[0]){
		if(E[it].w==0){
//			cout<<E[it].to<<endl;
			ok[E[it].to]=1;
		}
		else{
			puts("Impossible");
			return 0;
		}
	}
	rb(i,1,n){
		if(!vis[i]&&ok[i]){
				T_V.clear();
				dfs2(i);
				table.PB(T_V);	
		}
	}
	cout<<table.size()<<endl;
	for(auto it:table){
		cout<<it.size()<<" ";
		for(auto it2:it){
			cout<<it2<<" ";
		}
		cout<<endl;
	}
	return 0;
}