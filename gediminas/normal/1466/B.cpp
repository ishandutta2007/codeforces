#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(...) {\
    std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #__VA_ARGS__ << " "  << __VA_ARGS__ << std::endl;\
    }
#else
#define debug(...)
#endif
/*input
5
6
1 2 2 2 5 6
2
4 4
6
1 1 3 4 4 5
1
1
6
1 1 1 2 2 2

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		map<long long, int> b;
		set<long long> skir;
		set<long long> pas;

		for (int i = 0; i < n; ++i) {
			long long x;
			cin >> x;
			skir.insert(x);
			b[x]++;
		}

		for (auto &&[i, k] : b) {
			if (k == 1) {
				if (pas.count(i)) {
					skir.insert(i + 1);
					pas.insert(i + 1);
				}

				continue;
			}
			else {
				skir.insert(i + 1);
				pas.insert(i + 1);
			}
		}

		cout << skir.size() << "\n";
	}

}