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

signed main() {
	setup();
	// SOLVE;
	
	int u, v;
	cin >> u >> v;
	if (u == 0 && v == 0) {
		cout << 0;
		return 0; 
	}

	if (u == v) {
		cout << 1 << '\n' << u;
		return 0;
	}

	if (v < u) {
		cout << -1;
		return 0;
	}

	if ((v - u) % 2 == 1) {
		cout << -1;
		return 0;
	}

	bool P = true;
	v -= u;
	for(int i = 61; i > 0; --i) {
		if ((((long long) 1 << i) & v) && ((((long long) 1 << (i - 1)) & u)))
			P = false;
	}

	if (P == true) {
		int x = 0;
		for(int i = 61; i > 0; --i) {
			if (((long long) 1 << i) & v) {
				x += ((long long) 1 << (i - 1));
			}
		}
		cout << 2 << '\n' <<  x << ' ' << x + u << '\n';
		return 0;
	}
	v += u;

	cout << 3 << '\n' << u << ' ' << (v - u) / 2 << ' ' << (v - u) / 2;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}