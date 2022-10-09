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
#include <cmath>
#include <bitset>

// #include <algorithm>
// #define int long long

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

const int N = 1.82 * 1e8 + 2;
bitset<N> pr;

bool its_prime(int a) {
	for(int i = 2; i * i <= a; ++i) {
		if (a % i == 0)
			return false;
	}
	return true;
}

int kr(int l, int r, int k) {
	r -= r % k;
	if (l % k != 0) 
		l += k - l % k;
	// cout << (r - l) / k + 1;
	return (r - l) / k + 1;
}

signed main() {
	setup();	
	// for(int i = 0; i <= N; ++i)
	// 	pr[i] = true;
	
	int l, r, k;
	cin >> l >> r >> k;
	if (!its_prime(k)) {
		cout << 0 << ' ';
		return 0;
	}
	r -= r % k;
	if (l % k != 0) 
		l += k - l % k;
	// cout << l << ' ' << r << '\n';
	assert(r % k == 0 && l % k == 0);
	r /= k;
	l /= k;
	
	if (k == 2) {
		cout << r - l + 1;
		return 0;
	}
	if (k == 3) {
		cout << (r - l + 1) - kr(l, r, 2);
		return 0;
	}
	if (k == 5) {
		cout << (r - l + 1) - kr(l, r, 2) - kr(l, r, 3) + kr(l, r, 6);
		return 0;
	}
	if (k == 7) {
		cout << (r - l + 1) - kr(l, r, 2) - kr(l, r, 3) - kr(l, r, 5) + kr(l, r, 6) + kr(l, r, 10) + kr(l, r, 15) - kr(l, r, 30);
		return 0;
	}
	
	int ans = (r - l + 1);
	
	for(int i = 2; i <= min(r, k - 1); ++i) {
		if (!pr[i]) {
			// cout << i << ' ';
			if (i >= l && r >= i) {
				// cout << i << ' ';
				--ans;
			}
			if ((long long) i * i > N)
				continue;
			for(int j = i * i; j <= N; j += i) {
				if (!pr[j]) {
					if (j >= l && j <= r)
						--ans;
					pr[j] = true;
				}
			}
		} 
	}
	cout << ans << '\n';

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}