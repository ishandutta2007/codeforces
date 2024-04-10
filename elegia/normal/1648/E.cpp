/*
 , .
 */
#include <cmath>
#include <cstring>

#include <algorithm>
#include <limits>
#include <random>
#include <chrono>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using ull = unsigned long long;
using ll = long long;

using namespace std;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
int reduce(int x) { return x < 0 ? x + P : x; }
int neg(int x) { return x ? P - x : 0; }
void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
int mpow(int x, unsigned k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}

const int _ = 200005, L = 20;

int tot;
int a[_], b[_], c[_];
pair<int, int> ord[_];
set<int> adj[_], ch[_ * 2], bigch[_];
int prt[_ * 2][L], dep[_ * 2], wt[_ * 2];

int f[_], siz[_]; // big
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
// int g[_ * 2]; // small
// int gind(int x) { return g[x] == x ? x : g[x] = gind(g[x]); }

int LCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int k = 0; k != L; ++k) if (((dep[u] - dep[v]) >> k) & 1) u = prt[u][k];
	if (u == v) return u;
	for (int k = L - 1; k >= 0; --k) if (prt[u][k] != prt[v][k]) {
		u = prt[u][k]; v = prt[v][k];
	}
	return prt[u][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		for (int i = 1; i <= M; ++i) {
			cin >> a[i] >> b[i] >> c[i];
			adj[a[i]].insert(b[i]); adj[b[i]].insert(a[i]);
			ord[i] = make_pair(c[i], i);
		}
		sort(ord + 1, ord + M + 1);
		fill(siz + 1, siz + N + 1, 1);
		iota(f + 1, f + N + 1, 1); //iota(g + 1, g + N * 2, 1);
		for (int i = 1; i <= N; ++i) { ch[i].insert(i); bigch[i].insert(i); }
		tot = N;
		for (int rep = 1; rep <= M; ++rep) {
			int i = ord[rep].second;
			int x = find(a[i]), y = find(b[i]);
			// cerr << "HERE " << a[i] << ' ' << b[i] << ' ' << c[i] << '\n';
			if (x == y) continue;
			if (siz[x] > siz[y]) swap(x, y);
			siz[y] += siz[x]; f[x] = y;
			for (int x1 : bigch[x]) {
				vector<int> success;
				for (int y1 : bigch[y]) {
					bool fl = false;
					for (int xx : ch[x1]) {
						for (int yy : ch[y1])
							if (!adj[xx].count(yy)) { fl = true; break; }
						if (fl) break;
					}
					// if (fl) cerr << "SUCCESS " << x1 << " <-> " << y1 << '\n';
					// else cerr << "FAIL " << x1 << "(" << ch[x1].size() << ") <-> " << y1 << "(" << ch[y1].size() << ")" << '\n';
					if (fl) success.push_back(y1);
				}
				auto merge = [&](int u, int v) {
					// cerr << "ADD EDGE " << u << ' ' << v << " ->" << tot + 1 << ", " << c[i] << '\n';
					int ret = ++tot;
					prt[u][0] = prt[v][0] = ret;
					wt[ret] = c[i];
					if (ch[u].size() < ch[v].size()) swap(u, v);
					swap(ch[u], ch[ret]);
					for (int xx : ch[v]) ch[ret].insert(xx);
					ch[v].clear();
					return ret;
				};
				int tmp = x1;
				for (int y1 : success) {
					bigch[y].erase(y1);
					tmp = merge(tmp, y1);
				}
				bigch[y].insert(tmp);
			}
			bigch[x].clear();
		}

		dep[tot] = 0;
		for (int i = tot - 1; i; --i) {
			dep[i] = dep[prt[i][0]] + 1;
			for (int j = 1; j != L; ++j) prt[i][j] = prt[prt[i][j - 1]][j - 1];
		}
		for (int i = 1; i <= M; ++i)
			cout << wt[LCA(a[i], b[i])] << " \n"[i == M];
		for (int i = 1; i <= N; ++i) {
			adj[i].clear();
			bigch[i].clear();
		}
		ch[tot].clear();
	}

	return 0;
}