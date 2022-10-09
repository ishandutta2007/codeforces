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


int a[4][4];

signed main() {
	setup();
	
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) 
			cin >> a[i][j];
	}

	bool ans = true;
	for(int i = 0; i < 4; ++i) {
		int k = 1;
		for(int j = 0; j < 3; ++j) {
			if (a[i][j] && a[i][3])
				ans = false;
		}
		while((i + k) % 4 != i) {
			if (a[i][3] && a[(i + k) % 4][k - 1])
				ans = false;
			++k;
		}
	}
	if (!ans)
		cout << "YES";
	else
		cout << "NO";

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}