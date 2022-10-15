#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define double long double
typedef long long LL;

#define MAXN 100013
#define MAXC MAXN
int N, M, Q;
int ufd[MAXN];
vector<int> adj[MAXN];
set<int> t;

int C;
int to_cpt[MAXN];
int root[MAXC];
int parent[MAXN];
int sz[MAXC];
vector<int> nodes[MAXC];

int A[MAXN];
map<pair<int, int>, int> far;
int diam[MAXC];
map<pair<int, int>, double> memo;

vector<LL> X[MAXC];
vector<LL> Y[MAXC];

int fi(int a) {
	if (ufd[a] == a) return a;
	else return ufd[a] = fi(ufd[a]);
}

void un(int a, int b) {
	a = fi(a);
	b = fi(b);
	ufd[a] = b;
}

void dfs(int n, int p, int cpt) {
	parent[n] = p;
	to_cpt[n] = cpt;
	sz[cpt]++;
	for (int v : adj[n]) {
		if (v != p) {
			dfs(v, n, cpt);
		}
	}
}

int calc_far(int n, int p=-1) {
	pair<int, int> pii = {n, p};
	if (far.count(pii)) {
		return far[pii];
	}
	int ret = 0;
	for (int v : adj[n]) {
		if (v != p) {
			ret = max(ret, 1 + calc_far(v, n));
		}
	}
	far[pii] = ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cout << fixed << setprecision(12);

	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) {
		ufd[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		un(u, v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < N; i++) {
		t.insert(fi(i));
	}
	for (auto x : t) {
		root[C++] = x;
	}

	for (int i = 0; i < C; i++) {
		dfs(root[i], -1, i);
		X[i].resize(sz[i]);
		Y[i].resize(sz[i]);
	}

	for (int i = 0; i < N; i++) {
		calc_far(i);
		A[i] = far[{i, -1}];
		diam[to_cpt[i]] = max(diam[to_cpt[i]], A[i]);
	}

	for (int i = 0; i < N; i++) {
		int cpt = to_cpt[i];
		X[cpt][A[i]]++;
		Y[cpt][A[i]] += A[i];
		nodes[cpt].push_back(i);
	}

	for (int i = 0; i < C; i++) {
		for (int j = 1; j < X[i].size(); j++) {
			X[i][j] += X[i][j-1];
			Y[i][j] += Y[i][j-1];
		}
	}

	for (int i = 0; i < Q; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		u = fi(u);
		v = fi(v);
		if (u == v) {
			cout << -1 << '\n';
			continue;
		}
		if (u > v) swap(u, v);
		pair<int, int> pii = {u, v};
		if (memo.count(pii)) {
			cout << memo[pii] << '\n';
			continue;
		}

		int c1 = to_cpt[u], c2 = to_cpt[v];
		if (sz[c1] > sz[c2]) {
			swap(c1, c2);
			swap(u, v);
		}

		double ans = 0;
		for (int a : nodes[c1]) {
			int d2 = max(diam[c1], diam[c2]);
			int k = d2 - A[a] - 1;
			// error(k, d2, X[c2][k], Y[c2][1]);
			if (~k)
				ans += (((double) X[c2][k]) * d2 + (Y[c2][sz[c2] - 1] - Y[c2][k] + (sz[c2] - X[c2][k]) * ((double) A[a] + 1))) / sz[c2];
			else
				ans += ((Y[c2][sz[c2] - 1] + (sz[c2]) * ((double) A[a] + 1))) / sz[c2];
		}
		ans /= sz[c1];

		memo[pii] = ans;
		cout << ans << '\n';
	}

	cout.flush();
	return 0;
}