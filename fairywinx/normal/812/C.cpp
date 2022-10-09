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
#define int long long

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

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

int check(int n, vector<int> &a, int k, int s) {
	vector<int> c(n);
	int pr = 0;
	for(int i = 0; i < n; ++i) 
		c[i] = (i + 1) * k + a[i];
	sort(c.begin(), c.end());
	for(int i = 0; i < k; ++i) 
		pr += c[i];
	if (pr > s)
		return -1;
	return pr;
}

signed main() {
	setup();
	
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	int l = 0, r = n + 1;
	while(r - l > 1) {
		int m = (l + r) / 2;
		if (check(n, a, m, s) != -1) 
			l = m;
		else
			r = m;
	}
	cout << l << ' ' << check(n, a, l, s);

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}