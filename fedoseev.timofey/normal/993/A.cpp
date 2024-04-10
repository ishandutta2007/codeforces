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

const int Inf = 1e9;

bool check(pair <int, int> &a, vector <pair <int, int>> &b) {
	int mnx = Inf, mxx = -Inf, mny = Inf, mxy = -Inf;
	for (int i = 0; i < 4; ++i) {
		mxx = max(mxx, b[i].first);
		mnx = min(mnx, b[i].first);
		mxy = max(mxy, b[i].second);
		mny = min(mny, b[i].second);
	}
	return mnx <= a.first && a.first <= mxx && mny <= a.second && a.second <= mxy;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	vector <pair <int, int>> a(4), b(4);
	for (int i = 0; i < 4; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < 4; ++i) {
		cin >> b[i].first >> b[i].second;
		int x = b[i].first + b[i].second;
		int y = b[i].first - b[i].second;
		b[i].first = x;
		b[i].second = y;
	}
	for (int i = -100; i <= 100; ++i) {
		for (int j = -100; j <= 100; ++j) {
			pair <int, int> cur = {i, j};
			pair <int, int> ncur = {i + j, i - j};
			if (check(cur, a) && check(ncur, b)) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}