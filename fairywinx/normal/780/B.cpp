#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

// #define _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif

	srand(time(0));
}

pair<double, double> merge(pair<double, double> a, pair<double, double> b) {
	return {max(a.first, b.first), min(a.second, b.second)};
}

bool check(double m, int n, vector<int> &x, vector<int> &v) {
	pair<double, double> now = {-2e9, 2e9};
	for(int i = 0; i < n; ++i) {
		pair<double, double> cur = {(double) x[i] - v[i] * m, (double) x[i] + v[i] * m};
		now = merge(now, cur);
	}
	if (now.second >= now.first)
		return true;
	return false;
}

signed main() {
	setup();

	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> x[i];
	for(int i = 0; i < n; ++i) 
		cin >> v[i];
	double l = 0, r = 2e9;
	for(int k = 0; k < 60; ++k) {
		double m = (l + r) / 2;
		if (check(m, n, x, v))
			r = m;
		else 
			l = m;
	}
	cout << setprecision(15) << r << '\n';
	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}