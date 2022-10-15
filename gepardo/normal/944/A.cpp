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
	int n, a, b; cin >> n >> a >> b;
	vector< basic_string<int> > sts(n);
	for (int i = 0; i < n; i++) {
		sts[i] += i+1;
	}
	int ans = 0;
	while (sts.size() != 1) {
		vector< basic_string<int> > nSts;
		for (int i = 0; i < (int)sts.size(); i += 2) {
			if (i == (int)sts.size() - 1) {
				nSts.push_back(sts[i]);
			} else {
				nSts.push_back(sts[i] + sts[i+1]);
			}
		}
		if (nSts.size() == 1) {
			break;
		}
		ans++;
		for (auto st: nSts) {
			bool fa = false, fb = false;
			for (int i: st) {
				if (i == a) {
					fa = true;
				} else if (i == b) {
					fb = true;
				}
			}
			if (fa && fb) {
				cout << ans << endl;
				return 0;
			}
		}
		sts = nSts;
	}
	
	cout << "Final!" << endl;
	return 0;
}