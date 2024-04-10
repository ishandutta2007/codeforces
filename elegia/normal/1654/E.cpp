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

const int _ = 100005, B = 330;

int N;
int a[_];
int po[_ * B * 2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> a[i];
	int ans = 1;
	int* cnt = po + _ * B;
	{
		for (int i = 1; i <= N; ++i) {
			for (int j = i + 1; j <= min(N, i + B); ++j) {
				if ((a[j] - a[i]) % (j - i) == 0)
					ans = max(ans, 1 + ++cnt[(a[j] - a[i]) / (j - i)]);
			}
			for (int j = i + 1; j <= min(N, i + B); ++j)
				cnt[(a[j] - a[i]) / (j - i)] = 0;
		}
	}
	{
		for (int i = 1 - B; i <= B - 1; ++i) {
			for (int j = 1; j <= N; ++j)
				ans = max(ans, ++cnt[a[j] + j * i]);
			for (int j = 1; j <= N; ++j)
				cnt[a[j] + j * i] = 0;
		}
	}

	cout << N - ans << '\n';

	return 0;
}