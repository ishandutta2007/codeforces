#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int n, q;
vector<pair<int, int> > adj[100005];
int children[100005];
int parent[100005];
int a[100005], b[100005], l[100005];

void dfs(int node){
	++children[node];
	rep(i, 0, adj[node].size()){
		int to=adj[node][i].first;
		if(to == parent[node])
			continue;
		parent[to]=node;
		dfs(to);
		children[node] += children[to];
	}
}

int main(){
	scanf("%d", &n);
	rep(i, 0, n-1){
		scanf("%d%d%d", a+i, b+i, l+i);
		--a[i];--b[i];
		adj[a[i]].push_back(make_pair(b[i], l[i]));
		adj[b[i]].push_back(make_pair(a[i], l[i]));
	}
	parent[0]=-1;
	dfs(0);
	long long ans=0;
	rep(i, 0, n-1){
		long long sz=min(children[a[i]], children[b[i]]);
		ans += sz*(n-sz)*l[i];
	}
	scanf("%d", &q);
	rep(i, 0, q){
		int r, w;
		scanf("%d%d", &r, &w);
		--r;
		long long sz=min(children[a[r]], children[b[r]]);
		ans -= sz*(n-sz)*(l[r]-w);
		l[r]=w;
		double A=ans*6;
		A *= n;
		A -= ans*12;
		A /= n;
		A /= n-1;
		A /= n-2;
		printf("%.7lf\n", A);
	}
}