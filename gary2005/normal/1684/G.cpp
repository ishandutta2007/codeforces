/**
 *    author:  gary
 *    created: 19.05.2022 23:38:42
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
const int GRAPH_SIZE= 2000;
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
bool di[1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> L,R;
    rb(i,1,n){
        int ai;
        cin>>ai;
        if(2ll*ai+1>m){
            cout<<-1<<endl;
            return 0;
        }
        if(3ll*ai<=m) L.PB(ai);
        else R.PB(ai);
    }
    rep(i,L.size()) make_edge(s,i+1,1);
    rep(j,R.size()) make_edge(j+L.size()+1,t,1);
    rep(i,L.size()) rep(j,R.size()){
        if(R[j]%L[i]==0&&2ll*R[j]+L[i]<=m){ make_edge(i+1,j+L.size()+1,1);}
    }
    if(Dinic()!=R.size()){
        cout<<-1<<endl;
        return 0;
    }
    vector<mp> ans;
    rep(i,e.size()){
        if(i%2==0){
            int u,v;
            u=e[i].u;
            v=e[i].v;
            if(u<=L.size()&&u>=1&&v<=R.size()+L.size()&&v>L.size()&&e[i^1].c==1&&e[i].c==0){
                int A=L[u-1],B=R[v-L.size()-1];
                ans.PB(II(A+B,B+B+A));
                di[u-1]=1;
            }
        }
    }
    rep(i,L.size()) if(!di[i]) ans.PB(II(2*L[i],3*L[i]));
    cout<<ans.size()<<endl;
    for(auto it:ans) cout<<it.first<<" "<<it.second<<endl;
    return 0;
}