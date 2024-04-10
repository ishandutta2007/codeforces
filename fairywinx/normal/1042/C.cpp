// #define GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
// #include <cmath>
#include <bitset>

#include <algorithm>
// #define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3")

using namespace std;

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

// 11:00

signed main() {
	setup();
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	vector<pair<int, int>> otr;
	vector<int> z;
	for(int i = 0; i < n; ++i) {
		if (a[i] < 0)
			otr.push_back({a[i], i});
		if (a[i] == 0)
			z.push_back(i);
	}
	sort(otr.rbegin(), otr.rend());
	set<int> used;
	for(int i = 0; i < n; ++i) 
		used.insert(i);
	if (otr.size() % 2 == 1 && z.size() == 0) {
		cout << 2 << ' ' << otr[0].second + 1 << '\n';
		used.erase(otr[0].second);
	}
	else if (otr.size() % 2 == 1 && z.size() != 0) {
		for(int i = 0; i < z.size() - 1; ++i)
			cout << 1 << ' ' << z[i] + 1 << ' ' << z[i + 1] + 1 << '\n';
		for(auto i: z)
			used.erase(i);
		used.erase(otr[0].second);
		cout << 1 << ' ' << z.back() + 1 << ' ' << otr[0].second + 1 << '\n';
		if (z.size() + 1 != n)
			cout << 2 << ' ' << otr[0].second + 1 << '\n';
	}
	else if (z.size() != 0) {
		// cout << "MEOW"
		for(int i = 0; i < z.size() - 1; ++i)
			cout << 1 << ' ' << z[i] + 1 << ' ' << z[i + 1] + 1 << '\n';
		if(z.size() != n)
			cout << 2 << ' ' << z.back() + 1 << '\n';
		for(auto i: z)
			used.erase(i);
	}
	while(used.size() > 1) {
		cout << 1 << ' ' << *used.begin() + 1 << ' ';
		used.erase(*used.begin());
		cout << *used.begin() + 1 << '\n';
		// used.erase(*used.begin());
	}

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}