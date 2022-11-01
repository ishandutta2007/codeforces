#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

const int N=4.1e5;
vector<int> adj[N];
vector<int> path;
bool act[N];
int seen[N];
int typ=17;

int dfs(int u,int bad) {
	if(seen[u]==typ) return 0;
	seen[u]=typ;
	if(u==bad) return 0;
	if(act[u]) return u;
	path.push_back(u);
	for(int v:adj[u]) {
		int rec=dfs(v,bad);
		if(rec) return rec;
	}
	path.pop_back();
	return 0;
}

int main() {
	int T; scanf("%d",&T); for(;T--;) {
		int n,m,s,t; scanf("%d%d%d%d",&n,&m,&s,&t);

		vector<pair<int,int> > edges;
		for(int i=1;i<=n;i++) adj[i].clear();
		for(int i=0;i<m;i++) {
			int x,y; scanf("%d%d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
			edges.pb({x,y});
		}

		static int nx[N],pr[N];
		for(int i=1;i<=n;i++) nx[i]=pr[i]=-1;
		for(int i=1;i<=n;i++) act[i]=0;
		nx[s]=t;
		pr[t]=s;
		pr[s]=-1;
		nx[t]=-1;

		vector<pair<int,int> > act_edges;
		for(int u:adj[s]) act_edges.pb({s,u});
		for(int u:adj[t]) act_edges.pb({t,u});
		act[s]=act[t]=1;

		// printf("ayy\n");
		int u=s;
		for(;u!=t;u=nx[u]) {
			for(int w:adj[u]) {
				assert(act[u]);
				if(act[w]) continue;

				path.clear();
				// printf("bdfs\n");
				++typ;
				int v=dfs(w,u);
				// printf("edfs\n");
				if(!v) goto die;
				// if(v<u) {
					// reverse(path.begin(),path.end());
					// swap(u,v);
				// }
				assert(u!=t);
				assert(nx[u]!=-1);
				assert(v!=u);

				for(;!path.empty();) {
					int x=path.back();
					path.pop_back();
					act[x]=1;
					for(int y:adj[x]) act_edges.pb({x,y});
					pr[nx[u]]=x;
					nx[x]=nx[u];
					pr[x]=u;
					nx[u]=x;
				}
			}
		}
		// printf("here\n");

		for(int i=1;i<=n;i++) if(nx[i]==-1&&pr[i]==-1) goto die;
{
		vector<int> ans;
		for(int x=s;x!=-1;x=nx[x]) {
			ans.pb(x);
		}
		vector<int> rans(n+3);
		for(int i=0;i<n;i++) rans[ans[i]]=i;

		printf("Yes\n");
		for(auto &e:edges) {
			int u=e.fi, v=e.se;
			if(rans[u]>rans[v]) swap(u,v);
			assert(rans[u]<rans[v]);
			printf("%d %d\n",u,v);
		}
}
		continue;
		die: printf("No\n");
	}
}