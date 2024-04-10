#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <random>
#include <chrono>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <iomanip>
#include <tuple>

using namespace std;

int main() {
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
    #else
		ios_base::sync_with_stdio(false);
    #endif // DEBUG
    int n; cin >> n;
    vector<int> x(n), v(n);
    for (int i = 0; i < n; i++) {
		cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
		cin >> v[i];
    }
    auto ok = [&](long double time) -> bool {
    	vector< pair<long double, int> > events;
    	for (int i = 0; i < n; i++) {
            events.push_back({x[i] - v[i] * time, -1});
            events.push_back({x[i] + v[i] * time, +1});
    	}
    	sort(events.begin(), events.end());
		int cnt = 0;
		for (auto it: events) {
			cnt -= it.second;
			if (cnt == n) {
				return true;
			}
		}
		return false;
    };
    long double l = 0, r = 1e10;
    for (int i = 0; i < 70; i++) {
		long double m = (l + r) / 2;
		if (ok(m)) {
			r = m;
		} else {
			l = m;
		}
    }
    cout << fixed << setprecision(10) << l << endl;
	return 0;
}