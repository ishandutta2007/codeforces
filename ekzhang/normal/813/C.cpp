#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 200013
int N, X;
vector<int> adj[MAXN];
int parent[MAXN];
int dist[MAXN];
int maxdist = 0;

void dfs(int n, int p) {
	dist[n] = dist[p] + 1;
	parent[n] = p;
	for (int v : adj[n]) {
		if (v != p) {
			dfs(v, n);
		}
	}
}

void dfs2(int n) {
	maxdist = max(maxdist, dist[n]);
	for (int v : adj[n]) {
		if (v != parent[n]) {
			dfs2(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> X;
	X--;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dist[0] = -1;
	dfs(0, 0);

	// thanks avichal :)
	int d = dist[X];
	for (int i = 0; i < (d - 1) / 2; i++) {
		X = parent[X];
	}

	dfs2(X);

	cout << maxdist * 2 << endl;
	return 0;
}