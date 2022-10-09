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

const int N = 3e5 + 228;

int prefs[2][N];
int prefu[2][N];
int prefd[2][N];

signed main() {
	setup();
	
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	prefs[0][0] = 0;
	for(int i = 0; i < n; ++i) 
		prefs[0][i + 1] = prefs[0][i] + a[i];
	prefs[1][0] = 0;
	for(int i = 0; i < n; ++i) 
		prefs[1][i + 1] = prefs[1][i] + b[i];

	prefu[0][0] = 0;
	for(int i = 0; i < n; ++i) 
		prefu[0][i + 1] = prefu[0][i] + a[i] * i;
	prefu[1][0] = 0;
	for(int i = 0; i < n; ++i) 
		prefu[1][i + 1] = prefu[1][i] + b[i] * i;

	prefd[0][n] = 0;
	for(int i = n - 1; i >= 0; --i) 
		prefd[0][i] = prefd[0][i + 1] + a[i] * (n - i - 1);
	prefd[1][n] = 0;
	for(int i = n - 1; i >= 0; --i) 
		prefd[1][i] = prefd[1][i + 1] + b[i] * (n - i - 1);

	int ans = prefu[0][n] + prefd[1][0] + prefs[1][n] * n;
	// cout << ans << '\n';
	int l_ans = 0;
	int t = 0;
	pair<int, int> now = {0, 1};
	while(now.first < n) {
		if (now.second == 0) {
			// cout << prefd[1][now.first + 1] + (prefs[1][n] - prefs[1][now.first + 1]) * (t + n - now.first + 1) << '\n';
			int c = prefu[0][n] - prefu[0][now.first] - (prefs[0][n] - prefs[0][now.first]) * (now.first - t - 1);
			c += prefd[1][now.first + 1] + (prefs[1][n] - prefs[1][now.first + 1]) * (t + n - now.first + 1);
			ans = max(ans, l_ans + c + b[now.first] * t);
			// ans = l_ans + c + b[now.first] * t;
		}
		else {
			int c = prefu[1][n] - prefu[1][now.first] - (prefs[1][n] - prefs[1][now.first]) * (now.first - t - 1);
			c += prefd[0][now.first + 1] + (prefs[0][n] - prefs[0][now.first + 1]) * (t + n - now.first + 1);
			ans = max(ans, l_ans + c + a[now.first] * t);
			// ans = l_ans + c + a[now.first] * t;
		}
		// cout << ans << ' ' << now.first << ' ' << now.second << ' ' << l_ans << '\n';
		if (now.second == 1)
			l_ans += a[now.first] * t + b[now.first] * (t + 1);
		else
			l_ans += b[now.first] * t + a[now.first] * (t + 1);
		++now.first;
		now.second ^= 1;
		t += 2;
	}
	cout << ans;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}