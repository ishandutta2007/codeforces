/**
 *    author:  gary
 *    created: 27.12.2021 22:13:29
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
const LL INF=1e18;
typedef pair<int,int> mp;
const int GRAPH_SIZE= 1050;
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
int a[1001];
vector<mp> edge;
int answer[1001];
vector<int> b;
int ans[1001];
bool in[GRAPH_SIZE];
void tour(int now){
    in[now]=1;
    for(auto it:each[now]){
        if(e[it].c&&!in[e[it].v]){
            tour(e[it].v);
        }
    }
}
void solve(vector<int> v,int l,int r){
    if(l==r||v.empty()){
        for(auto it:v)
            ans[it]=b[l];
        return ;
    }
    memset(in,0,sizeof(in));
    for(auto it:v) in[it]=1;
    init();
    int mid=(l+r)/2;
    for(auto it:v){
        make_edge(s,it,(LL)(1e13)+abs(b[mid+1]-a[it]));
        make_edge(it,t,(LL)(1e13)+abs(b[mid]-a[it]));
    }
    for(auto it:edge){
        int u,v;
        tie(u,v)=it;
        if(in[u]&&in[v]) make_edge(v,u,INF);
    }
    Dinic();
    memset(in,0,sizeof(in));
    tour(s);
    vector<int> L,R;
    for(auto it:e){
        int u,v;
        u=it.u;
        v=it.v;
        if(in[u]&&!in[v]){
            if(u==s){
                R.PB(v);
            }
            if(v==t){
                L.PB(u);
            }
        }
    }
    sort(ALL(L));
    L.erase(unique(ALL(L)),L.end());
    sort(ALL(R));
    R.erase(unique(ALL(R)),R.end());
    solve(L,l,mid);
    solve(R,mid+1,r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    rb(i,1,n) cin>>a[i];
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        edge.PB(II(u,v));
    }
    rb(i,1,n) b.PB(a[i]);
    sort(ALL(b));
    b.erase(unique(ALL(b)),b.end());
    vector<int> v;
    rb(i,1,n) v.PB(i);
    solve(v,0,b.size()-1);
    rb(i,1,n) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}