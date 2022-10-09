#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <deque>
#include <algorithm>

#define SOLVE int t; cin >> t; while(t--) solve();
#define int long long

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
}

void ct(vector<int> &a) {
	for(auto i: a)
		cout << i << ' ';
	cout << '\n';
}

void ct(pair<int, int> a) {
	cout << a.first << ':' << a.second << ' ';
}

void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		ct(a);
	cout << '\n';
}

void ct(vector<vector<int>> a) {
	for(auto i: a)
		ct(i);
}

const int N = 50;

signed main() {
	setup();
	// SOLVE;
	vector<int> a(N + 5);
	int n;
	cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; ++i) 
		cin >> b[i];
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < n; ++j) {
			if (b[j] & (1 << i)) 
				a[i]++;
		}
	}
	int ans = -1;
	int z = 0;
	for(int i = 0; i < N; ++i) {
		if (a[i] == 1) {
			z = (1 << i);
		}
	}
	vector<int> u(n);
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < n; ++j) {
			if (a[i] == 1)
				u[j] |= b[j] & (1 << i); 
		}
	}
	int mx = 0;
	for(int i = 0; i < n; ++i) {
		if (u[i] > u[mx])
			mx = i;
	}
	if (z != 0) {
		// cout << z << '\n';
		ans = mx;
		if (u[ans] < u[mx])
			return 1;
		if (ans == -1)
			return 1;
		cout << b[ans] << ' ';
		for(int i = 0; i < ans; ++i)
			cout << b[i] << ' ';
		for(int i = ans + 1; i < n; ++i) 
			cout << b[i] << ' ';
		return 0;
	}
	ct(b);


	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif	
}