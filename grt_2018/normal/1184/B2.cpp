//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 110, INF = 1e9 + 10;
const int kax = 2000 + 10;
int G[nax][nax];
int n, m, A, B, con1, con2;
vector<tuple<int, int, int>> spaceships;
vector<pi>bases;
vi V[kax];
int match[kax];
bool vis[kax];

bool aug(int x) {
	vis[x] = true;
	for(int y : V[x]) {
		if(match[y] == -1) {
			match[y] = x, match[x] = y;
			return true;
		}
	}
	for(int y : V[x]) {
		if(!vis[match[y]] && aug(match[y])) {
			match[x] = y, match[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) G[i][j] = (i == j ? 0 : INF);
	for(int u, v, i = 0; i < m; ++i) {
		cin >> u >> v;
		G[u][v] = G[v][u] = 1;
	}
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
	cin >> A >> B >> con1 >> con2;
	for(int x, a, f, i = 0; i < A; ++i) {
		cin >> x >> a >> f;
		spaceships.emplace_back(x, a, f);
	}
	for(int x, d, i = 0; i < B; ++i) {
		cin >> x >> d;
		bases.emplace_back(x, d);
	}
	for(int i = 0; i < A; ++i) {
		for(int j = 0; j < B; ++j) {
			auto &[x, a, f] = spaceships[i];
			auto &[y, d] = bases[j];
			if(G[x][y] <= f && a >= d) {
				V[i << 1].PB(j << 1 | 1);
				V[j << 1 | 1].PB(i << 1);
			}
		}
	}
	int matching = 0;
	for(int i = 0; i < 2 * max(A, B); ++i) match[i] = -1;
	while(true) {
		for(int i = 0; i < 2 * max(A, B); ++i) vis[i] = 0;
		int cnt = 0;
		for(int i = 0; i < 2 * max(A, B); ++i) {
			if(!vis[i] && match[i] == -1) {
				cnt += aug(i);
			}
		}
		if(cnt == 0) break;
		matching += cnt;
	}
	cout << min((ll)matching * con1, (ll)A * con2);

}