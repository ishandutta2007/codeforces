#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
int x[1005],y[1005];
vector<int>zx,zy;
vector<int>red[1005],blue[1005];

struct edge
{
	int to,cap,rev;
};
vector<edge>G[2505];
bool used[2505];

void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
int dfs(int v,int t,int f)
{ 
	if(v==t) return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(!used[e.to] && e.cap>0)
		{ 
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0) 
			{ 
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t)
{ 
	int flow=0;
	while(1)
	{ 
		memset(used,0,sizeof(used));
		int f=dfs(s,t,INF);
		if(!f) return flow;
		flow+=f;
	}
}

vector<int>go[2505];
vector<P2>R,B;
bool usedd[2505];
struct uf{
	int par[2505],ran[2505];
	void init(){ for(int i=0;i<2505;i++) par[i] = i; }
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(ran[x] < ran[y]) par[x] = y;
		else{
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x,int y){ return find(x)==find(y); }
}redd,bluee;
vector<P>RR,BB;
vector<P>rpt,bpt;
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d%d",&x[i],&y[i]);
		zx.pb(x[i]);
		zy.pb(y[i]);
	}
	zx.pb(1);
	zx.pb(1000000000);
	zy.pb(1);
	zy.pb(1000000000);
	SORT(zx); ERASE(zy);
	SORT(zy); ERASE(zy);
	rep(i,n){
		x[i] = POSL(zx,x[i]);
		y[i] = POSL(zy,y[i]);
		red[y[i]].pb(x[i]);
		blue[x[i]].pb(y[i]);
	}
	int rrr = 0, bbb = 0;
	rep(i,1005){
		SORT(red[i]); SORT(blue[i]);
		for(int j=1;j<red[i].size();j++){
			R.pb(mp(mp(red[i][j-1],i),mp(red[i][j],i)));
			RR.pb(mp(rrr+j-1,rrr+j));
		}
		for(int j=0;j<red[i].size();j++) rpt.pb(mp(red[i][j],i));
		rrr += red[i].size();
		for(int j=1;j<blue[i].size();j++){
			B.pb(mp(mp(i,blue[i][j-1]),mp(i,blue[i][j])));
			BB.pb(mp(bbb+j-1,bbb+j));
		}
		for(int j=0;j<blue[i].size();j++) bpt.pb(mp(i,blue[i][j]));
		bbb += blue[i].size();
	}
	rep(i,R.size()) rep(j,B.size()){
		if(R[i].fi.fi < B[j].fi.fi && B[j].fi.fi < R[i].sc.fi){
			if(B[j].fi.sc < R[i].fi.sc && R[i].fi.sc < B[j].sc.sc){
				//mustnt choose both
				add_edge(i,1200+j,1);
			}
		}
	}
	rep(i,R.size()) add_edge(2401,i,1);
	rep(i,B.size()) add_edge(1200+i,2402,1);
	int x = max_flow(2401,2402);
	
	rep(i,R.size()){
		usedd[i] = 1;
		for(int j=0;j<G[i].size();j++){
			int T = G[i][j].to;
			if(1200<=T && T<1200+B.size()){
				if(G[i][j].cap == 0){
					go[T].pb(i);
					usedd[i] = 0;
				}
				else{
					assert(G[i][j].cap == 1);
					go[i].pb(T);
				}
			}
		}
	}
	queue<int>que;
	rep(i,R.size()){
		if(usedd[i]){
			que.push(i);
			usedd[i] = 0;
		}
	}
	while(!que.empty()){
		int q = que.front(); que.pop();
		if(usedd[q]) continue; usedd[q] = 1;
		for(int i=0;i<go[q].size();i++){
			int to = go[q][i];
			if(!usedd[to])
			{
				que.push(to);
			}
		}
	}
	int rc=0,bc=0;
	redd.init();
	bluee.init();
	
	rep(i,R.size()){
		if(usedd[i]){
			rc++;
			redd.unite(RR[i].fi,RR[i].sc);
		}
	}
	rep(i,B.size()){
		if(!usedd[1200+i]){
			bc++;
			bluee.unite(BB[i].fi,BB[i].sc);
		}
	}
	cout << n-rc << endl;
	for(int i=0;i<rpt.size();i++){
		if(redd.find(i) != i) continue;
		int mn = INF, mx = -INF;
		for(int j=0;j<rpt.size();j++){
			if(redd.find(j) == i){
				mn = min(mn,j);
				mx = max(mx,j);
			}
		}
		printf("%d %d %d %d\n",zx[rpt[mn].fi],zy[rpt[mn].sc],zx[rpt[mx].fi],zy[rpt[mx].sc]);
	}
	cout << n-bc << endl;
	for(int i=0;i<bpt.size();i++){
		if(bluee.find(i) != i) continue;
		int mn = INF, mx = -INF;
		for(int j=0;j<bpt.size();j++){
			if(bluee.find(j) == i){
				mn = min(mn,j);
				mx = max(mx,j);
			}
		}
		printf("%d %d %d %d\n",zx[bpt[mn].fi],zy[bpt[mn].sc],zx[bpt[mx].fi],zy[bpt[mx].sc]);
	}
}