#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n;
bitset <110> mem[110][110];
string input[110][110];
int cnt[110][110];
vector <pii> edge;
vector <int> G[110];
map <string, int> all;

void AddEdge(int x, int y) {
	G[x].push_back(y), G[y].push_back(x);
	edge.push_back(mp(x, y));
}

// bool Solve(bitset <110> S) {
// 	int rt = 0; while (rt < n && !S[rt]) rt++;
// 	int has = 0;
// 	for (int x = rt + 1; x < n; x++) if (S[x]) {
// 		if (mem[x][rt].count() == 0) continue;
// 		has = 1;
// 		int bad = 0;
// 		for (int i = 0; i < n; i++) if (S[i] && mem[rt][x][i] && mem[rt][i].count()) {
// 			if (!(mem[rt][i] & mem[x][i] & S).count()) {
// 				bad = 1;
// 				break;
// 			}
// 		}
// 		if (bad) continue;
// 		cout << "    rt:" << rt << " -> " << x << endl;
// 		bitset <110> tmp = S & mem[rt][x];
// 		if (!Solve(tmp)) return 0;
// 		int par = -1;
// 		for (int i = 0; i < n; i++) if (tmp[i] && !mem[rt][i].count()) {
// 			bitset <110> qwq = tmp;
// 			for (auto j : G[i]) {
// 				qwq &= mem[rt][j];
// 			}
// 			if (qwq.count() && qwq[i]) {
// 				par = i;
// 				break;
// 			}
// 		}
// 		if (par == -1) return 0;
// 		AddEdge(rt, par), AddEdge(x, par);
// 		S ^= tmp, S[rt] = 0, S[x] = 0;
// 		static queue <pii> q; q.push(mp(par, x)), q.push(mp(par, rt));
// 		while (!q.empty()) {
// 			pii t = q.front(); q.pop();
// 			for (int i = 0; i < n; i++) if (S[i] && mem[t.fi][i][t.se] == 1) {
// 				AddEdge(i, t.se);
// 				q.push(mp(t.se, i));
// 				S[i] = 0;
// 			}
// 		}
// 		if (S.count()) return 0;
// 		return 1;
// 	}
// 	if (has) return 0;
// 	for (int i = rt + 1; i < n; i++) if (S[i]) {
// 		AddEdge(rt, i);
// 	}
// 	return 1;
// }

bool Solve(int rt) {
	bitset <110> qwq; for (int i = 0; i < n; i++) qwq[i] = 1; qwq[rt] = 0;
	for (int i = 0; i < n; i++) if (i != rt && mem[i][rt].count() && cnt[i][rt] == 1) {
		qwq &= mem[i][rt];
	}
	if (qwq.count() != 1) return 0;
	int x = 0; while (!qwq[x]) x++;
	AddEdge(rt, x);
	static queue <pii> q; q.push(mp(rt, x));
	static int vis[110]; for (int i = 0; i < n; i++) vis[i] = 0; vis[rt] = vis[x] = 1;
	while (!q.empty()) {
		pii t = q.front(); q.pop();
		for (int i = 0; i < n; i++) if (!vis[i] && mem[t.fi][i][t.se] == 1) {
			AddEdge(i, t.se);
			q.push(mp(t.se, i));
			vis[i] = 1;
		}
	}
	; for (int i = 0; i < n; i++) if (!vis[i]) return 0;
	return 1;
}

void GetDist(int x, int last, int *d) {
	for (auto v : G[x]) if (v != last) {
		d[v] = d[x] + 1, GetDist(v, x, d);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		all.clear();
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
			static char buf[110]; scanf("%s", buf);
			input[i][j] = input[j][i] = buf;
			for (int k = 0; k < 110; k++) {
				if (k < n && buf[k] == '1') mem[j][i][k] = mem[i][j][k] = 1;
				else mem[j][i][k] = mem[i][j][k] = 0;
			}
			all[input[i][j]]++;
		}
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
			cnt[i][j] = cnt[j][i] = all[input[i][j]];
		}
		// if (!Solve(tmp)) {
		// 	printf("No\n");
		// 	continue;
		// }
		auto Check = [&]() -> bool {
			static int dist[110][110];
			for (int i = 0; i < n; i++) {
				dist[i][i] = 0, GetDist(i, i, dist[i]);
			}
			for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (mem[i][j][k] != (dist[i][k] == dist[j][k])) {
						// cerr << "                     :" << i << " " << j << " " << k << endl;
						return 0;
					}
				}
			}
			return 1;
		};
		// cerr << "     edge:"; for (auto it : edge) cerr << "  " << it.fi + 1 << " " << it.se + 1; cerr << endl;
		int good = 0;
		for (int rt = 0; rt < n; rt++) {
			; for (int i = 0; i < n; i++) G[i].clear();
			edge.clear();
			if (Solve(rt) && Check()) {
				good = 1;
				break;
			}
		}
		if (!good) {
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		; for (auto &it : edge) if (it.fi < it.se) swap(it.fi, it.se);
		sort(edge.begin(), edge.end());
		for (auto it : edge) {
			printf("%d %d\n", it.fi + 1, it.se + 1);
		}
	}
	return 0;
}