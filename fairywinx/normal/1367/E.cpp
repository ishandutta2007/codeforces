#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <assert.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
 
#define int long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();
// #pragma GCC optimize("Ofast")
// #pragma optimize("O3")
 
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
 
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
 
void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> cnt(26);
	for(int i = 0; i < n; ++i)
		cnt[s[i] - 'a']++;
	for(int i = n; i >= 1; --i) {
		int c = gcd(i, k);
		vector<int> a;
		for(int j = 0; j < c; ++j) {
			a.push_back((i - j - 1) / c + 1);
		}
		sort(rall(a));
		multiset<int> q;
		for(auto j: cnt)
			q.insert(j);
		bool can = false;
		for(auto j: a) {
			if (q.lower_bound(j) != q.end()) {
				int c = *q.lower_bound(j);
				q.erase(q.lower_bound(j));
				q.insert(c - j);		
			}
			else {
				can = true;
				break;
			}
		}
		if (!can) {
			cout << i << '\n';
			break;
		}
	}
}
 
signed main() {
	setup();
	SOLVE;
	// solve();
 
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}