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

signed main() {
	#ifdef DEBUG
	//	stdin = freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n);
	vector<int> d(n);
	vector<int> kd(n);
	d[0] = 0; kd[0] = 1;
	for (int i = 1; i < n; i++) {
		cin >> v[i]; v[i]--;
		d[i] = d[v[i]] + 1;
		kd[d[i]] ^= 1; 
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += kd[i];
	}
	cout << ans << endl;
	return 0;
}