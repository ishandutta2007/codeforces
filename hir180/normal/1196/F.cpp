#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<ll,ll> P;
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
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,q;
vector<P1>edge;
vector<P>G[200005];
vector<ll>t;
ll dist[505][505];

signed main(){
	cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		edge.pb(mp(w,mp(u,v)));
	}
	SORT(edge);
	for(int i=0;i<edge.size()&&i<q+5;i++){
		int u = edge[i].sc.fi, v = edge[i].sc.sc;
		int D = edge[i].fi;
		G[u].pb(mp(v,D));
		G[v].pb(mp(u,D));
	}
	for(int i=1;i<=n;i++){
		if(G[i].size() == 0) continue;
		priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >que;
		
		que.push(mp(0,i));
		map<int,ll>M;
		M.clear();
		M[i] = 0;
		
		while(!que.empty()){
			pair<ll,int>q = que.top(); que.pop();
			assert(M.find(q.sc) != M.end());
			if(M[q.sc] != q.fi) continue;
			if(q.fi != 0 && i < q.sc){
			    t.pb(q.fi);
			}
			int v = q.sc;
			for(int i=0;i<G[v].size();i++){
				if(M.find(G[v][i].fi) == M.end() || M[G[v][i].fi] > q.fi+G[v][i].sc){
					M[G[v][i].fi] = q.fi+G[v][i].sc;
					que.push(mp(M[G[v][i].fi],G[v][i].fi));
				}
			}
		}
	}
	SORT(t);
	cout << t[q-1] << endl;
}