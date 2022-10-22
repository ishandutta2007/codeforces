#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+1;
int par[N];
int subsz[N];
vector<int> adj[N];
vector<int> order;
int idx[N];

int dfs(int cur) {
	idx[cur] = order.size();
	order.push_back(cur);
	subsz[cur] = 1;
	for (int x : adj[cur]) {
		subsz[cur] += dfs(x);
	}
	return subsz[cur];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, q;
	cin >> n >> q;

	for (int i=2; i<=n; i++) {
		cin >> par[i];
		adj[par[i]].push_back(i);
	}
	dfs(1);

	while (q--) {
		int a, b;
		cin >> a >> b;
		if (subsz[a] < b) {
			cout << -1 << nl;
		} else {
			cout << order[idx[a] + b-1] << nl;
		}
	}

	return 0;
}