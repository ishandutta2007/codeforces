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

const int _ = 1000005;

char s[_];
int ans[_], ans2[_ * 2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M >> s;
		int cnt = 0;
		for (int i = 0; i != N * M; ++i) s[i] -= '0';
		for (int i = 0; i != N * M; ++i) {
			cnt += s[i];
			if (i >= M) cnt -= s[i - M];
			ans[i] = cnt >= 1;
		}
		for (int i = M; i != N * M; ++i) ans[i] += ans[i - M];

		fill(ans2, ans2 + N * M, 0);
		for (int i = 0; i != M; ++i) {
			cnt = 0;
			for (int j = 0; j != N; ++j) {
				cnt += s[j * M + i];
				ans2[j * M + i] += cnt >= 1;
				ans2[j * M + i + M] -= cnt >= 1;
			}
		}
		for (int i = 1; i != N * M; ++i) ans2[i] += ans2[i - 1];

		for (int i = 0; i != N * M; ++i) cout << ans[i] + ans2[i] << " \n"[i == N * M - 1];
	}

	return 0;
}