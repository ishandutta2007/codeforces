#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 300010;

int n, m, ql, qr;
int dis[N], frm[N];
int q[N];
bool vis[N];

set<int> ed[N];
vector<int> ans;

void out() {
	printf("%d\n1", (int)ans.size());
	for (int i = 0; i < ans.size(); ++i)
		printf(" %d", ans[i]);
	putchar('\n');
	exit(0);
}

void bfs(int u) {
	ql = 0;
	qr = 1;
	q[0] = u;
	vis[u] = true;
	while (ql < qr) {
		u = q[ql++];
		for (int v : ed[u])
			if (v != 1 && !vis[v]) {
				vis[v] = true;
				q[qr++] = v;
			}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		ed[u].insert(v);
		ed[v].insert(u);
	}
	qr = 1;
	q[0] = 1;
	memset(dis, -1, sizeof(dis));
	dis[1] = 0;
	while (ql < qr) {
		int u = q[ql++];
		for (int v : ed[u])
			if (dis[v] == -1) {
				frm[v] = u;
				dis[v] = dis[u] + 1;
				q[qr++] = v;
			}
	}
	if (dis[n] != -1) {
		ans.resize(dis[n]);
		int cnt = dis[n] - 1;
		int u = n;
		while (u != 1) {
			ans[cnt--] = u;
			u = frm[u];
		}
		if (ans.size() < 4)
			out();
	}

	for (int i = 1; i < qr; ++i)
		if (dis[q[i]] == 2) {
			ans.resize(4);
			ans[3] = n;
			ans[2] = 1;
			ans[1] = q[i];
			ans[0] = frm[q[i]];
			out();
		}

	if (ans.size() < 5 && !ans.empty())
		out();

	for (int i = 2; i < n; ++i)
		if (dis[i] != -1 && !vis[i]) {
			bfs(i);
			int u = 0, v;
			bool flag = false;
			for (int j = 0; j < qr; ++j) {
				for (int k = 0; k < j; ++k) {
					u = q[j];
					v = q[k];
					if (!ed[u].count(v)) {
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
			if (!flag)
				continue;
			ans.resize(5);
			ans[0] = u;
			ans[3] = u;
			ans[4] = n;
			ql = 0;
			qr = 1;
			q[0] = u;
			memset(dis, -1, sizeof(dis));
			dis[u] = 0;
			while (ql < qr) {
				int u = q[ql++];
				for (int v : ed[u])
					if (dis[v] == -1 && v != 1) {
						dis[v] = dis[u] + 1;
						q[qr++] = v;
						if (dis[v] == 2) {
							ans[1] = u;
							ans[2] = v;
							out();
						}
					}
			}
		}

	if (!ans.empty())
		out();

	puts("-1");
	return 0;
}