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

int count(int a, int b, int c, int d) {
	int res = 0;
	if (a == c) ++res;
	if (a == d) ++res;
	if (b == c) ++res;
	if (b == d) ++res;
	return res;
}

int who(int a, int b, int c, int d) {
	if (a == c) return a;
	if (a == d) return a;
	if (b == c) return b;
	if (b == d) return b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	vector <pair <int, int>> b(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i].first >> b[i].second;
	}
	set <int> res;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (count(a[i].first, a[i].second, b[j].first, b[j].second) == 1) {
				res.insert(who(a[i].first, a[i].second, b[j].first, b[j].second));
			}
		}
	}
	if (res.size() == 1) {
		cout << *res.begin() << '\n';
		return 0;
	}
	bool bad = false;
	for (int i = 0; i < n; ++i) {
		set <int> t;
		int x = a[i].first;
		int y = a[i].second;
		for (int j = 0; j < m; ++j) {
			if (count(x, y, b[j].first, b[j].second) == 1) {
				t.insert(who(x, y, b[j].first, b[j].second));
			}
		}
		if (t.size() > 1) {
			bad = true;
			break;
		}
	}
	for (int i = 0; i < m; ++i) {
		set <int> t;
		int x = b[i].first;
		int y = b[i].second;
		for (int j = 0; j < n; ++j) {
			if (count(x, y, a[j].first, a[j].second) == 1) {
				t.insert(who(x, y, a[j].first, a[j].second));
			}
		}
		if (t.size() > 1) {
			bad = true;
			break;
		}
	}
	if (!bad) {
		cout << "0\n";
		return 0;
	}
	cout << "-1\n";
	return 0;
}