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

const int N = 2e5 + 1;
int degree[N];
unordered_set<int> adj[N];
unordered_set<int> graph[N];

void init() {
	memset(degree, 0, sizeof degree);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	init();

	int n;
	cin >> n;

	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a != 0) {
			adj[a].insert(i);
			adj[i].insert(a);
			graph[a].insert(i);
			graph[i].insert(a);
			degree[i]++;
			degree[a]++;
		}
	}

	if (n == 1) {
		cout << "YES" << nl;
		cout << 1 << nl;
		return 0;
	}

	queue<int> next;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 1) next.push(i);
	}

	vector<int> in(n+1, 0), out(n+1, 0);
	while (!next.empty()) {
		int cur = next.front();
		next.pop();
		if (adj[cur].size() == 0) break;
		int other = *adj[cur].begin();


		if ((degree[cur] - out[cur]) % 2 == 0) {
			in[cur]++;
			out[other]++;
		} else {
			out[cur]++;
			in[other]++;
		}

		adj[other].erase(cur);
		if (adj[other].size() == 1) {
			next.push(other);
		}
	}

	for (int i = 1; i <= n; i++) {
		if ((degree[i] - out[i]) % 2 != 0) {
			cout << "NO" << nl;
			return 0;
		}
		if (out[i] == 0) {
			next.push(i);
		}
	}

	vector<int> ans;
	while (!next.empty()) {
		int cur = next.front();
		next.pop();

		ans.push_back(cur);
		for (int x : graph[cur]) {
			if (out[x] > 0) {
				out[x]--;
				if (out[x] == 0) {
					next.push(x);
				}
			}
		}
	}

	assert(ans.size() == n);

	cout << "YES" << nl;
	for (int it : ans) {
		cout << it << nl;
	}

	return 0;
}