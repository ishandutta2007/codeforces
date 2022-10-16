#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

const long long infty = 1000000000000000ll;

/*input
7 4
*/
/*input
2 8
*/
/*input
34 69
*/
/*input
8935891487501725 71487131900013807
*/
long long op(long long a, int b) {
	vector<int> t;
	t.push_back(b);

	while (a > 0) {
		t.push_back(a % 2);
		a /= 2;
	}

	if (t.size() > 62) {
		return 0;
	}

	for (auto &&i : t) {
		a = 2 * a + i;
	}

	return a;
}
long long n, m;
set<long long> c;
bool search(long long t) {
	if (t <= 0) {
		return false;
	}

	if (t == m) {
		return true;
	}

	if (c.count(t)) {
		return false;
	}

	c.insert(t);
	return search(op(t, 0)) or search(op(t, 1));
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cout << (search(n) ? "YES" : "NO");
}