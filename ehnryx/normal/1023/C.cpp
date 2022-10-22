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
vector<int> adj[N];
int par[N];

int dfs(int cur, int rem) {
	if (rem == 0) return 0;
	int vis = 1;
	if (cur) cout << '(';
	for (int x : adj[cur]) {
		vis += dfs(x, rem-vis);
	}
	if (cur) cout << ')';
	return vis;
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int id, cur;
	id = 1;
	cur = 0;
	for (char c : s) {
		if (c == '(') {
			par[id] = cur;
			adj[cur].push_back(id);
			cur = id++;
		} else {
			cur = par[cur];
		}
	}

	dfs(0, k/2+1);
	cout << nl;

	return 0;
}