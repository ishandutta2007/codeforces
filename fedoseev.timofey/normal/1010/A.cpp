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
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 1) {
			cout << "-1\n";
			return 0;
		}
	}
	vector <int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		if (b[i] == 1) {
			cout << "-1\n";
			return 0;
		}
	}
	ld cur = 0;
	for (int i = n - 1; i >= 0; --i) {
		int j = (i + 1) % n;
		cur += (cur + m) / (b[j] - 1);
		cur += (cur + m) / (a[i] - 1);
	}
	cout << cur << '\n';
}