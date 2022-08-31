/*
 , .
 */
#include <cmath>
#include <cstring>

#include <algorithm>
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

vector<pair<int, int>> pos[100005];

int x[100005], y[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M; cin >> N >> M;
	for (int i = 0; i != N; ++i)	
		for (int j = 0; j != M; ++j) {
			int c; cin >> c;
			pos[c].emplace_back(i, j);
		}
	ull ans = 0;
	for (int i = 1; i <= 100000; ++i)
		if (!pos[i].empty()) {
			int m = pos[i].size();
			for (int j = 0; j != m; ++j) {
				x[j] = pos[i][j].first;
				y[j] = pos[i][j].second;
			}
			sort(x, x + m); sort(y, y + m);
			for (int j = 1; j != m; ++j)
				ans += (x[j] - x[j - 1]) * (ull)j * (m - j);
			for (int j = 1; j != m; ++j)
				ans += (y[j] - y[j - 1]) * (ull)j * (m - j);
		}
	cout << ans << '\n';

	return 0;
}