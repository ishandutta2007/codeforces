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
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int mv = *min_element(v.begin(), v.end());
	vector<int> k(3);
	for (int i = 0; i < n; i++) {
		k[v[i] - mv]++;
	}
	
	int var1 = min(k[0], k[2]);
	int var2 = (k[2] == 0) ? -infinity : (k[1] / 2);
	int ans = n;
	
	if (var1 > var2) {
		while (k[0] != 0 && k[2] != 0) {
			ans -= 2;
			k[0]--; k[2]--;
			k[1] += 2;
		}
	} else {
		while (k[1] >= 2) {
			ans -= 2;
			k[1] -= 2;
			k[0]++; k[2]++;
		}
	}
	
	cout << ans << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < k[i]; j++) {
			cout << i + mv << " ";
		}
	}
	cout << endl;
	
	return 0;
}