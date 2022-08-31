#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
const ll mod = 998244353;

struct edge
{
	int to,cap,cost,rev;
};
int nn = 505;
vector<edge>G[505];
ll dist[505];
int prevv[505],preve[505];

void add_edge(int from,int to,int cap,int cost)
{
	G[from].pb((edge){to,cap,cost,G[to].size()});
	G[to].pb((edge){from,0,-cost,G[from].size()-1});
}

ll mincost_maxflow(int s,int t,int f)
{
	ll res=0;
	const ll inf = 100000000000000000LL;
	while(1)
	{
		//n!!!!!!
		fill(dist,dist+nn,inf);
		dist[s]=0;
		bool upd=true;
		while(upd)
		{
			upd=false;
			for(int v=0;v<nn;v++)
			{
				if(dist[v]==inf) continue;
				for(int i=0;i<G[v].size();i++)
				{
					edge &e = G[v][i];
					if(e.cap>0 && dist[e.to]>dist[v]+e.cost)
					{
						dist[e.to]=dist[v]+e.cost;
						prevv[e.to]=v;
						preve[e.to]=i;
						upd=true;
					}
				}
			}
		}
		if(dist[t]>=0) return res;
		int d=INF;
		for(int v=t;v!=s;v=prevv[v])
		{
			d = min(d,G[prevv[v]][preve[v]].cap);
		}
		res+=1LL*d*dist[t];
		for(int v=t;v!=s;v=prevv[v])
		{
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}


int n1,n2,m,r,b;
string L,R;

void add_edge_min(int from,int to,int cap,int cost,int mn){
	if(cap > mn) add_edge(from,to,cap-mn,cost);
	if(mn) add_edge(n1+n2+5,to,mn,0);
	if(mn) add_edge(from,n1+n2+6,mn,0);
}
vector<P>edge;
char res[205];
int cnt[405][405];
int main(){
	cin >> n1 >> n2 >> m >> r >> b;
	cin >> L >> R;
	int c = 0;
	rep(i,n1){
		if(L[i] != 'U') c++;
		if(L[i] == 'R' || L[i] == 'U'){
			add_edge_min(n1+n2+1,i,205,0,(L[i]=='R'));
		}
		if(L[i] == 'B' || L[i] == 'U'){
			add_edge_min(i,n1+n2+2,205,0,(L[i]=='B'));
		}
	}
	rep(i,n2){
		if(R[i] != 'U') c++;
		if(R[i] == 'B' || R[i] == 'U'){
			add_edge_min(n1+n2+1,n1+i,205,0,(R[i]=='B'));
		}
		if(R[i] == 'R' || R[i] == 'U'){
			add_edge_min(n1+i,n1+n2+2,205,0,(R[i]=='R'));
		}
	}
	rep(i,m){
		int a,bb; cin >> a >> bb; a--; bb--;
		edge.pb(mp(a,n1+bb));
		add_edge_min(a,n1+bb,1,r,0);
		add_edge_min(n1+bb,a,1,b,0);
	}
	{
		add_edge(n1+n2+10,n1+n2+1,50000,0);
		add_edge(n1+n2+2,n1+n2+11,50000,0);
	}
	add_edge(n1+n2+10,n1+n2+5,c,-50000);
	add_edge(n1+n2+6,n1+n2+11,c,-50000);
	
	
	ll ret = mincost_maxflow(n1+n2+10,n1+n2+11,INF);
	ret *= -1;
	ll ans = (100000-ret%100000)%100000;
	
	if((ret+ans)/100000 != c){
		puts("-1");
	}
	else{
		{
			printf("%lld\n",ans);
			rep(i,m){
			    res[i] = 'U';
			    int x = edge[i].fi, y = edge[i].sc;
			    int zan = cnt[x][y];
			    rep(a,G[x].size()) if(G[x][a].to == y && G[x][a].cap == 0 && G[x][a].cost > 0) {
			    	if(zan){
			    		zan--; continue;
			    	}
			    	cnt[x][y]++;
			        res[i] = 'R'; ans -= r; break;
			    }
			    zan = cnt[y][x];
			    rep(a,G[y].size()) if(G[y][a].to == x && G[y][a].cap == 0 && G[y][a].cost > 0) {
			    	if(zan){
			    		zan--; continue;
			    	}
			    	cnt[y][x]++;
			        res[i] = 'B'; ans -= b; break;
			    }
			    printf("%c",res[i]);
			}
			assert(ans == 0);
			puts("");
		}
	}
}