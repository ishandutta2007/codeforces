#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

int val[100001];
vector<int> graph[100001];
bitset<100001> visited;

int bribe(int s) {
	if (visited[s])
		return 0;
	int res = INF;
	stack<int> next;
	next.push(s);
	while (!next.empty()) {
		int cur = next.top();
		next.pop();
		res = min(res, val[cur]);
		visited[cur] = true;
		for (int neighbour : graph[cur]) {
			if (!visited[neighbour]) {
				next.push(neighbour);
			}
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b;

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += bribe(i);
	}
	cout << ans << nl;

	return 0;
}