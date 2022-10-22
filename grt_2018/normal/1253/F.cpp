#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100*1000+10;
const ll INF = (ll)1e18;
int n,m,q,k;
vector<pair<int,ll> >V[nax];
vector<pair<int,ll> >G[nax];
ll dist[nax];
priority_queue<pair<ll,int> >PQ;
int par[nax],r[nax],dep[nax];
pair<int,ll> parent[nax][20];
vector<pair<ll,pi> >Edges;

int fund(int x) {
	if(par[x]==x) return x;
	return fund(par[x]);
}

void onion(int a,int b) {
	int pa=fund(a),pb=fund(b);
	if(r[pa]<r[pb]) swap(pa,pb);
	par[pb] = pa;
	r[pa]+=r[pb];
}

void dfs(int x,int p) {
	dep[x] = dep[p]+1;
	for(auto nbh:G[x]) {
		if(nbh.ST==p) parent[x][0] = {p,nbh.ND};
		else dfs(nbh.ST,x);
	}
}

ll lca(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	ll w = 0;
	for(int i=19; i>=0;i--) {
		if(dep[parent[a][i].ST]>=dep[b]) {
			w = max(w,parent[a][i].ND);
			a=parent[a][i].ST;
		}
	}
	if(a==b) return w;
	for(int i=19; i>=0; i--) {
		if(parent[a][i].ST!=parent[b][i].ST) {
			w = max(w,parent[a][i].ND);
			w=max(w,parent[b][i].ND);
			a = parent[a][i].ST;
			b = parent[b][i].ST;
		}
	}
	w=max(w,parent[a][0].ND);
	w=max(w,parent[b][0].ND);
	return w;
}

int main() {_
	cin>>n>>m>>k>>q;
	for(int a,b,w,i=0; i<m;i++) {
		cin>>a>>b>>w;
		V[a].emplace_back(b,w);
		V[b].emplace_back(a,w);
	}
	for(int i=k+1; i<=n;i++) dist[i]=INF;
	for(int i=1; i<=k; i++) PQ.push({0,i});
	while(!PQ.empty()) {
		pair<ll,int>to = PQ.top();
		PQ.pop();
		if(-to.ST>dist[to.ND]) continue;
		for(auto nbh:V[to.ND]) {
			if(dist[to.ND]+nbh.ND<dist[nbh.ST]) {
				dist[nbh.ST] = dist[to.ND]+nbh.ND;
				PQ.push({-dist[nbh.ST],nbh.ST});
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(auto& nbh:V[i]) {
			if(nbh.ST<i) continue;
			Edges.PB({nbh.ND+dist[i]+dist[nbh.ST],{i,nbh.ST}});
		}
	}
	for(int i=1; i<=n; i++) {
		par[i] = i;
		r[i] = 1;
	}
	sort(Edges.begin(),Edges.end());
	for(auto it:Edges) {
		if(fund(it.ND.ST)!=fund(it.ND.ND)) {
			G[it.ND.ST].emplace_back(it.ND.ND,it.ST);
			G[it.ND.ND].emplace_back(it.ND.ST,it.ST);
			onion(it.ND.ST,it.ND.ND);
		}
	}
	dfs(1,0);
	for(int p=1; p<19;p++) {
		for(int i=1; i<=n; i++) {
			parent[i][p].ST = parent[parent[i][p-1].ST][p-1].ST;
			parent[i][p].ND = max(parent[i][p-1].ND,parent[parent[i][p-1].ST][p-1].ND);
		}
	}
	while(q--) {
		int a,b;
		cin>>a>>b;
		cout<<lca(a,b)<<"\n";
	}
	
}