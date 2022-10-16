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
3 3 1
1
7 3 3
1 5 7
10 5 3
4 5 6
13 7 7
1 3 5 7 9 11 12
10 5 2
3 8
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n, k, m;
		cin >> n >> k >> m;
		set<int> a, b;
        b.insert(1000000000);

		for (int i = 0; i < n; ++i) {
			a.insert(i + 1);
		}

		for (int i = 0; i < m; ++i) {
			int x;
			cin >> x;
			a.erase(x);
			b.insert(x);
		}

		if ((n - m) % (k - 1) != 0) {
			cout << "NO\n";
			continue;
		}
		else if (n == m) {
			cout << "YES\n";
			continue;
		}

		int kk = k / 2;
        vector<int> va(a.begin(), a.end());
        cout << (*b.lower_bound(va[kk - 1]) < va[(int)va.size() - kk]?"YES\n":"NO\n");
	}

}