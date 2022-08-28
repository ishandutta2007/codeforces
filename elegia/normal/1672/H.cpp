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

using ll = long long;
using ull = unsigned long long;

using namespace std;

const int _ = 200005;

char s[_];
int a[_], sum[_];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, Q; cin >> N >> Q >> (s + 1);
	int dep = 0;
	for (int i = 1; i <= N; ++i) {
		if (s[i] == '0') a[i] = ++dep;
		else a[i] = dep--;
		sum[i] = sum[i - 1] + (a[i] != a[i - 1]);
	}
	while (Q--) {
		int l, r; cin >> l >> r;
		int a0 = sum[r] - sum[l] + 1, a1 = 0;
		a1 = abs(a[r] - a[l]);
		cout << (a0 + a1 + 1) / 2 << '\n';
	}

	return 0;
}