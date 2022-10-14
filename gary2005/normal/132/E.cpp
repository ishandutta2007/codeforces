/**
 *    author:  gary
 *    created: 17.05.2022 19:32:48
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
const int GRAPH_SIZE= 606;
int s=0,t=GRAPH_SIZE-1;
struct EDGE{
	int u,v,c;
    LL cos;
};
vector<EDGE> e;
vector<int> each[GRAPH_SIZE];
int maxflow;
LL mincost;
int flow[GRAPH_SIZE];
LL dis[GRAPH_SIZE];
int inq[GRAPH_SIZE],las[GRAPH_SIZE];
bool spfa(){
	memset(inq,0,sizeof(inq));
    fill(dis,dis+GRAPH_SIZE,INF);
	flow[s]=1e9;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	inq[s]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		inq[now]=0;
		for(auto it:each[now]){
			int to,f;
            LL c;
			to=e[it].v;
			f=e[it].c;
			c=e[it].cos;
			if(f<=0) continue;
			if(dis[to]>dis[now]+c){
				dis[to]=dis[now]+c;
				las[to]=it;
				flow[to]=min(flow[now],f);
				if(!inq[to]) q.push(to);
				inq[to]=1;
			}
		}
	}
	return dis[t]!=INF;
}
void KM(){
	while(spfa()){
		maxflow+=flow[t];
		mincost+=dis[t]*flow[t];
		int now=t;
		while(now!=s){
			e[las[now]].c-=flow[t];
			e[las[now]^1].c+=flow[t];
			now=e[las[now]].u;
		}
	}
}
void make_edge(int U,int V,int C,LL COS){
	EDGE tmp;
	tmp.u=U;
	tmp.v=V;
	tmp.c=C;
	tmp.cos=COS;
	e.PB(tmp);
	each[U].PB(e.size()-1);
	swap(tmp.u,tmp.v);
	tmp.c=0;
	tmp.cos=-COS;
	e.PB(tmp);
	each[V].PB(e.size()-1);
}
int n,m;
int in[255],out[255],a[255];
int is[255];
void dfs(int now,int c=0){
    if(now==t) return ;
    if(now<=2*n&&now>=1) is[(now+1)/2]=c;
    if(now==s){
        for(auto it:each[now]) if(it%2==0&&e[it^1].c==1) dfs(e[it].v,e[it].v-2*n);
    }
    else{
        for(auto it:each[now]) if(it%2==0&&e[it^1].c==1) dfs(e[it].v,c);
    }
}
int pre[222];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    m=min(n,m);
    rb(i,1,n) cin>>a[i];
    rb(i,1,n) in[i]=i*2-1,out[i]=i*2,make_edge(in[i],out[i],1,-1e9);
    rb(i,1,m) {make_edge(s,2*n+i,1,0);rb(j,1,n) make_edge(2*n+i,in[j],1,__builtin_popcount(a[j]));}
    rb(i,1,n) rb(j,i+1,n) make_edge(out[i],in[j],1,(a[i]==a[j]? 0:__builtin_popcount(a[j])));
    rb(i,1,n) make_edge(out[i],t,1,0);
    KM();
    dfs(s);
    vector<pair<char,int> > ans;
    set<int> se;
    rb(i,1,n){
        se.insert(a[i]);
    }
    if(se.size()<=m){
        map<int,int> cnt;
        int ccc=0;
        rb(i,1,n){
            if(cnt.find(a[i])==cnt.end()) cnt[a[i]]=++ccc;
            is[i]=cnt[a[i]];
        }
    }
    int Ans=0;
    rb(i,1,n){
        if(pre[is[i]]!=a[i]) ans.emplace_back(char('a'+is[i]-1),a[i]),Ans+=__builtin_popcount(a[i]);
        ans.emplace_back(char('a'+is[i]-1),-1);
        pre[is[i]]=a[i];
    }
    cout<<ans.size()<<" "<<Ans<<endl;
    for(auto it:ans){
        if(it.second==-1) cout<<"print("<<it.first<<")\n";
        else cout<<it.first<<"="<<it.second<<endl;
    }
    return 0;
}