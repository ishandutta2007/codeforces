#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+1;
int deg[N];
int root[N];

void init() {
	memset(root, -1, sizeof root);
}

int find(int i) {
	if (root[i] == -1) return i;
	return root[i] = find(root[i]);
}

void link(int i, int j) {
	if (find(i) != find(j)) root[find(i)] = find(j);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
	init();

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
		link(a,b);
	}

	unordered_map<int,vector<int>> comp;
	for (int i = 1; i <= n; i++) {
		comp[find(i)].push_back(i);
	}

	int ans = 0;
	for (const pair<int,vector<int>>& it : comp) {
		bool bad = false;
		for (int v : it.second) {
			if (deg[v] != 2) bad = true;
		}
		if (!bad) ans++;
	}

	cout << ans << nl;

	return 0;
}