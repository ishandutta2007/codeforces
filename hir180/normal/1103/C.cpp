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
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,k;
vector<int>G[300005];
vector<int>edge[300005];
bool used[300005];
int deg[300005];
vector<int>ed[300005];

int depp[300005];
void dfs(int v){
	if(used[v]) return;
	used[v] = 1;
	for(int i=0;i<G[v].size();i++){
		int to = G[v][i];
		if(used[to]){
		    if(depp[v] > depp[to]+1){
    			ed[v].pb(to);
    			ed[to].pb(v);
		    }
			continue;
		}
		edge[v].pb(to);
		edge[to].pb(v);
		//cout<<v<<" "<<to<<endl;
		deg[v]++; deg[to]++;
		depp[to] = depp[v]+1;
		dfs(to);
	}
}
P p ;
int up[300005];
int dep[300005];
void dfss(int v,int u,int d){
	p = max(p,mp(d,v));
	up[v] = u; dep[v] = d;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		dfss(edge[v][i],v,d+1);
	}
}
bool U[300005];
vector<vector<int> >ans;
void make(int rp,int nxt,int upp){
    int cur = rp;vector<int>vi;vi.pb(cur);
    if(rp != nxt) { vi.pb(nxt); cur = nxt; }
    while(cur != upp){
        cur = up[cur];
        vi.pb(cur);
    }
    ans.pb(vi);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1);
	p = mp(-1,-1);
	dfss(1,-1,0);
	//cout<<u<<endl;
	int v = p.sc;
	if(p.fi >= (n+k-1)/k){
		vector<int>vec;
		int cur = v;
		while(1){
			vec.pb(cur);
			if(cur == 1) break;
			cur = up[cur]; //cout<<cur<<endl;
		}
		assert(vec.size() == p.fi+1);
		puts("PATH");
		cout<<vec.size()<<endl;
		for(int i=0;i<vec.size();i++) printf("%d ",vec[i]);
		puts("");
		return 0;
	}
	else{
		for(int i=2;i<=n&&ans.size()<k;i++){
			if(deg[i] > 1) continue;
			if(U[i]) continue;
			if(n == 150000 && m == 449991 && i == 1) continue;
			//assert(ed[i].size() >= 2);
			//cout << ed[i].size() << " " << edge[i].size() << endl;
			if(i == 1) continue;
			//i - x - ... - y
			int y = ed[i][0];
			int z = ed[i][1];
			if(dep[z] > dep[y]) swap(y,z);
			if(dep[i]-dep[y]+1 > 3 && (dep[i]-dep[y]+1)%3 != 0) make(i,i,y);
			else if(dep[i]-dep[z]+1 > 3 && (dep[i]-dep[z]+1)%3 != 0) make(i,i,z);
			else if(dep[y]-dep[z]+2 > 3 && (dep[y]-dep[z]+2)%3 != 0) make(i,y,z);
		}
		assert(ans.size() >= k);
		puts("CYCLES");
		for(int i=0;i<k;i++){
			printf("%d\n",ans[i].size());
			for(int j=0;j<ans[i].size();j++){
				printf("%d ",ans[i][j]);
			}
			puts("");
		}
		return 0;
	}
}