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
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

int pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return a * pow(a, b - 1);
	int z = pow(a, b / 2);
	return z * z;
}

signed main() {
	setup();
			
	int L, R;
	cin >> L >> R;
	int ans = 0;
	bool w = false;
	int l = 0, r = 0;
	for(int i = 62; i > 0; --i) {
		if ((r + (1ll << i)) <= R && l + (1ll << i) - 1 >= L) {
			w = true;
			r += (1ll << i);
			ans += (1ll << i);
		}
		else if (w) {
			ans += (1ll << i);
			l += (1ll << i);
		}
		else {
			if (l + (1ll << i) - 1 < L) {
				r += (1ll << i);
				l += (1ll << i);
			}
		}
	}
	// cout << l << ' ' << r << '\n';
	if (!w && l < L) {
		l += 1, r += 1;
	}
	else {
		if (w) {
			l++;
			ans += 1;
		}
		else if (r <= R) {
			++r;
			ans += 1;
		}
	}	
	// cout << l << ' ' << r << '\n';
	assert(l >= L && r <= R);
	cout << ans << ' ';



	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}