#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, ll> pil;
typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 2e5;
int N;
vector<pil> adj[MAXN];
int sz[MAXN];
int par[MAXN];

ll res;
int P[MAXN];

void dfs(int cur, int prv = -1, int pr = -1) {
	sz[cur] = 1;
	par[cur] = pr;
	for(auto i : adj[cur]) {
		int nxt = i.A;
		if(nxt == prv) continue;
		dfs(nxt, cur, (pr == -1) ? nxt : pr);
		res += sz[nxt] * i.B * 2;
		sz[cur] += sz[nxt];
	}
}

queue<int> trees[MAXN];

int deg[MAXN];

// solve with given root
void go(int r) {
	cerr << r << '\n';
	dfs(r);
	par[r] = r; // make more consistent
	for(int i = 0; i < N; i++) {
		trees[par[i]].push(i);
	}
	for(int i = 0; i < N; i++) {
		deg[i] = trees[i].size() * 2;
	}
	assert(deg[r] == 2);
	deg[r] --;
	priority_queue<pii> degs;
	for(int i = 0; i < N; i++) {
		if(deg[i]) degs.push(pii(deg[i], i));
	}
	//cerr << "hi\n";

	memset(P, -1, sizeof(P));
	priority_queue<int, vector<int>, greater<int>> vert;
	for(int i = 0; i < N; i++) {
		if(trees[i].size()) vert.push(trees[i].front());
	}
	for(int i = 0; i < N; i++) {
		int p = par[i];
		//cerr << i << ' ' << p << '\n';

		while(!degs.empty() && degs.top().A != deg[degs.top().B]) {
			int v = degs.top().B;
			degs.pop();
			degs.push(pii(deg[v], v));
		}
		while(!vert.empty() && vert.top() != trees[par[vert.top()]].front()) {
			int v = par[vert.top()];
			vert.pop();
			if(!trees[v].empty()) vert.push(trees[v].front());
		}
		//cerr << "hi\n";
		if(!degs.empty() && degs.top().A == N - i) {
			if(N - i == 1 && degs.top().B == r) {
				P[r] = r;
				break;
			}
			if(degs.top().B != p) {
				//cerr << "hi\n";
				int q = degs.top().B;
				P[i] = trees[q].front();
				trees[q].pop();
				deg[p] --;
				deg[q] --;
				//cerr << "hi\n";

				continue;
			}
		}
		assert(!vert.empty());
		if(i == r && vert.top() == r) {
			P[i] = r;
			trees[r].pop();
			deg[r] --;
			deg[r] --;
			continue;
		}
		bool vtop = par[vert.top()] == p;
		if(vtop) vert.pop();
		while(!vert.empty() && vert.top() != trees[par[vert.top()]].front()) {
			int v = par[vert.top()];
			vert.pop();
			if(!trees[v].empty()) vert.push(trees[v].front());
		}
		P[i] = vert.top();
		assert(trees[par[vert.top()]].front() == vert.top());
		trees[par[vert.top()]].pop();
		deg[p] --;
		deg[par[vert.top()]] --;
		if(vtop) {
			vert.push(trees[p].front());
		}
	}
}

void gosplit(int l, int r) {
	cerr << l << ' ' << r << '\n';
	go(l);
}

bool findcenter(int cur, int prv = -1) {
	sz[cur] = 1;
	int msize = 0;
	for(auto i : adj[cur]) {
		int nxt = i.A;
		if(nxt == prv) continue;
		if(findcenter(nxt, cur)) return true;
		sz[cur] += sz[nxt];
		if(sz[nxt] * 2 == N) {
			gosplit(cur, nxt);
			return true;
		}
		msize = max(sz[nxt], msize);
	}
	if(msize * 2 < N && (N - sz[cur]) * 2 < N) {
		go(cur);
		return true;
	}
	return false;
}

int main() {
	cin >> N;
	for(int i = 0; i < N - 1; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--, v--;
		adj[u].push_back(pil(v, w));
		adj[v].push_back(pil(u, w));
	}
	findcenter(0);
	cout << res << '\n';
	for(int i = 0; i < N; i++) cout << P[i] + 1 << ' '; cout << '\n';
}