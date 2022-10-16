#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

typedef long long ll;

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n; cin >> n; vector<int> a(n); for (int &x: a) cin >> x;
	int g = 0;
	for (int x: a) g = __gcd(g, x);
	int moves = *max_element(all(a)) / g - n;
	cout << (moves & 1 ? "Alice" : "Bob") << "\n";
	return 0;	
}