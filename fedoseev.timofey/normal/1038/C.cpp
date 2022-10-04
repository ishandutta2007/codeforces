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

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll A = 0, B = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (!(i % 2)) {
			if (a.empty()) b.pop_back();
			else if (b.empty()) {
				A += a.back();
				a.pop_back();
			}
			else {
				if (a.back() > b.back()) {
					A += a.back();
					a.pop_back();
				}
				else {
					b.pop_back();
				}
			}
		}
		else {
			if (b.empty()) a.pop_back();
			else if (a.empty()) {
				B += b.back();
				b.pop_back();
			}
			else {
				if (b.back() > a.back()) {
					B += b.back();
					b.pop_back();
				}
				else {
					a.pop_back();
				}
			}
		}
	}
	cout << A - B << '\n';
}