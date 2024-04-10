#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 300 * 1000 + 10, qax = 500 * 1000 + 10;
int n, q;
vector<pi> V[nax];

int p[nax], siz[nax], nr;
vector<tuple<int,int,int>>edge;
bool ans[qax];
int par[nax][20], dep[nax], sum[nax], in[nax], out[nax];
int T[(1 << 20)], R;

void add(int a, int b, int x) {
	a += R; b += R;
	T[a] += x;
	if(a != b) T[b] += x;
	while(a / 2 != b / 2) {
		if(a % 2 == 0) T[a + 1] += x;
		if(b % 2 == 1) T[b - 1] += x;
		a /= 2;
		b /= 2;
	}
}

int ask(int a) {
	a += R;
	int w = T[a];
	while(a > 1) {
		a /= 2;
		w += T[a];
	}
	return w;
}

int Fund(int x) {
	if(p[x] != x) p[x] = Fund(p[x]);
	return p[x];
}

bool Onion(int a, int b, int c) {
	int pa = Fund(a), pb = Fund(b);
	if(pa == pb) return false;
	V[a].emplace_back(b, c);
	V[b].emplace_back(a, c);
	if(siz[pa] < siz[pb]) swap(pa, pb);
	siz[pa] += siz[pb];
	p[pb] = pa;
	return true;
}

void dfs(int x, int pr) {
	par[x][0] = pr;
	dep[x] = dep[pr] + 1;
	in[x] = ++nr;
	for(auto nbh : V[x]) if(nbh.ST != pr) {
		sum[nbh.ST] = sum[x] + nbh.ND;
		dfs(nbh.ST, x);
	}
	out[x] = nr;
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 19; i >= 0; --i) {
		if(dep[par[a][i]] >= dep[b]) {
			a = par[a][i];
		}
	}
	if(a == b) return a;
	for(int i = 19; i >= 0; --i) {
		if(par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		p[i] = i;
		siz[i] = 1;
	}
	edge.resize(q);
	for(int i = 0; i < q; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = {a, b, c};
		if(Onion(a, b, c)) {
			ans[i] = true;
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(dep[i] == 0) {
			dfs(i, 0);
		}
	}
	for(int step = 1; step <= 19; ++step) {
		for(int i = 1; i <= n; ++i) {
			par[i][step] = par[par[i][step - 1]][step - 1];
		}
	}
	R = 1;
	while(R <= n) R *= 2;
	int id = 0;
	for(auto &[a,b,c] : edge) {
		if(!ans[id]) {
			int u = lca(a, b);
			int block = ask(in[a]) + ask(in[b]) - 2 * ask(in[u]);
			if(block == 0) {
				int s = sum[a] + sum[b] - 2 * sum[u];
				s = s & 1;
				if((s ^ c) == 1) {
					ans[id] = true;
					while(a != u) {
						add(in[a], out[a], 1);
						a = par[a][0];
					}
					while(b != u) {
						add(in[b], out[b], 1);
						b = par[b][0];
					}
				}
			}
		}
		if(ans[id]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		id++;
	}
	
}