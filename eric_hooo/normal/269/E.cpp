#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef unsigned long long ull;
typedef pair <ull, int> pui;

const ull P = 323232323;

int N;

struct Graph {
	vector <int> G[400010];
	int vis[400010];
	vector <int> node;
	vector <vector <int> > data;
	vector <pui> all;
	Graph() {clear();}
	void clear() {for (int i = 0; i < 400005; i++) G[i].clear();}
	void AddEdge(int x, int y) {
		G[x].push_back(y);
		G[y].push_back(x);
	}
	void dfs(int x) {
		vis[x] = 1, node.push_back(x);
		for (auto v : G[x]) {
			if (!vis[v]) dfs(v);
		}
	}
	void Flush(vector <int> &a) {
		int p1 = 0, p2 = 1;
		while (p2 < a.size()) {
			int k = 0;
			while (k < a.size() && a[(p1 + k) % a.size()] / N == a[(p2 + k) % a.size()] / N) k++;
			if (k == a.size()) break;
			if (a[(p1 + k) % a.size()] / N > a[(p2 + k) % a.size()] / N) {
				p1 += k + 1;
				if (p1 <= p2) p1 = p2 + 1;
				swap(p1, p2);
			} else p2 += k + 1;
		}
		for (int i = 0; i < p1; i++) a.push_back(a[i]);
		a.erase(a.begin(), a.begin() + p1);
	}
	ull GetHash(const vector <int> &node) {
		ull H = 0;
		for (auto x : node) H = H * P + x / N;
		return H;
	}
	void GetAll() {
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 4 * N; i++) {
			if (vis[i]) continue;
			node.clear(), dfs(i);
			if (node.size() == 1) continue;
			Flush(node);
			vector <int> tmp = node; reverse(tmp.begin(), tmp.end());
			Flush(tmp);
			for (int i = 0; i < node.size(); i++) {
				if (node[i] / N != tmp[i] / N) {
					if (node[i] > tmp[i]) node = tmp;
					break;
				}
			}
			all.push_back(mp(GetHash(node), (int)data.size()));
			data.push_back(node);
		}
		sort(all.begin(), all.end());
	}
}G1, G2;

int GetId(char c) {return c == 'L' ? 0 : c == 'T' ? 1 : c == 'R' ? 2 : 3;}

int cnt[4][4];
int px[100010], py[100010];

int main() {
	goto MAIN;
	BAD:;
	printf("No solution\n");
	return 0;
	MAIN:;
	int n, m; scanf("%d%d", &n, &m);
	N = max(n, m);
	for (int i = 0; i < n + m; i++) {
		char d1[2], d2[2]; int x, y; scanf("%s%s%d%d", d1, d2, &x, &y), x--, y--;
		int id1 = GetId(d1[0]), id2 = GetId(d2[0]);
		cnt[id1][id2]++, cnt[id2][id1]++;
		G1.AddEdge(id1 * N + x, id2 * N + y);
	}
	for (int i = 0; i < n; i++) G1.AddEdge(0 * N + i, 2 * N + i), G2.AddEdge(0 * N + i, 2 * N + i);
	for (int i = 0; i < m; i++) G1.AddEdge(1 * N + i, 3 * N + i), G2.AddEdge(1 * N + i, 3 * N + i);
	if (cnt[0][2] && cnt[1][3]) goto BAD;
	if (cnt[0][1] != cnt[2][3]) goto BAD;
	for (int i = 0; i < cnt[0][1]; i++) G2.AddEdge(0 * N + i, 1 * N + i);
	for (int i = 0; i < cnt[2][3]; i++) G2.AddEdge(2 * N + n - i - 1, 3 * N + m - i - 1);
	for (int i = 0; i < cnt[0][3]; i++) G2.AddEdge(0 * N + n - i - 1, 3 * N + i);
	for (int i = 0; i < cnt[2][1]; i++) G2.AddEdge(2 * N + i, 1 * N + m - i - 1);
	for (int i = 0; i < cnt[0][2]; i++) G2.AddEdge(0 * N + cnt[0][1] + i, 2 * N + cnt[2][1] + i);
	for (int i = 0; i < cnt[1][3]; i++) G2.AddEdge(1 * N + cnt[0][1] + i, 3 * N + cnt[0][3] + i);
	G1.GetAll();
	G2.GetAll();
	if (G1.all.size() != G2.all.size()) goto BAD;
	for (int i = 0; i < G1.all.size(); i++) {
		if (G1.all[i].fi != G2.all[i].fi) goto BAD;
	}
	for (int i = 0; i < G1.all.size(); i++) {
		const vector <int> &a = G1.data[G1.all[i].se], &b = G2.data[G2.all[i].se];
		for (int j = 0; j < a.size(); j++) {
			int x = a[j], y = b[j];
			if (x / N == 0) px[y % N] = x % N;
			if (x / N == 1) py[y % N] = x % N;
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", px[i] + 1); printf("\n");
	for (int i = 0; i < m; i++) printf("%d ", py[i] + 1); printf("\n");
	return 0;
}