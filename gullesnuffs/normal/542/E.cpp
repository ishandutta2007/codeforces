#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

vector<int> adj[1005];
queue<int> q;
int dis[1005];
bool vis[1005];
int best[1005];

int dfs(int node){
	if(vis[node])
		return 0;
	vis[node]=1;
	int ret=best[node];
	rep(i,0,adj[node].size()){
		int to=adj[node][i];
		ret=max(dfs(to), ret);
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i,0,m){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	rep(i,0,n){
		rep(j,0,n){
			dis[j]=-1;
		}
		dis[i]=0;
		q.push(i);
		while(!q.empty()){
			int cur=q.front();
			best[i]=max(best[i], dis[cur]);
			q.pop();
			rep(j,0,adj[cur].size()){
				int to=adj[cur][j];
				if(dis[to] == -1){
					dis[to]=dis[cur]+1;
					q.push(to);
				}
				else if(dis[to]%2 == dis[cur]%2){
					puts("-1");
					return 0;
				}
			}
		}
	}
	int ans=0;
	rep(i,0,n)
		ans += dfs(i);
	printf("%d\n", ans);
}