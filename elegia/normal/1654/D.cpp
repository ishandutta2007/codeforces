/*
   
   
   
   
 */
#include <cmath>
#include <cstring>

#include <algorithm>
#include <limits>
#include <functional>
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

using namespace std;

const int _ = 200005;

int cnt[_], mx[_];
vector<int> pf[_];

vector<tuple<int, int, int>> G[_];

int ans;

void dfs(int u, int p = 0, int prd = 1) {
	add(ans, prd);
	// cerr << u << ": " << prd << '\n';
	for (auto [v, x, y] : G[u])
		if (v != p) {
			for (int pr : pf[y]) ++cnt[pr];
			for (int pr : pf[x]) mx[pr] = max(mx[pr], - (--cnt[pr]));
			dfs(v, u, prd * (ull)y % P * mpow(x, P - 2) % P);
			for (int pr : pf[y]) --cnt[pr];
			for (int pr : pf[x]) ++cnt[pr];
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 2; i <= 200000; ++i)
		if (pf[i].empty()) {
			for (int j = i; j <= 200000; j += i) {
				int tmp = j;
				while (tmp % i == 0) {
					pf[j].push_back(i); tmp /= i;
				}
			}
		}

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int rep = 1; rep != N; ++rep) {
			int u, v, x, y; cin >> u >> v >> x >> y;
			G[u].emplace_back(v, x, y);
			G[v].emplace_back(u, y, x);
		}
		ans = 0;
		dfs(1);
		for (int i = 1; i <= N; ++i) {
			ans = ans * (ull)mpow(i, mx[i]) % P;
			// cerr << i << "^" << mx[i] << '\n';
		}
		cout << ans << '\n';
		fill(mx + 1, mx + N + 1, 0);
		for (int i = 1; i <= N; ++i) G[i].clear();
	}

	return 0;
}