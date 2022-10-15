#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 1013
#define MAXG 3013
int N, K, G;
int M;
int S[MAXN], T[MAXN], C[MAXN];
vector<int> adj[MAXG];
int cap[MAXG][MAXG];
int cost[MAXG][MAXG];
int pre[MAXG], dist[MAXG];
list<int> q;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
bool visited[MAXG];

void link(int u, int v, int f=50, int c=0) {
	adj[u].push_back(v);
	adj[v].push_back(u);
	cap[u][v] = f;
	cost[u][v] = c;
	cost[v][u] = -c;
}

void spfa(int s) {
	memset(pre, -1, sizeof pre);
	memset(dist, 63, sizeof dist); // 0x3f3f3f3f, trying out infinity value

	dist[s] = 0;
	q.push_back(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		visited[v] = false;
		for (int u : adj[v]) if (cap[v][u]) {
			int d = dist[v] + cost[v][u];
			if (d < dist[u]) {
				dist[u] = d, pre[u] = v;
				if (!visited[u]) {
					if (q.size() && d < dist[q.front()]) q.push_front(u);
					else q.push_back(u);
					visited[u] = true;
				}
			}
		}
	}
}

void dijkstra(int s) {
	memset(pre, -1, sizeof pre);
	memset(dist, 63, sizeof dist); // 0x3f3f3f3f, trying out infinity value
	memset(visited, 0, sizeof visited);

	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		int v = pq.top().second;
		pq.pop();
		if (visited[v]) continue;
		visited[v] = true;
		for (int u : adj[v]) if (cap[v][u]) {
			int d = dist[v] + cost[v][u];
			if (d < dist[u]) {
				dist[u] = d, pre[u] = v;
				pq.push({d, u});
			}
		}
	}
}

void reweight() {
	// precondition: dist[] must be calculated
	// postcondition: all costs become positive
	for (int v = 0; v < G; v++) {
		for (int u : adj[v]) {
			cost[v][u] += dist[v] - dist[u];
		}
	}
}

int ford_fulkerson(int s, int t) {
	// Time Complexity: O(VE + Ef lg V) worst-case; O(Ef lg V) average.
	spfa(s);
	int totalflow = 0;
	while (true) {
		reweight();
		dijkstra(s);
		if (~pre[t]) {
			int flow = 50;
			for (int v = t; ~pre[v]; v = pre[v])
				flow = min(flow, cap[pre[v]][v]);
			for (int v = t; ~pre[v]; v = pre[v]) {
				cap[pre[v]][v] -= flow;
				cap[v][pre[v]] += flow;
			}
			totalflow += flow;
		}
		else break;
	}
	return totalflow;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	vector<int> times;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> T[i] >> C[i];
		T[i] += S[i];
		times.push_back(S[i]);
		times.push_back(T[i]);
	}

	sort(times.begin(), times.end());
	times.resize(unique(times.begin(), times.end()) - times.begin());
	M = times.size();

	assert(M <= 2 * N);

	for (int i = 0; i < N; i++) {
		S[i] = lower_bound(times.begin(), times.end(), S[i]) - times.begin();
		T[i] = lower_bound(times.begin(), times.end(), T[i]) - times.begin();
	}

	// source and sink
	const int s = M + 1;
	const int t = M;
	const int est = M + 2;
	G = N + M + 2;

	link(s, 0, K);
	for (int i = 0; i < M; i++) {
		link(i, i + 1);
	}

	for (int i = 0; i < N; i++) {
		int cur = est + i;
		link(S[i], cur, 1, -C[i]);
		link(cur, T[i], 1);
	}

	int flow = ford_fulkerson(s, t);
	assert(flow == K);

	for (int i = 0; i < N; i++) {
		cout << cap[T[i]][est + i] << ' ';
	}

	cout << endl;
	return 0;
}