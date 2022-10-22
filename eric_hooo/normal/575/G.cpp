#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

queue <int> q;
int lst[100010], dist[100010];
int path[100010], edge[100010], vis[100010];
pii minj[100010];
vector <int> res;
vector <int> val;
int n, S, T;
vector <pii> from[100010];

bool cmp(int x, int y) {
	return minj[x] < minj[y];
}

void get_path(int x) {
	if (x != S) {
		get_path(path[x]);
		val.push_back(edge[x]);
	}
	res.push_back(x);
}

void get_lst(int x) {
	if (x == T) return ;
	res.push_back(lst[x]);
	get_lst(lst[x]);
}

int main () {
	int m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, len; scanf("%d%d%d", &x, &y, &len);
		from[x].push_back(mp(y, len));
		from[y].push_back(mp(x, len));
	}
	S = 0, T = n - 1;
	memset(dist, -1, sizeof(dist));
	q.push(T), lst[T] = -1, dist[T] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < from[x].size(); i++) {
			int v = from[x][i].fi, d = from[x][i].se;
			if (d) continue;
			if (dist[v] != -1) continue;
			dist[v] = dist[x] + 1, lst[v] = x, q.push(v);
		}
	}
	vector <int> node; node.push_back(S), vis[S] = 1;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		minj[i] = mp(0x3f3f3f3f, 0x3f3f3f3f);
	}
	while (1) {
		vector <int> tmp;
		int rnk = 0;
		for (int i = 0; i < node.size(); i++) {
			int x = node[i];
			if (i) rnk += cmp(node[i - 1], node[i]);
			for (int j = 0; j < from[x].size(); j++) {
				int v = from[x][j].fi, d = from[x][j].se;
				if (!vis[v]) {
					if (minj[v] > mp(d, rnk)) minj[v] = mp(d, rnk), path[v] = x, edge[v] = d;
				}
			}
		}
		for (int i = 0; i < node.size(); i++) {
			int x = node[i];
			for (int j = 0; j < from[x].size(); j++) {
				int v = from[x][j].fi;
				if (!vis[v]) {
					vis[v] = 1, tmp.push_back(v);
				}
			}
		}
		sort(tmp.begin(), tmp.end(), cmp);
		node = tmp;
		int p = -1; rnk = 0;
		for (int i = 0; i < node.size(); i++) {
			int x = node[i];
			if (i) rnk += cmp(node[i - 1], node[i]);
			if (dist[x] != -1) {
				p = rnk;
				break;
			}
		}
		if (p == -1) continue;
		rnk = 0;
		for (int i = 0; i < node.size(); i++) {
			int x = node[i];
			if (i) rnk += cmp(node[i - 1], node[i]);
			if (rnk == p && dist[x] != -1) {
				if (ans == -1 || dist[x] < dist[ans]) ans = x;
			}
		}
		break;
	}
	int cur = ans;
	get_path(cur), get_lst(cur);
	reverse(val.begin(), val.end());
	for (int i = 0; i < val.size(); i++) {
		printf("%d", val[i]);
	}
	printf("\n");
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}