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

const int _ = 1000005;

int sum[_];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, C; cin >> N >> C;
		fill(sum + 1, sum + C + 1, 0);
		while (N--) { int x; cin >> x; sum[x] = 1; }
		for (int i = 1; i <= C; ++i) sum[i] += sum[i - 1];
		bool fl = true;
		if (!sum[1]) fl = false;
		for (int i = 1; i <= C; ++i)
			if (sum[i] - sum[i - 1])
				for (int j = 1; j <= C / i; ++j)
					if (!(sum[j] - sum[j - 1]) && sum[min((j + 1) * i - 1, C)] - sum[j * i - 1]) {
						// cerr << "BAD " << i << ' ' << j << ": " << sum[min((j + 1) * i - 1, C)] - sum[j * i - 1] << '\n';
						fl = false;
					}
		cout << (fl ? "Yes\n" : "No\n");
	}

	return 0;
}