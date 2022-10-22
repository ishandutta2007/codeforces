#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n, m;
vector <int> G[200010];
vector <int> H[200010];
int used[200010];
int dist[200010];
priority_queue <pii, vector <pii>, greater <pii> > q;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y);
		H[y].push_back(x);
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[n] = 0, q.push(mp(dist[n], n));
	while (!q.empty()) {
		pii t = q.top(); q.pop();
		int x = t.se;
		if (dist[x] != t.fi) continue;
		for (auto v : H[x]) {
			used[v]++;
			if (dist[v] > dist[x] + (int)G[v].size() - used[v] + 1) {
				dist[v] = dist[x] + (int)G[v].size() - used[v] + 1;
				q.push(mp(dist[v], v));
			}
		}
	}
	printf("%d\n", dist[1]);
	return 0;
}