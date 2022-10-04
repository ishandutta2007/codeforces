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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector <pair <ll, ll>> ev;
	for (int i = 0; i < n; ++i) {
		ll l, r;
		cin >> l >> r;
		ev.push_back({l, -1});
		ev.push_back({r + 1, 1});
	}
	sort(ev.begin(), ev.end());
	int balance = 0;
	vector <ll> count(n + 1);
	for (int i = 0; i + 1 < ev.size(); ++i) {
		balance -= ev[i].second;
		if (balance <= n) count[balance] += ev[i + 1].first - ev[i].first;
	}
	for (int i = 1; i <= n; ++i) {
		cout << count[i] << ' ';
	}
}