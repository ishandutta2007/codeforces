#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 300013
#define MAXM 300013
int N, M;
int S[MAXN];
set<int> flv[MAXN];
vector<int> adj[MAXN];
int ans = 1;
int color[MAXM];

void dfs(int n, int p=0) {
	set<int> s;
	int cur = 1;
	for (int x : flv[n]) {
		if (color[x]) {
			s.insert(color[x]);
		}
	}
	for (int x : flv[n]) {
		if (!color[x]) {
			while (s.count(cur)) cur++;
			color[x] = cur++;
		}
	}

	for (int v : adj[n]) {
		if (v != p) {
			dfs(v, n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
		ans = max(ans, S[i]);
		for (int j = 0; j < S[i]; j++) {
			int k; cin >> k;
			flv[i].insert(k);
		}
	}

	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	cout << ans << endl;
	for (int i = 1; i <= M; i++) {
		cout << (color[i] ? color[i] : 1) << ' ';
	}

	cout << endl;
	return 0;
}