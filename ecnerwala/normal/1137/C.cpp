#include<bits/stdc++.h>
using namespace std;

void wssert(bool b) {
	if (!b) {
		cout << "GARBAGE\n";
		exit(0);
	}
}
void f(const vector<int>& verts);
namespace kactl {
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi val, comp, z, cont;
int Time, ncomps;
vector<vector<int>> g;
int dfs(int j) {
	int low = val[j] = ++Time; z.push_back(j);
	trav(e,g[j]) if (comp[e] < 0)
		low = min(low, val[e] ? val[e] : dfs(e));

	if (low == val[j]) {
		int x;
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
void scc(int st) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	//rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
	dfs(st);
}
}
using kactl::comp;
using kactl::ncomps;
using kactl::g;

const int MAXN = 1.1e5;
const int MAXM = 1.1e5;
const int MAXD = 60;

int N, M;
vector<int> adj[MAXN];

int D;
bool open[MAXN][MAXD];

vector<int> dp;
void f(const vector<int>& verts) {
	wssert(!verts.empty());

	vector<int> opens;
	for (int v : verts) {
		if (open[v / D][v % D]) {
			opens.push_back(v / D);
		}
	}
	sort(opens.begin(), opens.end());
	int nOpen = unique(opens.begin(), opens.end()) - opens.begin();

	wssert(int(dp.size()) == ncomps);
	dp.push_back(0);
	for (int cur : verts) {
		for (int nxt : g[cur]) {
			wssert(0 <= comp[nxt] && comp[nxt] <= ncomps);
			if (comp[nxt] == ncomps) continue;
			dp[ncomps] = max(dp[ncomps], dp[comp[nxt]]);
		}
	}
	dp[ncomps] += nOpen;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N >> M >> D;

	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
	}

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int d = 0; d < D; d++) {
			open[i][d] = (s[d] == '1');
		}
	}

	g = vector<vector<int>>(N * D);
	for (int i = 0; i < N; i++) {
		for (int j : adj[i]) {
			for (int d = 0; d < D; d++) {
				wssert(0 <= j && j < N);
				g[i * D + d].push_back(j * D + (d+1)%D);
			}
		}
	}

	using kactl::comp;
	using kactl::ncomps;
	kactl::scc(0);
	cout << dp[comp[0]] << '\n';

	return 0;
}