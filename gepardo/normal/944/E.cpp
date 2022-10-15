#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstdint>
#include <cstring>
#include <random>
#include <chrono>
#include <list>
#include <deque>
#include <tuple>
#include <numeric>

using namespace std;
using namespace chrono;

const int module = (int)1e9 + 7;
const int infinity = (int)1e9 + 42;
const int64_t llInf = (int64_t)1e18 + 256;

class Fenwick {
private:
	int n;
	vector<int> a;
public:
	inline void modify(int v, int delta) {
		for (; v < n; v |= v+1) {
			a[v] = max(a[v], delta);
		}
	}
	
	inline int sum(int v) {
		int res = 0;
		for (; v >= 0; v &= v+1, v--) {
			res = max(res, a[v]);
		}
		return res;
	}
	
	Fenwick(int n)
		: n(n), a(n) {
	}
};

inline vector<int> incs(vector<int> v) {
	int n = v.size();
	Fenwick f(142857);
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = f.sum(v[i]) + 1;
		f.modify(v[i], res[i]);
	}
	return res;
}

signed main() {
	#ifdef DEBUG
		stdin = freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<int> a(m+1);
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		a[l-1]++;
		a[r]--;
	}
	for (int i = 0; i < m; i++) {
		a[i+1] += a[i];
	}
	a.pop_back();
	
	auto q1 = incs(a);
	reverse(a.begin(), a.end());
	auto q2 = incs(a);
	reverse(a.begin(), a.end());
	reverse(q2.begin(), q2.end());
	
	int ans = 0;
	for (int i = 0; i < m; i++) {
		ans = max(ans, q1[i] + q2[i] - 1);
	}
	cout << ans << endl;
	
	return 0;
}