#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

int n, m, k;
vector <pii> from[200010];
vector <int> lst[200010];
int dist[200010];
int pre[200010];
queue <int> q;
char ans[200010];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(mp(y, i));
		from[y].push_back(mp(x, i));
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0, q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < from[x].size(); i++) {
			int v = from[x][i].fi, id = from[x][i].se;
			if (dist[v] > dist[x] + 1) {
				dist[v] = dist[x] + 1;
				lst[v] = {id};
				q.push(v);
			} else if (dist[v] == dist[x] + 1) {
				lst[v].push_back(id);
			}
		}
	}
	pre[1] = 1;
	for (int i = 2; i <= n; i++) {
		pre[i] = min((long long)pre[i - 1] * (int)lst[i].size(), (long long)INF);
	}
	printf("%d\n", min(pre[n], k));
	for (int v = 0; v < min(pre[n], k); v++) {
		for (int i = 0; i < m; i++) {
			ans[i] = '0';
		}
		int cur = v;
		for (int i = 2; i <= n; i++) {
			int x = cur % lst[i].size();
			ans[lst[i][x]] = '1', cur /= lst[i].size();
		}
		printf("%s\n", ans);
	}
	return 0;
}