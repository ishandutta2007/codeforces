#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int head[210], to[10010], nxt[10010], w[10010], f[10010], tot;
char s[110];
int dist[210], edge[1010];
int h[210];
priority_queue <pii, vector <pii>, greater <pii> > Q;
int cnt[26], pre[210];
int S = 205, T = 206;

void add(int x, int y, int W, int F) {
	nxt[tot] = head[x], to[tot] = y, w[tot] = W, f[tot] = F, head[x] = tot++;
	nxt[tot] = head[y], to[tot] = x, w[tot] = 0, f[tot] = -F, head[y] = tot++;
}

bool Dij(int S, int T) {
	memset(dist, 0x3f, sizeof(dist));
	dist[S] = 0; Q.push(mp(0, S));
	while (!Q.empty()) {
		pii t = Q.top(); Q.pop();
		int x = t.se;
		if (dist[x] != t.fi) continue;
		for (int i = head[x]; ~i; i = nxt[i]) {
			int v = to[i];
			if (w[i] && dist[v] > dist[x] + f[i] + h[x] - h[v]) {
				dist[v] = dist[x] + f[i] + h[x] - h[v], pre[v] = x, edge[v] = i;
				Q.push(mp(dist[v], v));
			}
		}
	}
	return dist[T] != 0x3f3f3f3f;
}

pii min_cost() {
	int fff = 0, ccc = 0;
	while (1) {
		if (!Dij(S, T)) break;
		int flow = 0x3f3f3f3f, cost = h[T];
		int now = T;
		while (now != S) {
			flow = min(flow, w[edge[now]]), cost += f[edge[now]] - h[now] + h[pre[now]];
			now = pre[now];
		}
		fff += flow, ccc += cost * flow;
		now = T;
		while (now != S) {
			w[edge[now]] -= flow, w[edge[now] ^ 1] += flow;
			now = pre[now];
		}
		for (int i = 0; i <= T; i++) {
			h[i] += dist[i];
		}
	}
	return mp(fff, ccc);
}

int main () {
	memset(head, -1, sizeof(head));
	scanf("%s", s); int TOT = strlen(s);
	for (int i = 0; i < TOT; i++) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (!cnt[i]) continue;
		add(i, T, cnt[i], 0);
	}
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%s%d", s, &x); int m = strlen(s);
		add(S, i + 26, x, 0);
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < m; j++) {
			cnt[s[j] - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			if (!cnt[j]) continue;
			add(i + 26, j, cnt[j], i + 1);
		}
	}
	pii t = min_cost();
	printf("%d\n", t.fi != TOT ? -1 : t.se);
	return 0;
}