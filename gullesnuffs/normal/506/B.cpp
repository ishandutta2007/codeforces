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

vector<int> adj[100005];
vector<int> inadj[100005];
bool vis[100005];
int ans=0;
vector<int> adj2[100005];
int cost[100005];

int rec(int node){
	if(vis[node])
		return 0;
	vis[node]=1;
	int ret=cost[node];
	rep(i,0,adj2[node].size()){
		int to=adj2[node][i];
		if(vis[to]){
		}
		else{
			++ans;
			ret += rec(to);
		}
	}
	return ret;
}

int index=0;
int ind[100005], lowlink[100005];
stack<int> S;
bool inS[100005];
int compN;
vector<int> comp[100005];
int belong[100005];
void tarjan(int i){
	ind[i]=index;
	lowlink[i]=index;
	++index;
	S.push(i);
	inS[i]=1;
	rep(j,0,adj[i].size()){
		int to=adj[i][j];
		if(ind[to] == -1){
			tarjan(to);
			lowlink[i]=min(lowlink[i],lowlink[to]);
		}
		else if(inS[to]){
			lowlink[i]=min(lowlink[i], ind[to]);
		}
	}

	if(lowlink[i] == ind[i]){
		while(!S.empty()){
			int cur=S.top();
			comp[compN].push_back(S.top());
			belong[S.top()]=compN;
			inS[cur]=0;
			S.pop();
			if(cur == i)
				break;
		}
		if(comp[compN].size() > 1){
			ans += comp[compN].size();
			cost[compN]=1;
		}
		else
			cost[compN]=0;
		++compN;
	}
}

set<int> adj3[100005];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i,0,m){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;--b;
		adj[a].push_back(b);
		inadj[b].push_back(a);
	}
	ans=0;
	rep(i,0,n)
		ind[i]=-1;
	rep(i,0,n){
		if(ind[i] == -1)
			tarjan(i);
	}
	rep(i,0,n){
		rep(j,0,adj[i].size()){
			int to=adj[i][j];
			if(adj3[belong[i]].find(belong[to]) != adj3[belong[i]].end())
				continue;
			if(adj3[belong[to]].find(belong[i]) != adj3[belong[to]].end())
				continue;
			adj2[belong[i]].push_back(belong[to]);
			adj2[belong[to]].push_back(belong[i]);
			adj3[belong[i]].insert(belong[to]);
		}
	}

	rep(i,0,compN){
		if(vis[i])
			continue;
		int ret=rec(i);
		if(ret >= 2)
			ans -= ret-1;
	}
	printf("%d\n", ans);
}