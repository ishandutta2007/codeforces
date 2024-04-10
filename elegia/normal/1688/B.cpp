#include <cmath>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int best = 100, ev = 0;
		for (int rep = 0; rep != N; ++rep) {
			int x, lb = 0; cin >> x;
			if (!(x & 1)) ++ev;
			while (!(x & 1)) {
				x >>= 1; ++lb;
			}
			best = min(best, lb);
		}
		if (ev == N) cout << best + N - 1 << '\n';
		else cout << ev << '\n';
	}
	
	return 0;
}