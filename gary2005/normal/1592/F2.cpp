/**
 *    author:  gary
 *    created: 03.10.2021 22:33:45
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
const int MAXN=505;
int n,m;
char c[MAXN][MAXN];
int a[MAXN][MAXN],b[MAXN][MAXN];

const int GRAPH_SIZE= 1005;
int s=0,t=GRAPH_SIZE-1;
struct EDGE{
	int u,v,c,cos;
};
vector<EDGE> e;
vector<int> each[GRAPH_SIZE];
int maxflow,mincost;
int flow[GRAPH_SIZE];
int dis[GRAPH_SIZE],inq[GRAPH_SIZE],las[GRAPH_SIZE];
bool spfa(){
	memset(inq,0,sizeof(inq));
	memset(dis,63,sizeof(dis));
	flow[s]=INF;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	inq[s]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		inq[now]=0;
		for(auto it:each[now]){
			int to,f,c;
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
void make_edge(int U,int V,int C,int COS){
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

int solve(int i,int j){
    if(i<=0) return 0;
    if(j<=0) return 0;
    return a[i][j]^a[i+1][j]^a[i+1][j+1]^a[i][j+1];
}
int chk(int i,int j){
    if(i<=0) return 0;
    if(j<=0) return 0;
    return 1;
}

int main(){
    cin>>n>>m;
    rb(i,1,n) rb(j,1,m) cin>>c[i][j],a[i][j]=(c[i][j]=='B');
    int ans=0;
    rb(i,1,n) rb(j,1,m) ans+=(a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1]);
    rb(i,1,n) rb(j,1,m) b[i][j]=(chk(i-1,j-1)+chk(n,j-1)+chk(i-1,m))-2*(solve(i-1,j-1)+solve(n,j-1)+solve(i-1,m))+2;
    rb(i,1,n) rb(j,1,m) make_edge(i,j+n,1,b[i][j]);
    int ss=t-1;
    rb(i,1,n) make_edge(ss,i,1,0);
    rb(i,1,m) make_edge(i+n,t,1,0);
    int tmp=ans;
    rb(i,1,n){
        make_edge(s,ss,1,0);
        KM();
        if(maxflow!=i) break;
        if(maxflow&1){
            check_min(ans,tmp+mincost+1-2*solve(n,m));
        }
        else{
            check_min(ans,tmp+mincost);
        }
    }
    cout<<ans<<endl;
    return 0;
}