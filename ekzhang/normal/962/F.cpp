#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N, M;
vector<int> adj[MAXN];
map<pair<int, int>, int> eidx;

namespace tarjan {
	// int N;
	// vector<int> adj[MAXN];
	vector<pair<int, int> > bcc[MAXN];
	set<int> bccv[MAXN];
	int bccnum = 0;
	int in[MAXN], low[MAXN], t = 0;
	stack<pair<int, int> > s;
	bool visited[MAXN];

	void dfs(int n, int p=-1) {
		visited[n] = true;
		low[n] = in[n] = t++;
		for (int v : adj[n]) if (v != p) {
			if (!visited[v]) {
				s.emplace(v, n);
				dfs(v, n);
				low[n] = min(low[n], low[v]);
				if (low[v] >= in[n]) {
					while (true) {
						auto p = s.top();
						s.pop();
						bcc[bccnum].push_back(p);
						bccv[bccnum].insert(p.first);
						bccv[bccnum].insert(p.second);
						if (p.first == v && p.second == n) break;
					}
					++bccnum;
				}
			}
			else if (in[v] < in[n]) {
				low[n] = min(low[n], in[v]);
				s.emplace(v, n);
			}
		}
	}

	void tarjan() {
		for (int i = 0; i < N; i++) {
			if (!visited[i])
				dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		eidx[{u, v}] = eidx[{v, u}] = i + 1;
	}

	tarjan::tarjan();

	vector<int> ans;
	for (int i = 0; i < tarjan::bccnum; i++) {
		if (tarjan::bcc[i].size() == tarjan::bccv[i].size()) {
			for (auto p : tarjan::bcc[i])
				ans.push_back(eidx[p]);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int x : ans) {
		cout << x << ' ';
	}

	cout << endl;
	return 0;
}