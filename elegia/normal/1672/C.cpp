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
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> a(N);
		int l = N + 1, r = -1;
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i < N; ++i)
			if (a[i] == a[i - 1]) {
				l = min(l, i);
				r = max(r, i);
			}
		if (l >= r) cout << "0\n";
		else cout << max(1, (r - l) - 1) << '\n';
	}

	return 0;
}