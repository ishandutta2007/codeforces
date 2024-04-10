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

const int N = 4e5 + 7;

int p[N];

void mk(int a) {
	p[a] = a;
}

int res = 0;

int get(int a) {
	if (a == p[a]) return a;
	return p[a] = get(p[a]);
}

void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a != b) {
		--res;
		p[a] = b;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	for (int i = 0; i < N; ++i) mk(i);
	int n, m;
	cin >> n >> m;
	res = n + m;
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		y += n;
		merge(x, y);
	}
	cout << res - 1 << '\n';
}