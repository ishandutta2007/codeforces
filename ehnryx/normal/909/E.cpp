#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

inline void srand() { srand(clock() + time(nullptr)); }

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;

const ll MOD = 1e9+7;
const ld EPS = 1e-9;

int deg[100000];
int val[100000];
int dist[100000];
vector<int> graph[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}

	int a, b;
	vector<bool> notleaf(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[b].push_back(a);
		notleaf[a] = true;
		deg[a]++;
	}

	queue<int> next;
	for (int i = 0; i < n; i++) {
		if (!notleaf[i]) {
			next.push(i);
			dist[i] = val[i];
		}
	}

	int ans = 0;
	while (!next.empty()) {
		int cur = next.front();
		next.pop();

		ans = max(ans, dist[cur]);

		if (val[cur] == 1) {
			for (int x : graph[cur]) {
				if (val[x] == 1)
					dist[x] = max(dist[x], dist[cur]);
				else
					dist[x] = max(dist[x], dist[cur]);
				deg[x]--;
				if (deg[x] == 0) {
					next.push(x);
				}
			}
		}

		else {
			for (int x : graph[cur]) {
				if (val[x] == 1)
					dist[x] = max(dist[x], dist[cur]+1);
				else
					dist[x] = max(dist[x], dist[cur]);
				deg[x]--;
				if (deg[x] == 0) {
					next.push(x);
				}
			}
		}
	}

	cout << ans << nl;

	return 0;
}