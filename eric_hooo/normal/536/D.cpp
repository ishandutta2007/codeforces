#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <long long, int> pli;

const long long INF = 0x3f3f3f3f3f3f3f3f;

int a[2010];
vector <pii> from[2010];
long long d1[2010], d2[2010], vis[2010];
priority_queue <pli, vector <pli>, greater <pli> > q;
long long f[2010][2010], g[2010][2010];
long long sp[2010][2010], sq[2010][2010];
long long mf[2010][2010], mg[2010][2010];

void get_dist(int S, long long *dist) {
	dist[S] = 0, q.push(mp(0, S));
	while (!q.empty()) {
		pli t = q.top(); q.pop();
		int x = t.se;
		if (dist[x] != t.fi) continue;
		for (int i = 0; i < from[x].size(); i++) {
			int v = from[x][i].fi, w = from[x][i].se;
			if (dist[v] > dist[x] + w) {
				dist[v] = dist[x] + w;
				q.push(mp(dist[v], v));
			}
		}
	}
}

bool cmp1(int x, int y) {
	return d1[x] < d1[y];
}

bool cmp2(int x, int y) {
	return d2[x] < d2[y];
}

int main () {
	int n, m; scanf("%d%d", &n, &m);
	int S, T; scanf("%d%d", &S, &T);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		from[x].push_back(mp(y, c));
		from[y].push_back(mp(x, c));
	}
	memset(d1, 0x3f, sizeof(d1)), memset(d2, 0x3f, sizeof(d2));
	get_dist(S, d1), get_dist(T, d2);
	vector <int> p, q;
	for (int i = 1; i <= n; i++) {
		p.push_back(i), q.push_back(i);
	}
	sort(p.begin(), p.end(), cmp1), sort(q.begin(), q.end(), cmp2);
	reverse(p.begin(), p.end()), reverse(q.begin(), q.end());
	memset(vis, 0, sizeof(vis));
	for (int i = p.size(); i >= 0; i--) {
		if (i != p.size()) vis[p[i]] = 1;
		for (int j = 1; j <= q.size(); j++) {
			sq[i][j] = sq[i][j - 1] + (vis[q[j - 1]] ? 0 : a[q[j - 1]]);
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int j = q.size(); j >= 0; j--) {
		if (j != q.size()) vis[q[j]] = 1;
		for (int i = 1; i <= p.size(); i++) {
			sp[i][j] = sp[i - 1][j] + (vis[p[i - 1]] ? 0 : a[p[i - 1]]);
		}
	}
	f[0][0] = 0, g[0][0] = 0;
	for (int i = 0; i <= p.size(); i++) {
		for (int j = 0; j <= q.size(); j++) {
			if (!i && !j) {
				f[i][j] = g[i][j] = 0;
				continue;
			}
			// f
			if (i) {
				if (sp[i][j] == sp[i - 1][j]) f[i][j] = f[i - 1][j];
				else f[i][j] = mf[i - 1][j] + sp[i][j];
				mg[i][j] = f[i][j] + sq[i][j];
				if (j) mg[i][j] = min(mg[i][j], mg[i][j - 1]);
			}
			// g
			if (j) {
				if (sq[i][j] == sq[i][j - 1]) g[i][j] = g[i][j - 1];
				else g[i][j] = mg[i][j - 1] - sq[i][j];
				mf[i][j] = g[i][j] - sp[i][j];
				if (i) mf[i][j] = max(mf[i][j], mf[i - 1][j]);
			}
		}
	}
	long long ans = f[p.size()][q.size()];
	if (ans > 0) printf("Break a heart\n");
	else if (ans == 0) printf("Flowers\n");
	else printf("Cry\n");
	return 0;
}