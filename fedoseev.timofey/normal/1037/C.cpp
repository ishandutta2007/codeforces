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
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 0; i + 1 < n; ++i) {
		if (a[i] != b[i] && a[i + 1] != b[i + 1] && a[i + 1] == b[i] && a[i] == b[i + 1]) {
			++ans;
			swap(a[i], a[i + 1]);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) ++ans;
	}
	cout << ans << '\n';
}