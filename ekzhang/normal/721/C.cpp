#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
typedef pair<int, pair<int, int> > piii;
#define MAXN 5013
#define INF 1000000013

int N, M;
LL T;
map<int, LL> adj[MAXN];
int dist[MAXN][MAXN];
bool visited[MAXN][MAXN];
int prevn[MAXN][MAXN];
priority_queue<piii, vector<piii>, greater<piii> > pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> T;
	for (int i = 0; i < M; i++) {
		int u, v;
		LL t;
		cin >> u >> v >> t;
		adj[u-1][v-1] = t;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N; j++) {
			dist[i][j] = INF;
			prevn[i][j] = -1;
		}
	}
	dist[0][1] = 0;
	pq.push(piii {0, {0, 1}});

	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();

		int d = p.first;
		int v = p.second.first;
		int n = p.second.second;

		if (visited[v][n]) continue;
		visited[v][n] = true;

		for (auto p : adj[v]) {
			int u = p.first;
			if (d + adj[v][u] < dist[u][n + 1]) {
				dist[u][n + 1] = d + adj[v][u];
				pq.push(piii {dist[u][n + 1], {u, n + 1}});
				prevn[u][n + 1] = v;
			}
		}
	}

	int k = N;
	while (k) {
		if (dist[N - 1][k] <= T) {
			break;
		}
		k--;
	}

	if (!k) {
		cout << -1 << endl;
		return 0;
	}

	cout << k << '\n';
	int c = N - 1;
	vector<int> ans;
	ans.push_back(c);
	while (prevn[c][k] != -1) {
		c = prevn[c][k];
		ans.push_back(c);
		k--;
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] + 1 << ' ';
	}

	cout << endl;
	return 0;
}