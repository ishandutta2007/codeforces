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


int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;

	auto query = [&](int w) {
		if (w < 1) return 0;
		cout << "? " << w << endl;
		int ret; cin >> ret; return ret;
	};

	int low = 1, high = 1e7;
	while (low < high) {
		int mid = (low + high) / 2;
		int h = query(mid);
		if (h == 0 || h > 1) low = mid + 1;
		else high = mid;
	}
	int L = low - (N - 1);
	int ans = low;
	for (int k = 2; k <= N; ++k) {
		int w = (L + N - 1) / k;
		int h = query(w);
		if (h > 0) ans = min(ans, w * h);
	}
	cout << "! " << ans << '\n';

	return 0;
}