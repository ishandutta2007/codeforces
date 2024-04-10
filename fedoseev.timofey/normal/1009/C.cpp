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
	int n, m;
	cin >> n >> m;
	ll cur = 0;
	ll s0 = 0, sm = 0;
	for (int i = 0; i < m; ++i) {
		int x, d;
		cin >> x >> d;
		cur += (ll)n * x;
		if (d >= 0) s0 += d;
		else sm += d;
	}
	ll d0 = 0, dm = 0;
	int mid = n / 2;
	for (int i = 0; i < n; ++i) {
		d0 += i;
		dm += abs(i - mid);
	}
	cur += (ll)d0 * s0;
	cur += (ll)dm * sm;
	cout << (ld)cur / n << '\n';
}