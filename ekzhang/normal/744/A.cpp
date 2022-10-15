#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 1013
#define MAXC 1013
int N, M, K;
bool isCapital[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];

int C = 0;
int sz[MAXC];
int esz[MAXC];
bool hasCapital[MAXC];

void dfs(int n) {
	if (visited[n]) return;
	visited[n] = true;
	sz[C]++;
	esz[C] += adj[n].size();
	if (isCapital[n]) hasCapital[C] = true;
	for (int x : adj[n]) {
		dfs(x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int c; cin >> c; c--; isCapital[c] = true;
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int center = -1;

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(i);
			esz[C] /= 2;
			if (hasCapital[C] && (center == -1 || sz[C] > sz[center])) {
				center = C;
			}
			C++;
		}
	}

	int ans = 0;
	int osz = 0;
	int oesz = 0;
	for (int i = 0; i < C; i++) {
		if (hasCapital[i] && i != center) {
			ans += sz[i] * (sz[i] - 1) / 2 - esz[i];
		}
		else {
			osz += sz[i];
			oesz += esz[i];
		}
	}

	ans += osz * (osz - 1) / 2 - oesz;

	cout << ans << endl;
	return 0;
}