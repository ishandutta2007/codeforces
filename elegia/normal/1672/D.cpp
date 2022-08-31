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
		vector<int> a(N), b(N);
		for (int i = 0; i != N; ++i) { cin >> a[i]; --a[i]; }
		for (int i = 0; i != N; ++i) { cin >> b[i]; --b[i]; }
		vector<int> shape, cnt;
		for (int i = N - 1; i >= 0; --i) {
			if (shape.empty() || shape.back() != b[i]) {
				shape.push_back(b[i]);
				cnt.push_back(1);
			} else {
				++cnt.back();
			}
		}
		bool ans = true;
		int pos = 0;
		vector<int> tot(N);
		for (int i = N - 1; i >= 0; --i) {
			if (pos < shape.size() && shape[pos] == a[i]) {
				tot[a[i]] += cnt[pos++];
			}
			if (--tot[a[i]] < 0) ans = false;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}