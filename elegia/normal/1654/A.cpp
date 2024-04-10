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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> a(N);
		for (int i = 0; i != N; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		cout << a[N - 1] + a[N - 2] << '\n';
	}

	return 0;
}