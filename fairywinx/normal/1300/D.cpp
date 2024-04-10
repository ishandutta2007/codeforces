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

int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

signed main() {
	setup();
	// SOLVE;
	int n;
	cin >> n;
	set<pair<int, int>> z;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i].first >> a[i].second;
	for(int i = 0; i < n; ++i) {
		pair<int, int> s, f;
		s = a[i];
		f = a[(i + 1) % n];
		pair<int, int> u = {s.first - f.first, s.second - f.second};
		z.insert(u);
	}
	bool ans = true;
	for(int i = 0; i < n; ++i) {
		pair<int, int> s, f;
		s = a[i];
		f = a[(i + 1) % n];
		pair<int, int> u = {s.first - f.first, s.second - f.second};
		if (!z.count({-u.first, -u.second})) {
			// ct(u);
			ans = false;
		}
	}
	if (ans)
		cout << "YES";
	else
		cout << "NO";


	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif	
}