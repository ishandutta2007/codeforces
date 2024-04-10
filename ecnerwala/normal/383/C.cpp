#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 4e5;
const int MAXM = 4e5;

int N, M;
int A[MAXN];
vector<int> adj[MAXN];

int par[MAXN];
int size[MAXN];
int depth[MAXN];

void dfs(int c, int p = -1) {
	size[c] = 1;
	par[c] = p;
	depth[c] = (p >= 0) ? (depth[p] + 1) : 0;
	for(int i = 0; i < adj[c].size(); i++) {
		int n = adj[c][i];
		if(n == p) continue;
		dfs(n, c);
		size[c] += size[n];
	}
	
}

int hpar[MAXN];
int hdepth[MAXN]; // index in chain
int hlen[MAXN]; // length of chain

int pos[MAXN]; // stores position of node

int S = 0;
int chains[MAXN];
int bits[MAXN];

void dfsH(int c, int p = -1) {
	pos[c] = S++;
	chains[pos[c]] = c;
	if(p == -1) {
		hpar[c] = -1;
		hdepth[c] = 0;
	}
	int child = -1;
	for(int i = 0; i < adj[c].size(); i++) {
		int n = adj[c][i];
		if(n == p) continue;
		if(size[n] * 2 >= size[c]) {
			hpar[n] = hpar[c];
			hdepth[n] = hdepth[c] + 1;
			child = n;
		} else {
			hpar[n] = c;
			hdepth[n] = 0;
		}
	}
	if(child != -1) {
		dfsH(child, c);
		hlen[c] = hlen[child];
	} else {
		hlen[c] = hdepth[c] + 1;
	}

	for(int i = 0; i < adj[c].size(); i++) {
		int n = adj[c][i];
		if(n == p) continue;
		if(n == child) continue;
		dfsH(n, c);
	}
}

// sum from [1, ind]
int sum(int* bit, int ind) {
	int res = 0;
	while(ind) {
		res += bit[ind - 1];

		ind = ind & (ind - 1);
	}
	return res;
}

// update ind, 1-indexed
void update(int *bit, int sz, int ind, int val) {
	while(ind <= sz) {
		bit[ind - 1] += val;
		ind += ind & -ind;
	}
}


void precomp() {
	dfs(0);
	dfsH(0);
	memset(bits, 0, sizeof(bits));

	for(int i = 0; i < N; i++) {
		int v = chains[i];
		//cerr << i << ' ' << v << ' ' << hdepth[v] << ' ' << hlen[v] << ' ' << hpar[v] << ' ' << par[v] << '\n';
	}
}

void insert(int n, int val) {
	if(depth[n] % 2) val *= -1;

	update(bits + (pos[n] - hdepth[n]), hlen[n], hdepth[n] + 1, val);

	//for(int i = 0; i < N; i++) { cerr << chains[i] << ' ' << bits[i] << '\n'; }
}

int get(int n) {
	int st = n;
	int res = 0; 

	while(n >= 0) {
		res += sum(bits + (pos[n] - hdepth[n]), hdepth[n] + 1);

		n = hpar[n];
	}

	if(depth[st] % 2) res = -res;

	return res + A[st];
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for(int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	precomp();

	for(int i = 0; i < M; i++) {
		int t; cin >> t;
		if(t == 1) {
			int x, v; cin >> x >> v;
			x--;
			insert(x, v);
		} else {
			int x; cin >> x;
			x--;
			cout << get(x) << '\n';
		}
	}

	return 0;
}