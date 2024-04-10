#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef mt19937 RNG;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	vector<int> adj[n+1];
	vector<int> par(n+1, -1);
	vector<int> depth(n+1, 0);
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		adj[par[i]].push_back(i);
	}

	stack<int> next;
	next.push(1);
	while (!next.empty()) {
		int cur = next.top();
		next.pop();
		for (int x : adj[cur]) {
			depth[x] = depth[cur]+1;
			next.push(x);
		}
	}

	vector<int> cnt(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cnt[depth[i]]++;
	}

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += cnt[i] % 2;
	}
	cout << ans << nl;

	return 0;
}