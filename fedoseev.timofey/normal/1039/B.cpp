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
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

bool query(ll l, ll r) {
	cout << l << ' ' << r << endl;
	string s;
	cin >> s;
	if (l == r && s == "Yes") exit(0);
	if (s == "Yes") return 1;
	else if (s == "No") return 0;
	else exit(0);
}

int k;
ll n;

pair <ll, ll> find(ll l, ll r) {
	while (r - l > 45) {
		ll m = (l + r) >> 1;
		if (query(l, m)) {
			r = m;
		}
		else {
			l = m + 1;
		}
		l -= k;
		r += k;
		l = max(l, 1ll);
		r = min(r, n);
	}
	return make_pair(l, r);
}

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 
	cin >> n >> k;
	ll cl = 1;
	ll cr = n;
	while (true) {
		auto p = find(cl, cr);
		cl = p.first;
		cr = p.second;
		int x = rnd() % (cr - cl + 1);
		query(cl + x, cl + x);
		cl -= k;
		cr += k;
		cl = max(cl, 1ll);
		cr = min(cr, n);
	}
}