/*
   
   
   
   
 */
#include <cmath>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <complex>
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

using namespace std;

using ull = unsigned long long;

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

// std::pair<int, int> approx(int p, int q, int A) {
// 	int x = q, y = p, a = 1, b = 0;
// 	while (x > A) {
// 		std::swap(x, y); std::swap(a, b);
// 		a -= x / y * b;
// 		x %= y;
// 	}
// 	return std::make_pair(x, a);
// }

// void outfrac(int x) {
// 	auto res = approx(P, x, sqrt(P));
// 	if (res.second < 0) { res.second *= -1; res.first *= -1; }
// 	if (res.second != 1) std::cout << res.first << '/' << res.second;
// 	else std::cout << res.first;
// }

const int _ = 100005;

int a[_], p[_];
bool vis[_];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 1; i <= N; ++i) cin >> a[i];
		for (int i = 1; i <= N; ++i) cin >> p[a[i]];

		fill(vis + 1, vis + N + 1, 0);
		int e = 0;
		for (int i = 1; i <= N; ++i) {
			if (vis[i]) continue;
			int len = 0, x = i;
			do {
				++len; vis[x] = true; x = p[x];
			} while (!vis[x]);
			e += len / 2 * 2;
		}
		ull ans = 0;
		for (int i = 1; i != N; ++i) {
			int val = min({i * 2, (N - i) * 2, e});
			ans += val;
		}
		cout << ans << '\n';
	}

	return 0;
}