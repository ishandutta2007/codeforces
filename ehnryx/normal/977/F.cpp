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
int sz[N];

void init() {
	memset(root, -1, sizeof root);
}

int find(int i) {
	if (root[i] == -1) return i;
	return root[i] = find(root[i]);
}

// i <- j
void link(int i, int j) {
	if (find(i) != find(j)) {
		sz[find(i)] += sz[find(j)] + 1;
		root[find(j)] = find(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
	init();

	int n;
	cin >> n;

	int a[n];
	map<int,int> index;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (index.count(a[i]-1)) {
			link(index[a[i]-1], i);
			index.erase(a[i]-1);
		}
		if (!index.count(a[i]) || sz[find(i)] > sz[find(index[a[i]])])
			index[a[i]] = i;
	}

	int best = 0;
	for (int i = 1; i < n; i++) {
		if (sz[find(i)] > sz[find(best)]) best = i;
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (find(i) == find(best)) ans.push_back(i);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << nl;
	for (int it : ans) cout << it+1 << " ";
	cout << nl;

	return 0;
}