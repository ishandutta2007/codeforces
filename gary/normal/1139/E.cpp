/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int GRAPH_SIZE=/*here->>>*/  12000 /*<<<=here*/;
int pin[GRAPH_SIZE],dep[GRAPH_SIZE],s=11998,t=s+1;
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
//	cout<<U<<"->>"<<V<<endl;
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
int n,m,p[5005],c[5005];
int flag[5000];
vector<int> res;
int main(){
	fastio;
	cin>>n>>m;
	rb(i,1,n){
//		int pi;
		cin>>p[i];
	} 
	rb(i,1,n){
		cin>>c[i];
	}
	int d;
	cin>>d;
	int query[5005];
	rb(i,1,d)
		cin>>query[i],flag[query[i]]=1;
	rb(i,1,n)
		if(!flag[i]){
			make_edge(p[i],4999+c[i],1);
		}
	rb(i,1,m)
		make_edge(i+4999,t,1);
	int mf=0,try_[5000],las=0;
	reverse(query+1,query+1+d);
	rb(i,1,d){
//		cout<<i<<"----------------------\n";
		while(1){
			if(!try_[mf]){
				try_[mf]=1;
//				cout<<mf<<endl;
				make_edge(s,mf,1);
			}
			int Tmp=Dinic();
			las+=Tmp;
			if(las==mf+1){
				mf++;
				continue;
			}
//			las+=Tmp;
			break;
		}    
//		cout<<"MaxFlow"<<las<<endl;
		res.PB(mf);
//		cout<<"process:  "<<query[i]<<" "<<p[query[i]]<<" to "<<c[query[i]]<<endl;
		make_edge(p[query[i]],4999+c[query[i]],1);
	}
	reverse(ALL(res));
	for(auto it:res){
		cout<<it<<endl;
	}
	return 0;
}