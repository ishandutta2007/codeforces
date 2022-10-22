#include <bits/stdc++.h>
using namespace std;

int p[250010], r[250010], m[250010], id[250010];
long long dist[250010];
vector <int> T[250010];
int vis[250010];
int q[2500010], ll, rr;
vector <long long> all;

void modify(int x, int val) {
	while (x <= all.size()) T[x].push_back(val), x += x & -x;
}

void query(int x, int val) {
	while (x) {
		while (T[x].size() && m[T[x].back()] <= val) {
			if (!vis[T[x].back()]) vis[T[x].back()] = 1, q[rr++] = T[x].back();
			T[x].pop_back();
		}
		x -= x & -x;
	}
}

bool cmp(int x, int y) {
	return m[x] > m[y];
}

int main () {
	int X, Y, P, R, n; scanf("%d%d%d%d%d", &X, &Y, &P, &R, &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d%d%d%d", &x, &y, &m[i], &p[i], &r[i]);
		dist[i] = 1ll * (X - x) * (X - x) + 1ll * (Y - y) * (Y - y);
		all.push_back(dist[i]), id[i] = i;
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	sort(id, id + n, cmp);
	for (int i = 0; i < n; i++) {
		dist[i] = lower_bound(all.begin(), all.end(), dist[i]) - all.begin() + 1;
	}
	for (int i = 0; i < n; i++) {
		modify(dist[id[i]], id[i]);
	}
	p[n] = P, r[n] = R;
	ll = rr = 0;
	q[rr++] = n;
	while (ll < rr) {
		int x = q[ll++];
		int pos = upper_bound(all.begin(), all.end(), 1ll * r[x] * r[x]) - all.begin();
		query(pos, p[x]);
	}
	printf("%d\n", rr - 1);
	return 0;
}