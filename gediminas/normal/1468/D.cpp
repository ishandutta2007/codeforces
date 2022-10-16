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
4
7 2 3 6
1 4
7 2 3 6
5 1
7 2 3 6
4 4
7 5 3 6
1 1 1 1 1

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		long long n, m, a, b;
		cin >> n >> m >> a >> b;
		vector<int> x(m);

		for (auto &&i : x) {
			cin >> i;
		}

		sort(x.begin(), x.end());

		long long met, beg;

		if (a < b) {
			met = b - a - 1;
			beg = a;
		}
		else {
			met = a - b - 1;
			beg = n - a + 1;
		}

		int ans = 0;
		int t = 0;

		for (int i = m - 1; i >= 0 and t < met; --i) {
			if (t + x[i] < beg + met) {
				t++;
				ans++;
			}
		}

		cout << ans << "\n";
	}

}