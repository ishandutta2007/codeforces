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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Inf = 3e18;

int get(int i, int j) {
	if (j < i) return j;
	else return j + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n; ll t;
	cin >> n >> t;
	vector <ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector <int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		--x[i];
	}
	vector <ll> kek(n, Inf);
	for (int i = 0; i < n; ++i) {
		if (x[i] != n - 1) kek[x[i]] = a[get(i, x[i])] + t - 1;
	}
	ll cur = Inf;
	vector <ll> ans(n);
	for (int i = n - 1; i >= 0; --i) {
		--cur;
		cur = min(cur, kek[i]);
		if (cur < 1) {
			cout << "No\n";
			return 0;
		}
		ans[i] = cur;
	}
	for (int i = 0; i < n; ++i) {
		if (i && !(ans[i - 1] >= a[i - 1] + t)) {
			cout << "No\n";
			return 0;
		}
		if (!(ans[x[i]] >= a[i] + t)) {
			cout << "No\n";
			return 0;
		}
		if (x[i] > i) {
			if (!(ans[x[i] - 1] >= a[x[i]] + t)) {
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}