#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int P = 1000000007;

int norm(int x) { return x >= P ? x - P : x; }
void add(int& x, int y) { if ((x += y) >= P) x -= P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

const int _ = 300010;

vector<int> G[_];
int val[_], prt[_];
bool vis[_];

void dfs(int u) { for (int v : G[u]) if (v != prt[u]) { prt[v] = u; dfs(v); val[u] ^= val[v] + 1; } }

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	for (int rep = 1; rep != N; ++rep) {
		int u, v; cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	dfs(1);
	int xsum = val[1]; vis[1] = true;
	cout << (xsum ? '1' : '2');
	for (int i = 2; i <= N; ++i) {
		int x = i;
		while (!vis[x]) {
			vis[x] = true;
			xsum ^= val[x] ^ (val[x] + 1) ^ 1;
			x = prt[x];
		}
		cout << (xsum ? '1' : '2');
	}

	return 0;
}