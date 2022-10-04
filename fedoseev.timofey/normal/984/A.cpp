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
#include <cassert>

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
	multiset <int> x;
	for (int i = 0; i < n; ++i) {
		int z;
		cin >> z;
		x.insert(z);
	}
	for (int i = 0; i < n - 1; ++i) {
		if (i % 2 == 0) {
			x.erase(--x.end());
		}
		else {
			x.erase(x.begin());
		}
	}
	cout << *x.begin() << '\n';
}