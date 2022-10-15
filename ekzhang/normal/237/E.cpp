#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

string T;
#define MAXN 130
#define INF 1e9
int N;
string S[MAXN];
int A[MAXN];
map<int, int> cap[MAXN];
map<int, int> cost[MAXN];

int maxflow = 0;
int mincost = 0;
int dist[MAXN];
int pre[MAXN];
bool inqueue[MAXN];

void spfa(int source) {
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
		pre[i] = -1;
		inqueue[i] = false;
	}
	dist[source] = 0;
	list<int> q;
	q.push_back(source);
	inqueue[source] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		inqueue[v] = false;
		for (auto p : cap[v]) {
			if (!p.second) continue;
			int u = p.first;
			if (dist[v] + cost[v][u] < dist[u]) {
				dist[u] = dist[v] + cost[v][u];
				pre[u] = v;
				if (!inqueue[u]) {
					if (dist[u] < dist[q.front()]) {
						q.push_front(u);
					}
					else {
						q.push_back(u);
					}
					inqueue[u] = true;
				}
			}
		}
	}
}

void bellmanford(int source) {
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
		pre[i] = -1;
	}
	dist[source] = 0;
	for (int c = 0; c < N - 1; c++) {
		for (int i = 0; i < N; i++) {
			for (auto p : cap[i]) {
				if (p.second && dist[i] + cost[i][p.first] < dist[p.first]) {
					dist[p.first] = dist[i] + cost[i][p.first];
					pre[p.first] = i;
				}
			}
		}
	}
}

void fordfulkerson(int source, int sink) {
	while (true) {
		bellmanford(source);
		if (dist[sink] == INF) break;
		int flow = INF;
		int pcost = 0;
		for (int v = sink; ~pre[v]; v = pre[v]) {
			flow = min(flow, cap[pre[v]][v]);
			pcost += cost[pre[v]][v];
		}
		for (int v = sink; ~pre[v]; v = pre[v]) {
			cap[pre[v]][v] -= flow;
			cap[v][pre[v]] += flow;
		}
		maxflow += flow;
		mincost += pcost * flow;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> A[i];
	}

	for (int i = 0; i < N; i++) {
		cost[0][1+i] = 1+i;
		cost[1+i][0] = -1-i;
		cap[0][1+i] = A[i];
	}

	for (int i = 0; i < N; i++) {
		int c[26];
		memset(c, 0, sizeof c);
		for (char ch : S[i]) {
			c[ch - 'a']++;
		}
		for (int k = 0; k < 26; k++) {
			if (c[k]) {
				cap[1+i][1+N+k] = c[k];
			}
		}
	}

	int c[26];
	memset(c, 0, sizeof c);
	for (char ch : T) {
		c[ch - 'a']++;
	}
	for (int k = 0; k < 26; k++) {
		if (c[k]) {
			cap[1+N+k][N+27] = c[k];
		}
	}

	N = N + 28;

	fordfulkerson(0, N - 1);

	if (maxflow == T.size()) {
		cout << mincost << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}