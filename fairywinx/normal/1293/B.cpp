#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <ctime>
#include <iomanip>

#define int long long
#define vi vector<int>
#define mp make_pair
#define pb emplace_back
#define SOLVE int t; cin >> t; for(int i = 0; i < t; ++i) solve();

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

void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		cout << i.first << ':' << i.second << ' ';
	cout << '\n';
}

signed main() {
	setup();
	//SOLVE;

	int n;
	cin >> n;
	long double ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += (long double) 1 / (n - i);
	}
	cout << setprecision(16) <<  ans;

	#ifdef LOCAL
	    cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
    #endif	
}