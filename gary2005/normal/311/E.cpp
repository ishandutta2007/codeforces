/**
 *    author:  gary
 *    created: 19.01.2022 14:02:40
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
typedef pair<int,int> mp;
const LL INF=1e18;
const int GRAPH_SIZE= 20000+2000+200;
int pin[GRAPH_SIZE],s=0,t=GRAPH_SIZE-1;
LL dep[GRAPH_SIZE];
struct EDGE{
	int u,v;
    LL c;
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
LL dfs(int now,LL flow){
	if(now==t){
		return flow;
	}
	for(int & i= pin[now];i<each[now].size();i++){
		int it=each[now][i];
		if(e[it].c&&dep[e[it].v]==dep[now]+1){
			LL tmp;
			if(tmp=dfs(e[it].v,min(flow,e[it].c))){
				e[it].c-=tmp;
				e[it^1].c+=tmp;
				return tmp;
			}
		}
	}
	return 0ll;
}
LL Dinic(){
	LL max_flow=0;
	rep(i,GRAPH_SIZE)
	{
		dep[i]=INF;
	}
	dep[s]=0;
	while(bfs()){
		rep(i,GRAPH_SIZE){
			pin[i]=0;
		}
		LL tmp;
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
void make_edge(int U,int V,LL C){
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
int n,m,g;
bool ini[10000+20];
int v[10000+20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>g;
    rb(i,1,n) cin>>ini[i];
    rb(i,1,n) cin>>v[i];
    rb(i,1,n){
        make_edge(i*2-1,i*2,1e17);
        if(ini[i]==0){
            make_edge(s,i*2-1,1e9+v[i]);
            make_edge(i*2,t,1e9);
        }
        else{
            make_edge(s,i*2-1,1e9);
            make_edge(i*2,t,1e9+v[i]);
        }
    }
    LL answer=0;
    rb(i,1,m){
        int S,W,K;
        cin>>S>>W>>K;
        vector<int> v(K);
        rb(j,1,K) cin>>v[j-1];
        bool ty;
        cin>>ty;
        int PAY=W+(ty? g:0);
        answer+=W;
        if(S==0){
            make_edge(s,2*n+i,PAY);
            for(auto it:v) make_edge(2*n+i,2*it,1e17);
        }
        else{
            make_edge(2*n+i,t,PAY);
            for(auto it:v) make_edge(2*it-1,2*n+i,1e17);
        }
    }
    cout<<answer-Dinic()+(LL)(1e9)*n<<endl;
    return 0;
}