// #define _GLIBCXX_DEBUG
 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <map>
#include <assert.h>
#include <math.h>
#include <iomanip>
#include <string>
 
// #include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve()
 
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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
		ct(i);
}

void solve() {
	int n;
	cin >> n;
	set<int> a;
	for(int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		a.insert(b);
	}
	cout << a.size() << '\n';
}

const int N = 2e5;

vector<pair<int, int>> G[N];

signed main() {
	setup();
	// SOLVE;
	
	int n;
	cin >> n;	
	vector<pair<int, int>> a(n - 1);
	for(int i = 0; i < n - 1; ++i) {
		cin >> a[i].first >> a[i].second;
		--a[i].first, --a[i].second;
		G[a[i].first].push_back({a[i].second, i});
		G[a[i].second].push_back({a[i].first, i});
	}
	vector<int> ans(n - 1, -1);
	int res = 0;
	for(int i = 0; i < n; ++i) {
		if (G[i].size() == 1 && ans[G[i][0].second] == -1) 
			ans[G[i][0].second] = res++;
	}
	for(int i = 0; i < n - 1; ++i) {
		if (ans[i] == -1) {
			ans[i] = res++;
		}
	}
	for(auto i: ans)
		cout << i << '\n';

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}