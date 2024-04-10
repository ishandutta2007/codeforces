#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

ll get(ll x, ll y) {
	return x * x + y * y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	reverse(a.begin(), a.end());
	vector <int> sign(n, 1);
	ll x = 0, y = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (get(x + a[i].first, y + a[i].second) < get(x - a[i].first, y - a[i].second)) {
			x += a[i].first;
			y += a[i].second;
		}
		else {
			x -= a[i].first;
			y -= a[i].second;
			sign[i] = -1;
		}
	}
	reverse(sign.begin(), sign.end());
	for (auto e : sign) {
		cout << e << ' ';
	}
}