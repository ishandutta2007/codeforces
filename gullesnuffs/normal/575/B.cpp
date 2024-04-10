#include <bits/stdc++.h>
#define MOD 1000000007

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
map<pair<int, int>, bool> legal;
int depth[100005];
int parent[100005][20];
int U[100005];
int D[100005];

void rec(int node){
	rep(i,0,adj[node].size()){
		int to=adj[node][i];
		if(to == parent[node][0])
			continue;
		parent[to][0]=node;
		rep(i,1,20){
			if(parent[to][i-1] == -1)
				parent[to][i]=-1;
			else
				parent[to][i]=parent[parent[to][i-1]][i-1];
		}
		depth[to]=depth[node]+1;
		rec(to);
	}
}

int lca(int n1, int n2){
	if(depth[n1] > depth[n2])
		swap(n1, n2);
	rrep(i,20,0){
		if(depth[n2]-(1<<i) < depth[n1])
			continue;
		n2=parent[n2][i];
	}
	if(n2 == n1)
		return n1;
	rrep(i,20,0){
		if(parent[n1][i] != parent[n2][i]){
			n1=parent[n1][i];
			n2=parent[n2][i];
		}
	}
	return parent[n1][0];
}

ll powerMod(ll a, ll x){
	if(!x)return 1;
	if(x%2)return (a*powerMod((a*a)%MOD, x/2))%MOD;
	return powerMod((a*a)%MOD, x/2);
}

ll ans;

void udrec(int node){
	rep(i,0,adj[node].size()){
		int to=adj[node][i];
		if(to == parent[node][0])
			continue;
		udrec(to);
		U[node] += U[to];
		D[node] += D[to];
	}
	if(!legal[make_pair(parent[node][0], node)])
		ans += powerMod(2, D[node])-1;
	if(!legal[make_pair(node, parent[node][0])])
		ans += powerMod(2, U[node])-1;
}

int main(){
	int N;
	scanf("%d", &N);
	rep(i,0,N-1){
		int a, b, x;
		scanf("%d%d%d", &a, &b, &x);
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		legal[make_pair(a, b)]=1;
		if(!x)
			legal[make_pair(b, a)]=1;
	}
	rep(i,0,20)
		parent[0][i]=-1;
	rec(0);
	int K;
	scanf("%d", &K);
	int sprev=0;
	rep(i,0,K){
		int s;
		scanf("%d", &s);
		--s;
		int l=lca(s, sprev);
		U[sprev]++;
		U[l]--;
		D[s]++;
		D[l]--;
		sprev=s;
	}
	udrec(0);
	ans%=MOD;
	cout << ans << endl;
}