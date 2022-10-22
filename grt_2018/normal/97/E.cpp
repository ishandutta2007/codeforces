#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 1e5 + 10;
int n, m, q;
vector<pi> V[nax];
pi edges[nax];

int in[nax], low[nax], nr, cc[nax], parity[nax], cnt, bcc[nax], bcc_id;
int inv[nax];
bool art[nax], marked[nax], vis[nax];
stack<int>S;

void dfs_low(int x, int p) {
	in[x] = low[x] = ++nr;
	cc[x] = cnt;
	bool articulation = false;
	int child = 0;
	for(auto [y, id] : V[x]) {
		if(y == p) continue;
		if(!in[y]) {
			S.push(id);
			parity[y] = 1 - parity[x];
			child++;
			dfs_low(y, x);
			low[x] = min(low[x], low[y]);
			if((low[y] >= in[x] && p != 0) || (p == 0 && child > 1)) {
				articulation = true;
				bcc_id++;
				while(true) {
					bcc[S.top()] = bcc_id;
					if(S.top() == id) {
						S.pop();
						break;
					}	
					S.pop();
				}
			}
		} else {
			if(in[y] < in[x]) {
				S.push(id);
			}
			low[x] = min(low[x], in[y]);
		}
	}
	art[x] = articulation;	
}

int odd[2 * nax];

int jp[2 * nax][18], dep[2 * nax];
vi T[2 * nax];

void dfs(int x, int p) {
	jp[x][0] = p;
	dep[x] = dep[p] + 1;
	for(auto y : T[x]) if(y != p) {
		odd[y] += odd[x];
		dfs(y, x);
	}
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 17; i >= 0; --i) {
		if(dep[jp[a][i]] >= dep[b]) {
			a = jp[a][i];
		}
	}
	if(a == b) return a;
	for(int i = 17; i >= 0; --i) {
		if(jp[a][i] != jp[b][i]) {
			a = jp[a][i];
			b = jp[b][i];
		}
	}
	return jp[a][0];
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int a, b, i = 0; i < m; ++i) {
		cin >> a >> b;
		V[a].emplace_back(b, i);
		V[b].emplace_back(a, i);
		edges[i] = {a, b};
	}
	for(int i = 1; i <= n; ++i) {
		if(!in[i]) {
			cnt++;
			dfs_low(i, 0);
			if(!S.empty()) {
				bcc_id++;
			}
			while(!S.empty()) {
				bcc[S.top()] = bcc_id;
				S.pop();
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(art[i]) {
			bcc_id++;
			inv[i] = bcc_id;
			for(auto [y, id] : V[i]) {
				if(!marked[bcc[id]]) {
					T[bcc_id].PB(bcc[id]);
					T[bcc[id]].PB(bcc_id);
					marked[bcc[id]] = true;
				}
			}
			for(auto [y, id] : V[i]) marked[bcc[id]] = false;
		}
	}
	for(int i = 0; i < m; ++i) {
		if(parity[edges[i].ST] == parity[edges[i].ND]) {
			odd[bcc[i]] = 1;
		}
	}
	for(int i = 1; i <= bcc_id; ++i) {
		if(!jp[i][0]) dfs(i, 0);
	}
	for(int step = 1; step < 18; ++step) {
		for(int i = 1; i <= bcc_id; ++i) {
			jp[i][step] = jp[jp[i][step - 1]][step - 1];
		}
	}
	cin >> q;
	while(q--) {
		int x, y, l;
		cin >> x >> y;
		if(cc[x] != cc[y] || (int)V[x].size() == 0 || (int)V[y].size() == 0 || x == y) {
			cout << "No\n";
			continue;
		}
		if(parity[x] != parity[y]) {
			cout << "Yes\n";
			continue;
		}
		if(art[x]) x = inv[x];
		else x = bcc[V[x][0].ND];
		if(art[y]) y = inv[y];
		else y = bcc[V[y][0].ND];
		l = lca(x, y);
		int sum = odd[x] + odd[y] - 2 * odd[l] + (odd[l] != odd[jp[l][0]]);
		if(sum > 0) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}