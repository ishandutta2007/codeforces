#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

const ll mod = 1000000007;

struct edge{
	int to,cap,cost,rev;
};
int nn = 55;
vector<edge>G[55];
ll dist[55],prevv[55],preve[55];

void add_edge(int from,int to,int cap,int cost){
	G[from].pb((edge){to,cap,cost,G[to].size()});
	G[to].pb((edge){from,0,-cost,G[from].size()-1});
}

vector<pair<ll,ll>>path;
void calc(int s,int t){
	while(true){
		fill(dist,dist+nn,1e18);
		dist[s] = 0;
		bool upd = 1;
		
		while(upd){
			upd = 0;
			rep(v,nn){
				if(dist[v] > 5e17) continue;
				rep(i,G[v].size()){
					edge &e = G[v][i];
					if(e.cap > 0 && dist[e.to] > dist[v]+e.cost){
						dist[e.to] = dist[v]+e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						upd = 1;
					}
				}
			}
		}
		if(dist[t] > 5e17) return ;
		ll d = 1e18;
		for(int v=t;v!=s;v=prevv[v]){
			d = min(d,1LL*G[prevv[v]][preve[v]].cap);
		}
		if(path.empty() || path.back().fi < dist[t])
		    path.pb(mp(dist[t],d));
		else
		    path.back().sc += d;
		    
		for(int v=t;v!=s;v=prevv[v]){
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return ;
}

int n,m;
long double ans[100005];

int main(){
	cin >> n >> m;
	rep(i,m){
		int a,b,c; cin >> a >> b >> c;
		add_edge(a,b,1,c);
	}
	calc(1,n);
	
	vector<P>query;
	int q; scanf("%d",&q);
	rep(i,q){
		int c; scanf("%d",&c); query.pb(mp(c,i));
	}
	SORT(query);
	
	//for(auto a:path) cout << a.fi << " " << a.sc << endl;
	int nxt = 0;
	ll slope = 0;
	long double cur = 0.;
	for(int i=0;i<path.size();i++){
		slope += path[i].sc;
		
		if(i+1 < path.size()){
			cur += (double)(path[i+1].fi - path[i].fi) * (double)(slope);
			while(nxt < query.size() && (double)(query[nxt].fi) <= cur){
				ans[query[nxt].sc] = (double)(path[i+1].fi) - (cur-(double)(query[nxt].fi)) / (double)(slope);
				nxt++;
			}
		}
		else{
			while(nxt < query.size()){
				ans[query[nxt].sc] = (double)(path[i].fi) + ((double)(query[nxt].fi)-cur) / (double)(slope);
				nxt++;
			}
		}
	}
	rep(i,q) printf("%.10Lf\n",ans[i]);
}