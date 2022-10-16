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
8
4
1 2 4 5
3
1 3 5
3
2 6 8
2
1 2
1
50
5
3 4 5 6 8
3
1 25 26
6
1 2 4 8 16 32

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		set<long long> b;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		for (auto &&i : a) {
			for (auto &&j : a) {
				if (i == j) {
					continue;
				}

				b.insert(abs(i - j));
			}
		}

		b.erase(0);
		cout << b.size() << "\n";
	}

}