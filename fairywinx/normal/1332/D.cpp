#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <iomanip>
#include <string>
#include <ctime>

// #include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

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

const int N = 1e3;

int dp[N][N];
int a[N][N];

signed main() {
	setup();

	int k;
	cin >> k;
	int a = 0;
	int b = 0;
	int m = 0;
	for(int i = 0; i < 30; ++i) {
		if (k & (1 << i)) {
			m |= (1 << i);
			a |= (1 << i);
		}
		else {
			if (b + (1 << i) > 3e5)
				continue;
			b |= (1 << i);
		}
	}
	// cout << a << ' ' << b << ' ' << m << '\n';
	cout << 3 << ' ' <<3 << '\n';
	int ans[3][3];
	ans[0][0] = m + b;
	ans[0][1] = m;
	ans[0][2] = 0;
	ans[1][0] = b;
	ans[1][1] = m;
	ans[1][2] = 0;
	ans[2][0] = b;
	ans[2][1] = b + m;
	ans[2][2] = a;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}


	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}