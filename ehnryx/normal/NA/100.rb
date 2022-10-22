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

const int N = 1e5+1;

vector<int> adj[N];
int par[N], h[N], a[N], s[N];

void dfs(int cur) {
	int minv = INF;
	for (int x : adj[cur]) {
		dfs(x);
		minv = min(minv, s[x]);
	}
	if (s[cur] == -1) {
		if (minv == INF) {
			s[cur] = s[par[cur]];
		} else {
			s[cur] = minv;
		}
	}
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

	int n;
	cin >> n;


	h[1] = 1;
	for (int i=2; i<=n; i++) {
		cin >> par[i];
		h[i] = h[par[i]]+1;
		adj[par[i]].push_back(i);
	}

	for (int i=1; i<=n; i++) {
		cin >> s[i];
		if (s[i] == -1 && h[i]%2) goto gulag;
		if (s[i] != -1 && h[i]%2 == 0) goto gulag;
	}
	a[1] = s[1];

	{
		dfs(1);
		ll sum = a[1];
		for (int i=2; i<=n; i++) {
			if (s[i] < s[par[i]]) goto gulag;
			sum += s[i] - s[par[i]];
		}
		cout << sum << nl;
	}

	return 0;

gulag:
	cout << -1 << nl;

	return 0;
}