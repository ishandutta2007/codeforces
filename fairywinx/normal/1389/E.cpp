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
#include <random>
// #include <cmath>
#include <bitset>

#include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3")

using namespace std;

void solve() {
	int m, d, w;
	cin >> m >> d >> w;
	int k = w / gcd(d - 1, w);
	int c = min(d, m);
	int u = (c + k - 1) / k;
	cout << (u - 1) * (c) - k * u * (u - 1) / 2 << '\n';
}

signed main() {
	SOLVE;
}