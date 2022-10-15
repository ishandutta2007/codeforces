#define NDEBUG

#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 200013
int N, K;
vector<int> adj[MAXN];
bool univ[MAXN];
long long depth[MAXN];
int parent[MAXN];
int usize[MAXN];
long long ans = 0;

void dfs(int n, int p) {
	parent[n] = p;
	usize[n] = univ[n];
	depth[n] = depth[p] + 1;

	auto it = find(adj[n].begin(), adj[n].end(), p);
	if (it != adj[n].end()) {
		adj[n].erase(it);
	}

	for (int x : adj[n]) {
		if (x != p) {
			dfs(x, n);
			usize[n] += usize[x];
		}
		else throw domain_error("bad dfs .-. erase");
	}
}

void solve(int n, int rm) {
	// error(n, rm);
	if (usize[n] == rm) return;	
	assert((usize[n] - rm) % 2 == 0);
	assert(usize[n] > rm);
	int ch = adj[n].size();
	if (ch == 1) {
		if (univ[n]) {
			ans -= 2 * depth[n];
			solve(adj[n][0], rm + 1);
		}
		else {
			solve(adj[n][0], rm);
		}
	}
	else {
		int tot = usize[n] - rm;
		int biggest = adj[n][0];
		for (int i : adj[n]) {
			if (usize[i] > usize[biggest]) {
				biggest = i;
			}
		}
		if (usize[biggest] - rm <= (usize[n] - rm) / 2) {
			// EZ MONEY
			// error(usize[26]);
			// error(usize[31]);
			ans -= depth[n] * (usize[n] - rm);
		}
		else {
			// oops bad
			int rest = usize[n] - usize[biggest];
			ans -= depth[n] * rest * 2;
			solve(biggest, rm + rest);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < 2 * K; i++) {
		int x; cin >> x; x--;
		univ[x] = true;
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, 0);
	solve(0, 0);

	// error(ans);
	// error(depth[14]); // 5
	// error(depth[5]); // 8
	// error(depth[34]); // 10
	// error(depth[33]); // 12
	// error(depth[10]); // 12
	// error(depth[9]) // 13

	for (int i = 0; i < N; i++) {
		if (univ[i]) {
			ans += depth[i];
		}
	}

	cout << ans << endl;
	return 0;
}